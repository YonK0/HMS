// dbmanager.h
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "reservation.h"

class DbManager {
public:
    DbManager(const QString& path);
    ~DbManager();
    
    bool isOpen() const;
    QString lastError() const;
    
    // Reservation operations
    bool addReservation(const Reservation& reservation);
    QList<Reservation> getAllReservations();
    bool updateReservation(const Reservation& reservation);
    bool deleteReservation(int id);
    QStringList getAvailableRoomNumbers(const QString& roomType, const QDate& checkIn, const QDate& checkOut);
    QStringList getCountries();
    // Initialization
    void initializeDatabase();
    bool isInitialized();
    void createSampleReservations();
    double getRoomRate(const QString& roomType);
    QList<QString> searchAvailableClients(const QString &searchText);
    bool getClientDetails(const QString &clientName, QString &country, QString &phone, QString &email);
    bool addSampleClients();
    bool createClientTable();
    int getClientIdByName(const QString &clientName);
    
private:
    QSqlDatabase m_db;
   int getOrCreateClient(const QString& fullName, const QString& country, const QString& email, const QString& phone);
   int getRoomIdByNumber(const QString& roomNumber);
   int getClientIdByReservation(int reservationId);
   void splitName(const QString& fullName, QString& firstName, QString& lastName);
   // Room operations

   QStringList getRoomTypes();

};
