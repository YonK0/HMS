// dbmanager.cpp
#include "dbmanager.h"

DbManager::DbManager(const QString& path) {
    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();

    // Use SQLite instead of MySQL
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    // If path is empty, use a default path
    QString dbPath = path.isEmpty() ? "hotel_database.sqlite" : path;
    m_db.setDatabaseName(dbPath);

    if (!m_db.open()) {
        qDebug() << "Database connection error:" << m_db.lastError();
    } else {
        qDebug() << "SQLite database connected successfully";
    }
}

QStringList DbManager::searchAvailableClients(const QString &searchText)
{
    QStringList availableClients;
    QSqlQuery query(m_db); // Make sure to pass the database connection

    qDebug() << "Searching for available clients with search text:" << searchText;

    // Use string concatenation for simple queries like this to avoid parameter binding issues
    QString queryStr;

    if (searchText.isEmpty()) {
        queryStr = "SELECT name FROM clients ORDER BY name";
    } else {
        // Use string concatenation but with proper escaping to prevent SQL injection
        QString escapedText = searchText;
        escapedText.replace("'", "''"); // Basic SQL escape for single quotes
        queryStr = QString("SELECT name FROM clients WHERE name LIKE '%%1%' ORDER BY name").arg(escapedText);
    }

    qDebug() << "Executing query:" << queryStr;

    if (query.exec(queryStr)) {
        while (query.next()) {
            QString name = query.value(0).toString();
            availableClients.append(name);
            qDebug() << "Found client:" << name;
        }
        qDebug() << "Found" << availableClients.size() << "clients matching" << searchText;
    } else {
        qDebug() << "Client search query failed:" << query.lastError().text();
    }

    return availableClients;
}

bool DbManager::createClientTable()
{
    QSqlQuery query;
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS clients ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "country TEXT, "
        "phone TEXT, "
        "email TEXT, "
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
        ")"
        );

    if (!success) {
        qDebug() << "Failed to create clients table:" << query.lastError().text();
    }

    return success;
}

bool DbManager::getClientDetails(const QString &clientName, QString &country, QString &phone, QString &email)
{
    QSqlQuery query;
    query.prepare("SELECT country, phone, email FROM clients WHERE name = ?");
    query.bindValue(0, clientName);

    if (query.exec() && query.next()) {
        country = query.value(0).toString();
        phone = query.value(1).toString();
        email = query.value(2).toString();
        return true;
    }

    return false;
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

bool DbManager::addSampleClients()
{
    // Check if database is open
    if (!isOpen()) {
        qDebug() << "Database is not open, cannot add sample clients";
        return false;
    }

    // Create a list of sample clients with their details
    struct SampleClient {
        QString name;
        QString country;
        QString phone;
        QString email;
    };

    QList<SampleClient> sampleClients = {
        {"John Smith", "United States", "+1-555-123-4567", "john.smith@example.com"},
        {"Maria Garcia", "Spain", "+34-555-987-6543", "maria.garcia@example.com"},
        {"Ahmed Hassan", "Egypt", "+20-555-234-5678", "ahmed.h@example.com"},
        {"Yuki Tanaka", "Japan", "+81-555-876-5432", "yuki.t@example.com"},
        {"Emma Wilson", "Australia", "+61-555-345-6789", "emma.w@example.com"},
        {"Carlos Mendoza", "Mexico", "+52-555-789-0123", "carlos.m@example.com"},
        {"Sophie Dubois", "France", "+33-555-456-7890", "sophie.d@example.com"},
        {"Li Wei", "China", "+86-555-567-8901", "li.wei@example.com"},
        {"Oliver Schmidt", "Germany", "+49-555-678-9012", "oliver.s@example.com"},
        {"Fatima Al-Farsi", "UAE", "+971-555-890-1234", "fatima.a@example.com"}
    };

    // Begin a transaction for better performance
    QSqlDatabase::database().transaction();

    int addedCount = 0;
    bool success = true;

    // Add each client to the database
    for (const SampleClient &client : sampleClients) {
        // Check if the client already exists to avoid duplicates
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM clients WHERE name = ?");
        checkQuery.bindValue(0, client.name);

        if (checkQuery.exec() && checkQuery.next()) {
            int count = checkQuery.value(0).toInt();
            if (count > 0) {
                qDebug() << "Client already exists:" << client.name;
                continue; // Skip this client
            }
        }

        // Insert the new client
        QSqlQuery query;
        query.prepare("INSERT INTO clients (name, country, phone, email) VALUES (?, ?, ?, ?)");
        query.bindValue(0, client.name);
        query.bindValue(1, client.country);
        query.bindValue(2, client.phone);
        query.bindValue(3, client.email);

        if (query.exec()) {
            addedCount++;
        } else {
            qDebug() << "Failed to add client:" << client.name << "-" << query.lastError().text();
            success = false;
        }
    }

    // Commit or rollback the transaction
    if (success) {
        QSqlDatabase::database().commit();
        qDebug() << "Successfully added" << addedCount << "sample clients";
    } else {
        QSqlDatabase::database().rollback();
        qDebug() << "Transaction rolled back due to errors";
    }

    return success;
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


bool DbManager::addReservation(const Reservation &reservation)
{
    // Get client and room IDs
    int clientId = getClientIdByName(reservation.guestName());
    int roomId = getRoomIdByNumber(reservation.roomNumber());

    if (clientId <= 0) {
        qDebug() << "Failed to find client ID for name:" << reservation.guestName();
        return false;
    }

    if (roomId <= 0) {
        qDebug() << "Failed to find room ID for room number:" << reservation.roomNumber();
        return false;
    }

    // Now insert the reservation with the found IDs
    QSqlQuery query;
    query.prepare("INSERT INTO reservations "
                  "(id_client, id_room, arrival_date, departure_date, status) "
                  "VALUES (?, ?, ?, ?, ?)");

    query.bindValue(0, clientId);
    query.bindValue(1, roomId);
    query.bindValue(2, reservation.checkInDate().toString("yyyy-MM-dd"));
    query.bindValue(3, reservation.checkOutDate().toString("yyyy-MM-dd"));
    query.bindValue(4, static_cast<int>(reservation.status()));

    bool success = query.exec();

    if (success) {
        qDebug() << "Reservation added with ID:" << query.lastInsertId().toInt();
    } else {
        qDebug() << "Failed to add reservation to database:" << query.lastError().text();
    }

    return success;
}

int DbManager::getClientIdByName(const QString &fullName)
{
    // Split the full name into first and last name
    QStringList nameParts = fullName.split(" ", Qt::SkipEmptyParts);
    QString firstName, lastName;

    if (nameParts.size() >= 1) {
        firstName = nameParts.at(0);
    }

    if (nameParts.size() >= 2) {
        // If there are multiple parts, combine all parts after the first as the last name
        nameParts.removeFirst();
        lastName = nameParts.join(" ");
    }

    qDebug() << "Looking up client ID for:" << fullName
             << "(First name:" << firstName << ", Last name:" << lastName << ")";

    QSqlQuery query;
    if (!lastName.isEmpty()) {
        // If we have both first and last name
        query.prepare("SELECT id_client FROM clients WHERE first_name = ? AND last_name = ?");
        query.bindValue(0, firstName);
        query.bindValue(1, lastName);
    } else {
        // If we only have one name part, try matching it against first_name
        query.prepare("SELECT id_client FROM clients WHERE first_name = ?");
        query.bindValue(0, firstName);
    }

    if (query.exec() && query.next()) {
        int id = query.value(0).toInt();
        qDebug() << "Found client ID:" << id;
        return id;
    } else {
        qDebug() << "Client not found:" << fullName;
        qDebug() << "SQL error:" << query.lastError().text();
        return -1;
    }
}

QList<Reservation> DbManager::getAllReservations()
{
    QList<Reservation> reservations;

    // Only declare the query variable once
    QSqlQuery query;

    // Use prepare() instead of direct constructor with query string
    query.prepare("SELECT r.id_reservation, c.first_name, c.last_name, c.country, "
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


int DbManager::getRoomIdByNumber(const QString &roomNumber)
{
    // First check if rooms table exists
    QSqlQuery tableCheck("SELECT name FROM sqlite_master WHERE type='table' AND name='rooms'");
    if (!tableCheck.exec() || !tableCheck.next()) {
        qDebug() << "Rooms table does not exist!";
        return -1;
    }

    // Get all rooms
    QSqlQuery query("SELECT * FROM rooms LIMIT 100");
    if (query.exec()) {
        // Find the room number and id columns
        int idIndex = 0;
        int numberIndex = 1; // Assume room number is in the second column

        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); i++) {
            QString fieldName = record.fieldName(i);
            if (fieldName.contains("id", Qt::CaseInsensitive)) {
                idIndex = i;
            } else if (fieldName.contains("number", Qt::CaseInsensitive) ||
                       fieldName.contains("room", Qt::CaseInsensitive)) {
                numberIndex = i;
                qDebug() << "Using field" << fieldName << "as room number field";
            }
        }

        // Search for room by number
        while (query.next()) {
            QString number = query.value(numberIndex).toString();
            if (number == roomNumber) {
                int id = query.value(idIndex).toInt();
                qDebug() << "Found room" << number << "with ID" << id;
                return id;
            }
        }
    } else {
        qDebug() << "Failed to query rooms:" << query.lastError().text();
    }

    qDebug() << "Room not found:" << roomNumber;
    return -1;
}

int DbManager::getClientIdByReservation(int reservationId) {
    QSqlQuery query;
    query.prepare("SELECT id_client FROM reservations WHERE id_reservation = :id");
    query.bindValue(":id", reservationId);

    if (query.exec() && query.next())
    {
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
    query.bindValue(":checkIn", checkIn.toString(Qt::ISODate));
    query.bindValue(":checkOut", checkOut.toString(Qt::ISODate));

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

    QSqlQuery query;
    query.prepare("SELECT type_name FROM room_types ORDER BY base_price");

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


// Initialize database with SQLite schema and sample data
void DbManager::initializeDatabase() {
    // Check if we need to initialize the database
    if (isInitialized()) {
        qDebug() << "Database already initialized";
        return;
    }

    qDebug() << "Initializing database...";

    // Begin transaction for faster execution
    m_db.transaction();

    QSqlQuery query;

    // Create tables
    // Clients table
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS clients ("
        "id_client INTEGER PRIMARY KEY AUTOINCREMENT, "
        "last_name TEXT NOT NULL, "
        "first_name TEXT NOT NULL, "
        "country TEXT NOT NULL, "
        "email TEXT, "
        "phone TEXT, "
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
        ")"
        );

    if (!success) {
        qDebug() << "Error creating clients table:" << query.lastError().text();
    }

    // Room types table
    success = query.exec(
        "CREATE TABLE IF NOT EXISTS room_types ("
        "id_type INTEGER PRIMARY KEY AUTOINCREMENT, "
        "type_name TEXT NOT NULL, "
        "description TEXT, "
        "base_price REAL NOT NULL"
        ")"
        );

    if (!success) {
        qDebug() << "Error creating room_types table:" << query.lastError().text();
    }

    // Rooms table
    success = query.exec(
        "CREATE TABLE IF NOT EXISTS rooms ("
        "id_room INTEGER PRIMARY KEY AUTOINCREMENT, "
        "room_number TEXT NOT NULL UNIQUE, "
        "id_type INTEGER NOT NULL, "
        "status TEXT DEFAULT 'Available' CHECK(status IN ('Available', 'Occupied', 'Maintenance', 'Reserved')), "
        "FOREIGN KEY (id_type) REFERENCES room_types(id_type)"
        ")"
        );

    if (!success) {
        qDebug() << "Error creating rooms table:" << query.lastError().text();
    }

    // Reservations table
    success = query.exec(
        "CREATE TABLE IF NOT EXISTS reservations ("
        "id_reservation INTEGER PRIMARY KEY AUTOINCREMENT, "
        "id_client INTEGER NOT NULL, "
        "id_room INTEGER NOT NULL, "
        "arrival_date DATE NOT NULL, "
        "departure_date DATE NOT NULL, "
        "status TEXT DEFAULT 'Pending' CHECK(status IN ('Pending', 'Confirmed', 'CheckedIn', 'Completed', 'Cancelled')), "
        "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, "
        "updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP, "
        "FOREIGN KEY (id_client) REFERENCES clients(id_client), "
        "FOREIGN KEY (id_room) REFERENCES rooms(id_room), "
        "CHECK (departure_date > arrival_date)"
        ")"
        );

    if (!success) {
        qDebug() << "Error creating reservations table:" << query.lastError().text();
    }

    // Create trigger for updated_at
    success = query.exec(
        "CREATE TRIGGER IF NOT EXISTS update_reservation_timestamp "
        "AFTER UPDATE ON reservations "
        "BEGIN "
        "    UPDATE reservations SET updated_at = CURRENT_TIMESTAMP WHERE id_reservation = NEW.id_reservation; "
        "END"
        );

    if (!success) {
        qDebug() << "Error creating trigger:" << query.lastError().text();
    }

    // Add sample data

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
        query.prepare("INSERT INTO room_types (type_name, description, base_price) "
                      "VALUES (:name, :description, :price)");

        query.bindValue(":name", roomType.first);
        query.bindValue(":description", "Description for " + roomType.first);
        query.bindValue(":price", roomType.second);

        if (!query.exec()) {
            qDebug() << "Error initializing room type:" << query.lastError().text();
        }
    }

    // Insert sample rooms
    // Standard Single rooms: 101-105
    for (int i = 1; i <= 5; i++) {
        QString roomNumber = QString("10%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                      "VALUES (:number, 1, 'Available')");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Standard Double rooms: 201-205
    for (int i = 1; i <= 5; i++) {
        QString roomNumber = QString("20%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                      "VALUES (:number, 2, 'Available')");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Deluxe King rooms: 301-303
    for (int i = 1; i <= 3; i++) {
        QString roomNumber = QString("30%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                      "VALUES (:number, 3, 'Available')");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Deluxe Double rooms: 401-402
    for (int i = 1; i <= 2; i++) {
        QString roomNumber = QString("40%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                      "VALUES (:number, 4, 'Available')");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Junior Suite rooms: 501-502
    for (int i = 1; i <= 2; i++) {
        QString roomNumber = QString("50%1").arg(i);
        query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                      "VALUES (:number, 5, 'Available')");

        query.bindValue(":number", roomNumber);

        if (!query.exec()) {
            qDebug() << "Error initializing room:" << query.lastError().text();
        }
    }

    // Executive Suite room: 601
    query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                  "VALUES ('601', 6, 'Available')");

    if (!query.exec()) {
        qDebug() << "Error initializing room:" << query.lastError().text();
    }

    // Presidential Suite room: 701
    query.prepare("INSERT INTO rooms (room_number, id_type, status) "
                  "VALUES ('701', 7, 'Available')");

    if (!query.exec()) {
        qDebug() << "Error initializing room:" << query.lastError().text();
    }

    // Initialize sample clients
    QList<QVector<QString>> clients = {
        {"John", "Smith", "United States", "john.smith@example.com", "+1-555-123-4567"},
        {"Marie", "Dupont", "France", "marie.dupont@example.com", "+33-612-345-678"},
        {"Ahmed", "Hassan", "Egypt", "ahmed.hassan@example.com", "+20-10-2345-6789"},
        {"Yuki", "Tanaka", "Japan", "yuki.tanaka@example.com", "+81-90-1234-5678"},
        {"Carlos", "Rodriguez", "Spain", "carlos.rodriguez@example.com", "+34-612-345-678"},
        {"Emma", "Wilson", "United Kingdom", "emma.wilson@example.com", "+44-7700-900123"},
        {"Hans", "Mueller", "Germany", "hans.mueller@example.com", "+49-151-12345678"},
        {"Sophia", "Chen", "China", "sophia.chen@example.com", "+86-139-1234-5678"},
        {"Alessia", "Rossi", "Italy", "alessia.rossi@example.com", "+39-312-345-6789"},
        {"Lucas", "Silva", "Brazil", "lucas.silva@example.com", "+55-11-91234-5678"}
    };

    for (const auto& client : clients) {
        query.prepare("INSERT INTO clients (first_name, last_name, country, email, phone) "
                      "VALUES (:firstName, :lastName, :country, :email, :phone)");

        query.bindValue(":firstName", client[0]);
        query.bindValue(":lastName", client[1]);
        query.bindValue(":country", client[2]);
        query.bindValue(":email", client[3]);
        query.bindValue(":phone", client[4]);

        if (!query.exec()) {
            qDebug() << "Error initializing client:" << query.lastError().text();
        }
    }
    addSampleClients();
    // Commit the transaction
    m_db.commit();

    qDebug() << "Database initialized successfully";
}


bool DbManager::isInitialized() {
    // Check if we have any rooms in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='rooms'");

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count == 0) {
            return false;
        }
    } else {
        return false;
    }

    // Check if there are any rooms
    query.prepare("SELECT COUNT(*) FROM rooms");

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
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name='reservations'");

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        qDebug() << "Reservations table doesn't exist yet";
        return;
    }

    checkQuery.prepare("SELECT COUNT(*) FROM reservations");
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "Sample reservations already exist";
        return;
    }

    // Begin transaction
    m_db.transaction();

    // Get clients
    QList<int> clientIds;
    QSqlQuery clientQuery;
    clientQuery.prepare("SELECT id_client FROM clients");
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
    QSqlQuery roomQuery;
    roomQuery.prepare("SELECT id_room FROM rooms");
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

    // Create 10 sample reservations
    QSqlQuery query;
    for (int i = 0; i < 10; i++) {
        query.prepare("INSERT INTO reservations (id_client, id_room, arrival_date, departure_date, status) "
                      "VALUES (:clientId, :roomId, :arrival, :departure, :status)");

        // Get client and room (ensuring not to reuse the same room for overlapping dates)
        int clientId = clientIds[i % clientIds.size()];
        int roomId = roomIds[i % roomIds.size()];

        // Create dates
        int daysOffset = (i * 3) % 60; // Spread over about 2 months
        QDate checkIn = today.addDays(daysOffset);
        QDate checkOut = checkIn.addDays(2 + (i % 5)); // Stay between 2-6 days

        // Set status
        QString status = statuses[i % statuses.size()];

        query.bindValue(":clientId", clientId);
        query.bindValue(":roomId", roomId);
        query.bindValue(":arrival", checkIn.toString(Qt::ISODate));
        query.bindValue(":departure", checkOut.toString(Qt::ISODate));
        query.bindValue(":status", status);

        if (!query.exec()) {
            qDebug() << "Error creating sample reservation:" << query.lastError().text();
        }
    }

    // Commit transaction
    m_db.commit();

    qDebug() << "Sample reservations created successfully";
}
