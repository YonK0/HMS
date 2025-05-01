#include "reservation.h"

Reservation::Reservation(int id, const QString &guestName, const QString &roomNumber,
                         const QString &roomType, const QString &country, const QString &phone,
                         const QString &email, const QDate &checkInDate, const QDate &checkOutDate,
                         Status status)
    : m_id(id), m_guestName(guestName), m_roomNumber(roomNumber), m_roomType(roomType),
      m_country(country), m_phone(phone), m_email(email), m_checkInDate(checkInDate),
      m_checkOutDate(checkOutDate), m_status(status)
{
}

QString Reservation::statusString() const
{
    switch (m_status) {
    case Pending:
        return "Pending";
    case Confirmed:
        return "Confirmed";
    case CheckedIn:
        return "Checked-in";
    case Completed:
        return "Completed";
    case Cancelled:
        return "Cancelled";
    default:
        return "Unknown";
    }
}

QList<Reservation> Reservation::createSampleReservations()
{
    QList<Reservation> reservations;

    reservations.append(Reservation(1005, "John Smith", "101", "Standard Double",
                                    "United States", "+1-555-123-4567", "john.smith@example.com",
                                    QDate(2025, 4, 15), QDate(2025, 4, 20), Confirmed));

    reservations.append(Reservation(1001, "Maria Garcia", "205", "Deluxe King",
                                    "Spain", "+34-612-345-678", "maria.garcia@example.com",
                                    QDate(2025, 4, 22), QDate(2025, 4, 28), Pending));

    reservations.append(Reservation(1020, "David Johnson", "302", "Junior Suite",
                                    "Canada", "+1-416-789-0123", "david.j@example.com",
                                    QDate(2025, 4, 18), QDate(2025, 4, 21), CheckedIn));

    reservations.append(Reservation(1003, "Emma Wilson", "405", "Executive Suite",
                                    "Australia", "+61-2-9876-5432", "emma.w@example.com",
                                    QDate(2025, 4, 10), QDate(2025, 4, 15), Completed));

    reservations.append(Reservation(1050, "Hiroshi Tanaka", "504", "Deluxe Double",
                                    "Japan", "+81-3-1234-5678", "hiroshi.t@example.com",
                                    QDate(2025, 4, 25), QDate(2025, 5, 2), Confirmed));

    reservations.append(Reservation(1020, "Sophie Dubois", "103", "Standard Single",
                                    "France", "+33-1-2345-6789", "sophie.d@example.com",
                                    QDate(2025, 4, 12), QDate(2025, 4, 16), Cancelled));

    reservations.append(Reservation(1099, "Ahmed Hassan", "305", "Deluxe King",
                                    "Egypt", "+20-2-1234-5678", "ahmed.h@example.com",
                                    QDate(2025, 4, 28), QDate(2025, 5, 5), Confirmed));

    return reservations;
}

QStringList Reservation::getCountryList()
{
    QStringList countries = {
        "Australia", "Canada", "China", "Egypt", "France", "Germany",
        "India", "Italy", "Japan", "Russia", "Spain", "United Kingdom",
        "United States"
    };

    return countries;
}
