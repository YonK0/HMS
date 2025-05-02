#include "reservationModel.h"
#include <QColor>
#include <QBrush>

ReservationModel::ReservationModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    // Initialize the database manager
    m_dbManager = new DbManager("");

    // Load reservations if database connection is successful
    if (m_dbManager && m_dbManager->isOpen()) {
        loadReservationsFromDatabase();
    } else {
        qDebug() << "Failed to open database connection";
    }
}

ReservationModel::~ReservationModel()
{
    delete m_dbManager;
    m_dbManager = nullptr;
}

int ReservationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_reservations.size();
}

int ReservationModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return LastColumn;
}

QVariant ReservationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_reservations.size())
        return QVariant();

    const Reservation &reservation = m_reservations.at(index.row());

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case IdColumn:
            return reservation.id();
        case GuestNameColumn:
            return reservation.guestName();
        case RoomNumberColumn:
            return reservation.roomNumber();
        case RoomTypeColumn:
            return reservation.roomType();
        case CountryColumn:
            return reservation.country();
        case PhoneColumn:
            return reservation.phone();
        case EmailColumn:
            return reservation.email();
        case CheckInDateColumn:
            return reservation.checkInDate().toString("yyyy-MM-dd");
        case CheckOutDateColumn:
            return reservation.checkOutDate().toString("yyyy-MM-dd");
        case StatusColumn:
            switch (reservation.status()) {
            case Reservation::Pending:
                return tr("Pending");
            case Reservation::Confirmed:
                return tr("Confirmed");
            case Reservation::CheckedIn:
                return tr("Checked-in");
            case Reservation::Completed:
                return tr("Completed");
            case Reservation::Cancelled:
                return tr("Cancelled");
            default:
                return QVariant();
            }
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QVariant ReservationModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case IdColumn:
            return tr("ID");
        case GuestNameColumn:
            return tr("Guest Name");
        case RoomNumberColumn:
            return tr("Room No.");
        case RoomTypeColumn:
            return tr("Room Type");
        case CountryColumn:
            return tr("Country");
        case PhoneColumn:
            return tr("Phone");
        case EmailColumn:
            return tr("Email");
        case CheckInDateColumn:
            return tr("Check-in Date");
        case CheckOutDateColumn:
            return tr("Check-out Date");
        case StatusColumn:
            return tr("Status");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

void ReservationModel::loadReservationsFromDatabase()
{
    // Clear any existing data
    beginResetModel();
    m_reservations.clear();

    // Load all reservations from database
    if (m_dbManager && m_dbManager->isOpen()) {
        m_reservations = m_dbManager->getAllReservations();
    } else {
        qDebug() << "Database connection issue. Cannot load reservations.";
    }

    endResetModel();
}

void ReservationModel::addReservation(const Reservation &reservation)
{
    // Add to database first
    if (m_dbManager && m_dbManager->isOpen()) {
        bool success = m_dbManager->addReservation(reservation);
        if (success) {
            // Reload all reservations to get the new ID
            loadReservationsFromDatabase();

            // Notify views that data has changed
            emit dataChanged(QModelIndex(), QModelIndex());
        }
    }
}

void ReservationModel::updateReservation(int id, const Reservation &updatedReservation)
{
    // Update in database
    if (m_dbManager && m_dbManager->isOpen()) {
        bool success = m_dbManager->updateReservation(updatedReservation);
        if (success) {
            // Find and update in the local model
            for (int i = 0; i < m_reservations.size(); ++i) {
                if (m_reservations[i].id() == id) {
                    m_reservations[i] = updatedReservation;

                    QModelIndex topLeft = index(i, 0);
                    QModelIndex bottomRight = index(i, columnCount() - 1);

                    emit dataChanged(topLeft, bottomRight);
                    break;
                }
            }
        }
    }
}

void ReservationModel::removeReservation(int id)
{
    // Delete from database
    if (m_dbManager && m_dbManager->isOpen()) {
        bool success = m_dbManager->deleteReservation(id);
        if (success) {
            // Find and remove from local model
            for (int i = 0; i < m_reservations.size(); ++i) {
                if (m_reservations[i].id() == id) {
                    beginRemoveRows(QModelIndex(), i, i);
                    m_reservations.removeAt(i);
                    endRemoveRows();

                    // Notify views that data has changed
                    emit dataChanged(QModelIndex(), QModelIndex());
                    break;
                }
            }
        }
    }
}

const QList<Reservation> &ReservationModel::reservations() const
{
    return m_reservations;
}

void ReservationModel::filterReservations(const QString &searchText, int searchType,
                                          const QDate &fromDate, const QDate &toDate,
                                          const QString &roomType, const QString &status,
                                          const QString &country)
{
    // Begin reset to clear current data
    beginResetModel();
    m_reservations.clear();

    if (!m_dbManager || !m_dbManager->isOpen()) {
        qDebug() << "Database connection issue. Cannot filter reservations.";
        endResetModel();
        return;
    }

    // Debug what criteria we're filtering with
    qDebug() << "Filtering with criteria:";
    qDebug() << "  Search text:" << searchText << "Type:" << searchType;
    qDebug() << "  Date range:" << fromDate << "to" << toDate;
    qDebug() << "  Room type:" << roomType;
    qDebug() << "  Status:" << status;
    qDebug() << "  Country:" << country;

    // Get all reservations - we'll filter them in memory for simplicity
    QList<Reservation> allReservations = m_dbManager->getAllReservations();
    qDebug() << "Total reservations before filtering:" << allReservations.size();

    // Apply filters
    for (const Reservation &reservation : allReservations) {
        bool matchesSearch = true;
        bool matchesDate = true;
        bool matchesRoomType = true;
        bool matchesStatus = true;
        bool matchesCountry = true;

        // Apply search text filter
        if (!searchText.isEmpty()) {
            switch (searchType) {
            case 1: // ID
                matchesSearch = (QString::number(reservation.id()) == searchText);
                break;
            case 2: // Guest Name
                matchesSearch = reservation.guestName().contains(searchText, Qt::CaseInsensitive);
                break;
            case 3: // Room Number
                matchesSearch = reservation.roomNumber().contains(searchText, Qt::CaseInsensitive);
                break;
            case 4: // Room Type
                matchesSearch = reservation.roomType().contains(searchText, Qt::CaseInsensitive);
                break;
            case 5: // Country
                matchesSearch = reservation.country().contains(searchText, Qt::CaseInsensitive);
                break;
            case 6: // Phone
                matchesSearch = reservation.phone().contains(searchText, Qt::CaseInsensitive);
                break;
            case 7: // Email
                matchesSearch = reservation.email().contains(searchText, Qt::CaseInsensitive);
                break;
            case 8: // Check-in Date
                if (fromDate.isValid() && toDate.isValid()) {
                    matchesDate = (reservation.checkInDate() >= fromDate &&
                                   reservation.checkInDate() <= toDate);
                    // Skip other search text matching since we're using date range
                    matchesSearch = true;
                } else {
                    matchesSearch = reservation.checkInDate().toString("yyyy-MM-dd").contains(searchText);
                }
                break;
            case 9: // Check-out Date
                if (fromDate.isValid() && toDate.isValid()) {
                    matchesDate = (reservation.checkOutDate() >= fromDate &&
                                   reservation.checkOutDate() <= toDate);
                    // Skip other search text matching since we're using date range
                    matchesSearch = true;
                } else {
                    matchesSearch = reservation.checkOutDate().toString("yyyy-MM-dd").contains(searchText);
                }
                break;
            default:
                break;
            }
        }

        // Apply room type filter
        if (roomType != "All Types") {
            matchesRoomType = (reservation.roomType() == roomType);
        }

        // Apply status filter
        if (status != "All Statuses") {
            QString statusStr;
            switch (reservation.status()) {
            case Reservation::Pending: statusStr = "Pending"; break;
            case Reservation::Confirmed: statusStr = "Confirmed"; break;
            case Reservation::CheckedIn: statusStr = "Checked-in"; break;
            case Reservation::Completed: statusStr = "Completed"; break;
            case Reservation::Cancelled: statusStr = "Cancelled"; break;
            }
            matchesStatus = (statusStr == status);
        }

        // Apply country filter
        if (country != "All Countries") {
            matchesCountry = (reservation.country() == country);
        }

        // If all filters match, add to filtered list
        if (matchesSearch && matchesDate && matchesRoomType && matchesStatus && matchesCountry) {
            m_reservations.append(reservation);
        }
    }

    qDebug() << "Total reservations after filtering:" << m_reservations.size();

    // End reset to update views
    endResetModel();

    // Emit dataChanged to update any other views
    emit dataChanged(QModelIndex(), QModelIndex());
}

void ReservationModel::resetFilter()
{
    // Simply reload all reservations
    loadReservationsFromDatabase();
}

void ReservationModel::sortByName()
{
    // Sort reservations by guest name
    beginResetModel();

    std::sort(m_reservations.begin(), m_reservations.end(),
              [](const Reservation &a, const Reservation &b) {
                  return a.guestName().toLower() < b.guestName().toLower();
              });

    endResetModel();
}


void ReservationModel::refresh()
{
    beginResetModel();
    // Reload all reservations from the database
    if (m_dbManager && m_dbManager->isOpen()) {
        m_reservations = m_dbManager->getAllReservations();
    }
    endResetModel();

    // Emit dataChanged to update any views
    emit dataChanged(QModelIndex(), QModelIndex());
}
