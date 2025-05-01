#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QDate>
#include <QList>

class Reservation
{
public:
    enum Status {
        Pending,
        Confirmed,
        CheckedIn,
        Completed,
        Cancelled
    };

    Reservation() = default;
    Reservation(int id, const QString &guestName, const QString &roomNumber,
                const QString &roomType, const QString &country, const QString &phone,
                const QString &email, const QDate &checkInDate, const QDate &checkOutDate,
                Status status);

    // Getters
    int id() const { return m_id; }
    QString guestName() const { return m_guestName; }
    QString roomNumber() const { return m_roomNumber; }
    QString roomType() const { return m_roomType; }
    QString country() const { return m_country; }
    QString phone() const { return m_phone; }
    QString email() const { return m_email; }
    QDate checkInDate() const { return m_checkInDate; }
    QDate checkOutDate() const { return m_checkOutDate; }
    Status status() const { return m_status; }
    QString statusString() const;

    // Setters
    void setId(int id) { m_id = id; }
    void setGuestName(const QString &name) { m_guestName = name; }
    void setRoomNumber(const QString &number) { m_roomNumber = number; }
    void setRoomType(const QString &type) { m_roomType = type; }
    void setCountry(const QString &country) { m_country = country; }
    void setPhone(const QString &phone) { m_phone = phone; }
    void setEmail(const QString &email) { m_email = email; }
    void setCheckInDate(const QDate &date) { m_checkInDate = date; }
    void setCheckOutDate(const QDate &date) { m_checkOutDate = date; }
    void setStatus(Status status) { m_status = status; }

    // Static methods for demo data
    static QList<Reservation> createSampleReservations();
    static QStringList getCountryList();

private:
    int m_id = 0;
    QString m_guestName;
    QString m_roomNumber;
    QString m_roomType;
    QString m_country;
    QString m_phone;
    QString m_email;
    QDate m_checkInDate;
    QDate m_checkOutDate;
    Status m_status = Pending;
};

#endif // RESERVATION_H