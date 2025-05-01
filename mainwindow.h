#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidgetItem>
#include "reservation.h"
#include "reservationModel.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QComboBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QDateTimeAxis>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
//#include <QtPrintSupport/QPdfWriter>
#include <QtGui/QPainter>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QPdfWriter>
#include "reservationModel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //DbManager* getDatabaseManager() const { return m_dbManager; }
private slots:
    // Button handlers
    void on_sortButton_clicked();
    void on_searchButton_clicked();
    void on_resetButton_clicked();
    void on_addReservationButton_clicked();
    void on_advancedSearchCheckBox_toggled(bool checked);
    void on_searchTypeComboBox_currentIndexChanged(int index);
    void on_reservationsTableView_cellDoubleClicked(int row, int column);
    void on_modifyButton_clicked();
    void on_deleteButton_clicked();
    void onReservationDataChanged();
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_clearButton_clicked();
    void on_checkAvailabilityButton_clicked();
    void on_checkInDateEdit_dateChanged(const QDate &date);
    void on_checkOutDateEdit_dateChanged(const QDate &date);
    void on_nightsSpinBox_valueChanged(int nights);
    void on_roomTypeComboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void showInfoMessage(const QString &title, const QString &message);
    bool showConfirmationMessage(const QString &title, const QString &message);
    void showWarningMessage(const QString &title, const QString &message);
    ReservationModel *m_reservationModel = nullptr;
    void setupSidebar();
    QPushButton* createSidebarButton(const QString& text, const QString& icon);
    void setupReservationsTab();
    void setupDashboard(); 
    void setupCountryStatsTable(QTableView *tableView);
    int getNextReservationId();
    void populateCountryComboBox();
    void setupTableWidget();
    void editReservation(int id);
    Reservation* findReservationById(int id);
    void setupTableViewAppearance(QTableView *tableView);
    void updateDashboard();
    void exportToPdf();

// Current reservation ID being edited (-1 for new reservation)
    int m_currentReservationId = -1;

    // Helper methods for reservation form
    void clearReservationForm();
    void updateRoomDetails();
    void calculateTotalAmount();
    void updateNights();

    QLineSeries *m_currentYearSeries = nullptr;
    QLineSeries *m_previousYearSeries = nullptr;
    QPieSeries *m_statusSeries = nullptr;
    QChart *m_reservationChart = nullptr;
    QChart *m_statusChart = nullptr;
    QTableView *m_countryStatsTableView = nullptr;
    QValueAxis *m_reservationYAxis = nullptr;
};
#endif // MAINWINDOW_H
