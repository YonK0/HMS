#ifndef RESERVATIONMODEL_H
#define RESERVATIONMODEL_H

#include <QAbstractTableModel>
#include <QDate>
#include <QList>
#include "reservation.h"

// Forward declaration
class DbManager;

class ReservationModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ReservationModel(QObject *parent = nullptr);
    ~ReservationModel();
    DbManager *m_dbManager;
    DbManager* getDatabaseManager() const { return m_dbManager; }

    // Define columns
    enum {
        IdColumn = 0,
        GuestNameColumn,
        RoomNumberColumn,
        RoomTypeColumn,
        CountryColumn,
        PhoneColumn,
        EmailColumn,
        CheckInDateColumn,
        CheckOutDateColumn,
        StatusColumn,
        LastColumn
    };

    // Required overrides for QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // CRUD operations
    void addReservation(const Reservation &reservation);
    void updateReservation(int id, const Reservation &updatedReservation);
    void removeReservation(int id);

    // Access the reservations list
    const QList<Reservation> &reservations() const;

    // Filtering functions
    void filterReservations(const QString &searchText, int searchType,
                            const QDate &fromDate, const QDate &toDate,
                            const QString &roomType, const QString &status,
                            const QString &country);
    void resetFilter();

    // Sorting
    void sortByName();

private:
    QList<Reservation> m_reservations;


    // Load reservations from database
    void loadReservationsFromDatabase();
};

#endif // RESERVATIONMODEL_H
