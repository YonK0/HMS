// dbmanager.cpp
#include "dbmanager.h"

DbManager::DbManager(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("hotel_reservation_system");
    m_db.setUserName("aero");
    m_db.setPassword("your_password");
    
    if (!m_db.open()) {
        qDebug() << "Database connection error:" << m_db.lastError();
    }
}

DbManager::~DbManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DbManager::isOpen() const {
    return m_db.isOpen();
}

QString DbManager::lastError() const {
    return m_db.lastError().text();
}

int DbManager::getOrCreateClient(const QString& fullName, const QString& country,
                                 const QString& email, const QString& phone) {
    // Split the full name into first and last name
    QString firstName, lastName;
    splitName(fullName, firstName, lastName);

    // First check if client already exists
    QSqlQuery query;
    query.prepare("SELECT id_client FROM clients WHERE first_name = :firstName AND last_name = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    // If not, create a new client
    query.prepare("INSERT INTO clients (first_name, last_name, country, email, phone) "
                  "VALUES (:firstName, :lastName, :country, :email, :phone)");

    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":country", country);
    query.bindValue(":email", email);
    query.bindValue(":phone", phone);

    if (!query.exec()) {
        qDebug() << "Create client error:" << query.lastError().text();
        return -1;
    }

    return query.lastInsertId().toInt();
}


bool DbManager::addReservation(const Reservation& reservation) {
    QSqlQuery query;

    // First, ensure the client exists or create a new one
    int clientId = getOrCreateClient(reservation.guestName(), reservation.country(), reservation.email(), reservation.phone());

    if (clientId <= 0) {
        qDebug() << "Failed to create or find client";
        return false;
    }

    // Find the room by room number
    int roomId = getRoomIdByNumber(reservation.roomNumber());
    if (roomId <= 0) {
        qDebug() << "Room not found:" << reservation.roomNumber();
        return false;
    }

    // Prepare the insert query for reservation
    query.prepare("INSERT INTO reservations (id_client, id_room, arrival_date, departure_date, status) "
                  "VALUES (:client, :room, :arrival, :departure, :status)");

    query.bindValue(":client", clientId);
    query.bindValue(":room", roomId);
    query.bindValue(":arrival", reservation.checkInDate());
    query.bindValue(":departure", reservation.checkOutDate());

    // Convert reservation status enum to string
    QString statusStr;
    switch (reservation.status()) {
    case Reservation::Pending: statusStr = "Pending"; break;
    case Reservation::Confirmed: statusStr = "Confirmed"; break;
    case Reservation::CheckedIn: statusStr = "CheckedIn"; break;
    case Reservation::Completed: statusStr = "Completed"; break;
    case Reservation::Cancelled: statusStr = "Cancelled"; break;
    default: statusStr = "Pending";
    }

    query.bindValue(":status", statusStr);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Add reservation error:" << query.lastError().text();
        return false;
    }

    return true;
}


QList<Reservation> DbManager::getAllReservations() {
    QList<Reservation> reservations;

    QSqlQuery query("SELECT r.id_reservation, c.first_name, c.last_name, c.country, "
                    "c.email, c.phone, rm.room_number, rt.type_name, "
                    "r.arrival_date, r.departure_date, r.status "
                    "FROM reservations r "
                    "JOIN clients c ON r.id_client = c.id_client "
                    "JOIN rooms rm ON r.id_room = rm.id_room "
                    "JOIN room_types rt ON rm.id_type = rt.id_type "
                    "ORDER BY r.arrival_date DESC");

    if (!query.exec()) {
        qDebug() << "Get reservations error:" << query.lastError().text();
        return reservations;
    }

    while (query.next()) {
        int id = query.value("id_reservation").toInt();
        QString firstName = query.value("first_name").toString();
        QString lastName = query.value("last_name").toString();
        QString guestName = firstName + " " + lastName;
        QString roomNumber = query.value("room_number").toString();
        QString roomType = query.value("type_name").toString();
        QString country = query.value("country").toString();
        QString email = query.value("email").toString();
        QString phone = query.value("phone").toString();
        QDate checkInDate = query.value("arrival_date").toDate();
        QDate checkOutDate = query.value("departure_date").toDate();

        // Convert status string to enum
        QString statusStr = query.value("status").toString();
        Reservation::Status status = Reservation::Pending;

        if (statusStr == "Confirmed") status = Reservation::Confirmed;
        else if (statusStr == "CheckedIn") status = Reservation::CheckedIn;
        else if (statusStr == "Completed") status = Reservation::Completed;
        else if (statusStr == "Cancelled") status = Reservation::Cancelled;

        Reservation reservation(id, guestName, roomNumber, roomType, country,
                                phone, email, checkInDate, checkOutDate, status);

        reservations.append(reservation);
    }

    return reservations;
}

bool DbManager::updateReservation(const Reservation& reservation) {
    QSqlQuery query;

    // First, get the client ID for this reservation
    int clientId = getClientIdByReservation(reservation.id());
    if (clientId <= 0) {
        qDebug() << "Client not found for reservation ID:" << reservation.id();
        return false;
    }

    // Update client information first
    QString firstName, lastName;
    splitName(reservation.guestName(), firstName, lastName);

    query.prepare("UPDATE clients SET first_name = :firstName, last_name = :lastName, "
                  "country = :country, email = :email, phone = :phone "
                  "WHERE id_client = :clientId");

    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":country", reservation.country());
    query.bindValue(":email", reservation.email());
    query.bindValue(":phone", reservation.phone());
    query.bindValue(":clientId", clientId);

    if (!query.exec()) {
        qDebug() << "Update client error:" << query.lastError().text();
        return false;
    }

    // Find the room by room number
    int roomId = getRoomIdByNumber(reservation.roomNumber());
    if (roomId <= 0) {
        qDebug() << "Room not found:" << reservation.roomNumber();
        return false;
    }

    // Convert reservation status enum to string
    QString statusStr;
    switch (reservation.status()) {
    case Reservation::Pending: statusStr = "Pending"; break;
    case Reservation::Confirmed: statusStr = "Confirmed"; break;
    case Reservation::CheckedIn: statusStr = "CheckedIn"; break;
    case Reservation::Completed: statusStr = "Completed"; break;
    case Reservation::Cancelled: statusStr = "Cancelled"; break;
    default: statusStr = "Pending";
    }

    // Update the reservation
    query.prepare("UPDATE reservations SET id_room = :roomId, arrival_date = :arrival, "
                  "departure_date = :departure, status = :status "
                  "WHERE id_reservation = :id");

    query.bindValue(":roomId", roomId);
    query.bindValue(":arrival", reservation.checkInDate());
    query.bindValue(":departure", reservation.checkOutDate());
    query.bindValue(":status", statusStr);
    query.bindValue(":id", reservation.id());

    if (!query.exec()) {
        qDebug() << "Update reservation error:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DbManager::deleteReservation(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM reservations WHERE id_reservation = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Delete reservation error:" << query.lastError().text();
        return false;
    }

    return query.numRowsAffected() > 0;
}


int DbManager::getRoomIdByNumber(const QString& roomNumber) {
    QSqlQuery query;
    query.prepare("SELECT id_room FROM rooms WHERE room_number = :roomNumber");
    query.bindValue(":roomNumber", roomNumber);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

int DbManager::getClientIdByReservation(int reservationId) {
    QSqlQuery query;
    query.prepare("SELECT id_client FROM reservations WHERE id_reservation = :id");
    query.bindValue(":id", reservationId);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    return -1;
}

void DbManager::splitName(const QString& fullName, QString& firstName, QString& lastName) {
    QStringList parts = fullName.split(" ", Qt::SkipEmptyParts);
    if (parts.size() > 1) {
        lastName = parts.takeLast();
        firstName = parts.join(" ");
    } else {
        firstName = fullName;
        lastName = ""; // Default empty last name
    }
}


QStringList DbManager::getAvailableRoomNumbers(const QString& roomType, const QDate& checkIn, const QDate& checkOut) {
    QStringList roomNumbers;

    // Find rooms of the specified type that are not reserved for the given dates
    QSqlQuery query;
    query.prepare(
        "SELECT r.room_number FROM rooms r "
        "JOIN room_types rt ON r.id_type = rt.id_type "
        "WHERE rt.type_name = :roomType "
        "AND r.id_room NOT IN ("
        "   SELECT res.id_room FROM reservations res "
        "   WHERE (res.arrival_date <= :checkOut AND res.departure_date >= :checkIn) "
        "   AND res.status NOT IN ('Cancelled')"
        ") "
        "ORDER BY r.room_number"
        );

    query.bindValue(":roomType", roomType);
    query.bindValue(":checkIn", checkIn);
    query.bindValue(":checkOut", checkOut);

    if (!query.exec()) {
        qDebug() << "Get available rooms error:" << query.lastError().text();
        return roomNumbers;
    }

    while (query.next()) {
        roomNumbers << query.value("room_number").toString();
    }

    return roomNumbers;
}

QStringList DbManager::getRoomTypes() {
    QStringList roomTypes;

    QSqlQuery query("SELECT type_name FROM room_types ORDER BY base_price");

    if (!query.exec()) {
        qDebug() << "Get room types error:" << query.lastError().text();
        return roomTypes;
    }

    while (query.next()) {
        roomTypes << query.value("type_name").toString();
    }

    return roomTypes;
}

double DbManager::getRoomRate(const QString& roomType) {
    QSqlQuery query;
    query.prepare("SELECT base_price FROM room_types WHERE type_name = :roomType");
    query.bindValue(":roomType", roomType);

    if (query.exec() && query.next()) {
        return query.value("base_price").toDouble();
    }

    return 0.0;
}


void DbManager::initializeDatabase() {
    // Check if we need to initialize the database
    if (isInitialized()) {
        return;
    }

    // Begin transaction for faster execution
    m_db.transaction();

    // 1. Initialize room types if they don't exist
    QSqlQuery query;

    // Insert room types
    QList<QPair<QString, double>> roomTypes = {
        {"Standard Single", 149.99},
        {"Standard Double", 179.99},
        {"Deluxe King", 229.99},
        {"Deluxe Double", 249.99},
        {"Junior Suite", 329.99},
        {"Executive Suite", 499.99},
        {"Presidential Suite", 999.99}
    };

    for (const auto& roomType : roomTypes) {
        query.prepare("INSERT INTO room_types (type_name, base_price, description) "
                      "VALUES (:name, :price, :description)");

        query.bindValue(":name", roomType.first);
        query.bindValue(":price", roomType.second);
        query.bindValue(":description", "Description for " + roomType.first);

        if (!query.exec()) {
            qDebug() << "Error initializing room type:" << query.lastError().text();
        }
    }

    // 2. Initialize some rooms
    // Standard Single rooms: 101-110
    for (int i = 1; i <= 10; i++) {
        QString roomNumber = QString("10%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type) "
                      "VALUES (:number, (SELECT id_type FROM room_types WHERE type_name = 'Standard Single'))");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Standard Double rooms: 201-210
    for (int i = 1; i <= 10; i++) {
        QString roomNumber = QString("20%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type) "
                      "VALUES (:number, (SELECT id_type FROM room_types WHERE type_name = 'Standard Double'))");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }
    // Deluxe Double rooms: 401-405 (continuing)
    for (int i = 1; i <= 5; i++) {
        QString roomNumber = QString("40%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type) "
                      "VALUES (:number, (SELECT id_type FROM room_types WHERE type_name = 'Deluxe Double'))");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Junior Suite rooms: 501-503
    for (int i = 1; i <= 3; i++) {
        QString roomNumber = QString("50%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type) "
                      "VALUES (:number, (SELECT id_type FROM room_types WHERE type_name = 'Junior Suite'))");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Executive Suite rooms: 601-602
    for (int i = 1; i <= 2; i++) {
        QString roomNumber = QString("60%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type) "
                      "VALUES (:number, (SELECT id_type FROM room_types WHERE type_name = 'Executive Suite'))");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Presidential Suite room: 701
    query.prepare("INSERT INTO rooms (room_number, id_type) "
                  "VALUES ('701', (SELECT id_type FROM room_types WHERE type_name = 'Presidential Suite'))");

    if (!query.exec()) {
        qDebug() << "Error initializing room:" << query.lastError().text();
    }

    // 3. Initialize some sample countries for the client filter
    QStringList countries = {
        "United States", "France", "United Kingdom", "Germany", "Japan",
        "Canada", "Australia", "Italy", "Spain", "China", "Brazil",
        "India", "Russia", "South Korea", "Mexico"
    };

    // We'll create a sample client for each country
    for (const QString& country : countries) {
        query.prepare("INSERT INTO clients (first_name, last_name, country, email, phone) "
                      "VALUES (:firstName, :lastName, :country, :email, :phone)");

        QString firstName = "Sample";
        QString lastName = country.split(" ").first() + " Client";
        QString email = firstName.toLower() + "." + lastName.toLower().replace(" ", "") + "@example.com";
        QString phone = "+1234567890"; // Dummy phone number

        query.bindValue(":firstName", firstName);
        query.bindValue(":lastName", lastName);
        query.bindValue(":country", country);
        query.bindValue(":email", email);
        query.bindValue(":phone", phone);

        if (!query.exec()) {
            qDebug() << "Error initializing client:" << query.lastError().text();
        }
    }

    // Commit the transaction
    m_db.commit();

    qDebug() << "Database initialized successfully";
}


bool DbManager::isInitialized() {
    // Check if we have any rooms in the database
    QSqlQuery query("SELECT COUNT(*) FROM rooms");

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}


// Add a method to get all countries for filtering
QStringList DbManager::getCountries() {
    QStringList countries;

    QSqlQuery query("SELECT DISTINCT country FROM clients ORDER BY country");

    if (!query.exec()) {
        qDebug() << "Get countries error:" << query.lastError().text();
        return countries;
    }

    while (query.next()) {
        countries << query.value("country").toString();
    }

    return countries;
}


// Add a method to create sample reservations for testing
void DbManager::createSampleReservations() {
    // Check if we already have reservations
    QSqlQuery checkQuery("SELECT COUNT(*) FROM reservations");
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "Sample reservations already exist";
        return;
    }

    // Begin transaction
    m_db.transaction();

    // Get clients
    QList<int> clientIds;
    QSqlQuery clientQuery("SELECT id_client FROM clients LIMIT 10");
    if (clientQuery.exec()) {
        while (clientQuery.next()) {
            clientIds << clientQuery.value(0).toInt();
        }
    }

    if (clientIds.isEmpty()) {
        qDebug() << "No clients found for sample reservations";
        m_db.rollback();
        return;
    }

    // Get rooms
    QList<int> roomIds;
    QSqlQuery roomQuery("SELECT id_room FROM rooms");
    if (roomQuery.exec()) {
        while (roomQuery.next()) {
            roomIds << roomQuery.value(0).toInt();
        }
    }

    if (roomIds.isEmpty()) {
        qDebug() << "No rooms found for sample reservations";
        m_db.rollback();
        return;
    }

    // Create some sample reservations
    QDate today = QDate::currentDate();

    // Sample statuses
    QStringList statuses = {"Pending", "Confirmed", "CheckedIn", "Completed", "Cancelled"};

    // Create 20 sample reservations
    for (int i = 0; i < 20; i++) {
        QSqlQuery query;
        query.prepare("INSERT INTO reservations (id_client, id_room, arrival_date, departure_date, status) "
                      "VALUES (:clientId, :roomId, :arrival, :departure, :status)");

        // Random client
        int clientId = clientIds[i % clientIds.size()];

        // Random room
        int roomId = roomIds[i % roomIds.size()];

        // Random dates
        int daysOffset = (i * 3) % 60; // Spread over about 2 months
        QDate checkIn = today.addDays(daysOffset);
        QDate checkOut = checkIn.addDays(2 + (i % 5)); // Stay between 2-6 days

        // Random status
        QString status = statuses[i % statuses.size()];

        query.bindValue(":clientId", clientId);
        query.bindValue(":roomId", roomId);
        query.bindValue(":arrival", checkIn);
        query.bindValue(":departure", checkOut);
        query.bindValue(":status", status);

        if (!query.exec()) {
            qDebug() << "Error creating sample reservation:" << query.lastError().text();
        }
    }

    // Commit transaction
    m_db.commit();

    qDebug() << "Sample reservations created successfully";
}
