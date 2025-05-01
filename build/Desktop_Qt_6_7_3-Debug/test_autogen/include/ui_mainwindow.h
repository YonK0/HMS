/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_reservations;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *searchGroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *searchTypeComboBox;
    QLineEdit *searchLineEdit;
    QLabel *dateRangeLabel;
    QDateEdit *fromDateEdit;
    QLabel *toLabel;
    QDateEdit *toDateEdit;
    QPushButton *searchButton;
    QPushButton *resetButton;
    QHBoxLayout *advancedSearchLayout;
    QCheckBox *advancedSearchCheckBox;
    QLabel *roomTypeLabel;
    QComboBox *roomTypeFilterComboBox;
    QLabel *statusFilterLabel;
    QComboBox *statusFilterComboBox;
    QLabel *countryFilterLabel;
    QComboBox *countryFilterComboBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *sortButton;
    QPushButton *addReservationButton;
    QSplitter *mainSplitter;
    QTableView *reservationsTableView;
    QWidget *buttonContainer;
    QHBoxLayout *buttonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *modifyButton;
    QPushButton *deleteButton;
    QWidget *statsContainer;
    QVBoxLayout *statsLayout;
    QWidget *dashboardWidget;
    QHBoxLayout *chartsLayout;
    QFrame *trafficChartFrame;
    QVBoxLayout *trafficFrameLayout;
    QLabel *trafficTitle;
    QGraphicsView *trafficChart;
    QFrame *trafficLegendFrame;
    QHBoxLayout *trafficLegendLayout;
    QFrame *copilotLegend;
    QHBoxLayout *copilotLegendLayout;
    QFrame *copilotColor;
    QLabel *copilotText;
    QFrame *personalSiteLegend;
    QHBoxLayout *personalSiteLegendLayout;
    QFrame *personalSiteColor;
    QLabel *personalSiteText;
    QSpacerItem *trafficLegendSpacer;
    QFrame *countryStatsFrame;
    QVBoxLayout *countryStatsLayout;
    QLabel *countryStatsTitle;
    QTableWidget *countryStatsTable;
    QFrame *languageChartFrame;
    QVBoxLayout *languageFrameLayout;
    QLabel *languageTitle;
    QGraphicsView *languageChart;
    QFrame *languageLegendFrame;
    QHBoxLayout *languageLegendLayout;
    QFrame *htmlLegend;
    QHBoxLayout *htmlLegendLayout;
    QFrame *htmlColor;
    QLabel *htmlText;
    QFrame *javascriptLegend;
    QHBoxLayout *javascriptLegendLayout;
    QFrame *javascriptColor;
    QLabel *javascriptText;
    QFrame *cssLegend;
    QHBoxLayout *cssLegendLayout;
    QFrame *cssColor;
    QLabel *cssText;
    QSpacerItem *languageLegendSpacer;
    QLabel *proTipLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *selectedReservationLabel;
    QSpacerItem *horizontalSpacer1;
    QWidget *tab_calendar;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *prevMonthButton;
    QLabel *monthYearLabel;
    QPushButton *nextMonthButton;
    QPushButton *todayButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *filterLayout;
    QLabel *roomTypeLabel1;
    QComboBox *roomTypeFilterComboBox1;
    QLabel *minRoomsLabel;
    QSpinBox *minRoomsSpinBox;
    QPushButton *applyFilterButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *legendLayout;
    QLabel *legendLabel;
    QFrame *fullyAvailableFrame;
    QLabel *fullyAvailableLabel;
    QFrame *partiallyAvailableFrame;
    QLabel *partiallyAvailableLabel;
    QFrame *fullyBookedFrame;
    QLabel *fullyBookedLabel;
    QSpacerItem *horizontalSpacer_5;
    QCalendarWidget *calendarWidget;
    QWidget *tab_add_reservation;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *clientGroupBox;
    QHBoxLayout *clientLayout;
    QLabel *clientSearchLabel;
    QComboBox *clientComboBox;
    QPushButton *searchClientButton;
    QGroupBox *roomDetailsGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *roomTypeLabel_2;
    QComboBox *roomTypeComboBox;
    QLabel *availableRoomsLabel;
    QComboBox *roomNumberComboBox;
    QLabel *rateLabel;
    QDoubleSpinBox *rateSpinBox;
    QPushButton *checkAvailabilityButton;
    QLabel *roomDetailsLabel;
    QGroupBox *stayDetailsGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *checkInLabel;
    QDateEdit *checkInDateEdit;
    QLabel *checkInTimeLabel;
    QTimeEdit *checkInTimeEdit;
    QLabel *checkOutLabel;
    QDateEdit *checkOutDateEdit;
    QLabel *checkOutTimeLabel;
    QTimeEdit *checkOutTimeEdit;
    QLabel *nightsLabel;
    QSpinBox *nightsSpinBox;
    QLabel *adultsLabel;
    QSpinBox *adultsSpinBox;
    QLabel *childrenLabel;
    QSpinBox *childrenSpinBox;
    QGroupBox *paymentDetailsGroupBox;
    QGridLayout *gridLayout_4;
    QLabel *paymentMethodLabel;
    QComboBox *paymentMethodComboBox;
    QLabel *depositLabel;
    QDoubleSpinBox *depositSpinBox;
    QLabel *totalAmountLabel;
    QDoubleSpinBox *totalAmountSpinBox;
    QLabel *statusLabel;
    QComboBox *statusComboBox;
    QGroupBox *notesGroupBox;
    QVBoxLayout *verticalLayout_8;
    QTextEdit *notesTextEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_41;
    QPushButton *clearButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuReservation;
    QMenu *menuView;
    QMenu *menuService;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 650);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"/* Base styles for the entire application */\n"
"QMainWindow, QDialog, QWidget {\n"
"    background-color: #f5f7fa;\n"
"    font-family: 'Segoe UI', 'Roboto', sans-serif;\n"
"    font-size: 9.5pt;\n"
"    color: #37474f;\n"
"}\n"
"\n"
"/* Main form container styling */\n"
"#tab_add_reservation {\n"
"    background-color: #f8f9fa;\n"
"    padding: 15px;\n"
"}\n"
"\n"
"/* Group box styling */\n"
"#tab_add_reservation QGroupBox {\n"
"    border: 1px solid #dee2e6;\n"
"    border-radius: 6px;\n"
"    margin-top: 15px;\n"
"    padding-top: 25px;\n"
"    background-color: white;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"#tab_add_reservation QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 8px;\n"
"    color: #495057;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"/* Form labels */\n"
"#tab_add_reservation QLabel {\n"
"    font-size: 10pt;\n"
"    color: #495057;\n"
"    padding: 4px 0;\n"
"}\n"
"\n"
"/* Input field styling */\n"
"#tab_add_reservation QComboBox,\n"
"#tab_add_r"
                        "eservation QSpinBox,\n"
"#tab_add_reservation QDoubleSpinBox,\n"
"#tab_add_reservation QDateEdit,\n"
"#tab_add_reservation QTimeEdit {\n"
"    border: 1px solid #ced4da;\n"
"    border-radius: 4px;\n"
"    padding: 6px 10px;\n"
"    min-height: 34px;\n"
"    font-size: 10pt;\n"
"    background-color: white;\n"
"}\n"
"\n"
"#tab_add_reservation QComboBox:editable {\n"
"    padding: 6px 10px;\n"
"}\n"
"\n"
"/* Date/Time edit specific styling */\n"
"#tab_add_reservation QDateEdit,\n"
"#tab_add_reservation QTimeEdit {\n"
"    padding-right: 25px;\n"
"}\n"
"\n"
"#tab_add_reservation QDateEdit::drop-down,\n"
"#tab_add_reservation QTimeEdit::drop-down {\n"
"    width: 24px;\n"
"    border-left: 1px solid #ced4da;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"/* Spin box arrows */\n"
"#tab_add_reservation QSpinBox::up-button,\n"
"#tab_add_reservation QDoubleSpinBox::up-button,\n"
"#tab_add_reservation QSpinBox::down-button,\n"
"#tab_add_reservation QDoubleSpinBox::down-button {\n"
"    width: 20px;\n"
"    border-l"
                        "eft: 1px solid #ced4da;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"#tab_add_reservation QSpinBox::up-arrow,\n"
"#tab_add_reservation QDoubleSpinBox::up-arrow {\n"
"    image: url(:/icons/up-arrow.svg);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"#tab_add_reservation QSpinBox::down-arrow,\n"
"#tab_add_reservation QDoubleSpinBox::down-arrow {\n"
"    image: url(:/icons/down-arrow.svg);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* Button styling */\n"
"#tab_add_reservation QPushButton {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 8px 16px;\n"
"    font-size: 10pt;\n"
"    min-height: 34px;\n"
"}\n"
"\n"
"#tab_add_reservation QPushButton:hover {\n"
"    background-color: #0069d9;\n"
"}\n"
"\n"
"#tab_add_reservation QPushButton:pressed {\n"
"    background-color: #0056b3;\n"
"}\n"
"\n"
"/* Special button for check availability */\n"
"#checkAvailabilityButton {\n"
"    background-color: #28a745;\n"
"}"
                        "\n"
"\n"
"#checkAvailabilityButton:hover {\n"
"    background-color: #218838;\n"
"}\n"
"\n"
"/* Form layout adjustments */\n"
"#tab_add_reservation QGridLayout {\n"
"    margin: 10px;\n"
"    spacing: 10px;\n"
"}\n"
"\n"
"#tab_add_reservation QHBoxLayout {\n"
"    spacing: 10px;\n"
"}\n"
"\n"
"/* Payment section styling */\n"
"#paymentGroupBox QLabel {\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#paymentGroupBox QDoubleSpinBox {\n"
"    font-weight: bold;\n"
"    color: #dc3545;\n"
"}\n"
"\n"
"/* Notes section */\n"
"#notesTextEdit {\n"
"    border: 1px solid #ced4da;\n"
"    border-radius: 4px;\n"
"    padding: 8px;\n"
"    font-size: 10pt;\n"
"    min-height: 100px;\n"
"}\n"
"\n"
"/* Enhanced ComboBox drop-down arrow */\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 6px solid #546e7a;\n"
"    margin-right: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:hover {\n"
"    border-top-color: #1a7"
                        "3e8;\n"
"}\n"
"\n"
"/* DateEdit and TimeEdit drop-down arrows */\n"
"QDateEdit::down-arrow, QTimeEdit::down-arrow, QDateTimeEdit::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 6px solid #546e7a;\n"
"    margin-right: 4px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow:hover, QTimeEdit::down-arrow:hover, QDateTimeEdit::down-arrow:hover {\n"
"    border-top-color: #1a73e8;\n"
"}\n"
"\n"
"/* Make sure the arrows are properly aligned */\n"
"QSpinBox, QDoubleSpinBox, QDateEdit, QTimeEdit, QDateTimeEdit {\n"
"    padding-right: 20px;\n"
"}\n"
"\n"
"/* Remove the old calendar/clock icons if you prefer the new arrows */\n"
"QDateEdit::down-arrow[qproperty-text], QTimeEdit::down-arrow[qproperty-text] {\n"
"    qproperty-text: \"\";\n"
"}\n"
"\n"
"/* Tab widget styling */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-top: 0px;\n"
"    background-color: white;\n"
"    border-bottom-left-radius"
                        ": 4px;\n"
"    border-bottom-right-radius: 4px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f5f7fa;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-bottom: none;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    padding: 8px 12px;\n"
"    margin-right: 2px;\n"
"    font-size: 9.5pt;\n"
"    min-width: 80px;\n"
"    color: #546e7a;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom: 3px solid #1a73e8;\n"
"    color: #1a73e8;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #f0f0f0;\n"
"}\n"
"\n"
"/* Group box styling */\n"
"QGroupBox {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 5px;\n"
"    margin-top: 15px;\n"
"    padding-top: 15px;\n"
"    background-color: white;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;"
                        "\n"
"    padding: 0 8px;\n"
"    left: 10px;\n"
"    color: #263238;\n"
"    background-color: transparent;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* Fix text selection color for all inputs */\n"
"QLineEdit, QComboBox, QSpinBox, QDoubleSpinBox, QDateEdit, QTimeEdit, QDateTimeEdit, QTextEdit {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"    padding: 6px 8px;\n"
"    background-color: white;\n"
"    font-size: 9.5pt;\n"
"    selection-background-color: #1a73e8;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QLineEdit:hover, QComboBox:hover, QSpinBox:hover, QDoubleSpinBox:hover, QDateEdit:hover, QTimeEdit:hover, QDateTimeEdit:hover, QTextEdit:hover {\n"
"    border: 1px solid #bdbdbd;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus, QDateEdit:focus, QTimeEdit:focus, QDateTimeEdit:focus, QTextEdit:focus {\n"
"    border: 1px solid #1a73e8;\n"
"    background-color: white;\n"
"}\n"
"\n"
"/* Button styling */\n"
"QPushButton {\n"
"    background-color: #1"
                        "a73e8;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    padding: 6px 12px;\n"
"    min-width: 70px;\n"
"    font-size: 9.5pt;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1565c0;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #cfd8dc;\n"
"    color: #78909c;\n"
"}\n"
"\n"
"QPushButton.secondary {\n"
"    background-color: white;\n"
"    color: #1a73e8;\n"
"    border: 1px solid #1a73e8;\n"
"}\n"
"\n"
"QPushButton.secondary:hover {\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"QPushButton.danger, QPushButton#deleteButton, QPushButton#cancelButton {\n"
"    background-color: #d32f2f;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton.danger:hover, QPushButton#deleteButton:hover, QPushButton#cancelButton:hover {\n"
"    background-color: #c62828;\n"
"}\n"
"\n"
"QPushButton.success, QPushButton#saveButton, QPushButton#btnTrier {\n"
"    background-colo"
                        "r: #2e7d32;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton.success:hover, QPushButton#saveButton:hover, QPushButton#btnTrier:hover {\n"
"    background-color: #2e6b32;\n"
"}\n"
"\n"
"\n"
"/* Special handling for spinboxes with prefix (like $ sign) */\n"
"QDoubleSpinBox[prefix=\"$\"] {\n"
"    padding-right: 25px; /* Make room for the buttons */\n"
"    padding-left: 20px; /* More room for the prefix */\n"
"}\n"
"\n"
"/* Specific styles for the payment section spinboxes */\n"
"#depositSpinBox, #totalAmountSpinBox {\n"
"    min-height: 32px;\n"
"    padding-right: 25px;\n"
"    padding-left: 20px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* Handle read-only state specially but still show buttons */\n"
"QDoubleSpinBox[readOnly=\"true\"] {\n"
"    background-color: #f5f5f5;\n"
"    color: #455a64;\n"
"    border: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"QDoubleSpinBox[readOnly=\"true\"]::up-button,\n"
"QDoubleSpinBox[readOnly=\"true\"]::down-button {\n"
"    background-color: #ebebeb;\n"
"    border-left: 1px solid #d0d"
                        "0d0;\n"
"}\n"
"\n"
"/* Enhanced DateEdit and TimeEdit styling */\n"
"QDateEdit, QTimeEdit {\n"
"    padding-right: 25px; /* Make room for the dropdown button */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QDateEdit::drop-down, QTimeEdit::drop-down {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #e0e0e0;\n"
"    border-top-right-radius: 4px;\n"
"    border-bottom-right-radius: 4px;\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"QDateEdit::drop-down:hover, QTimeEdit::drop-down:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-left: 1px solid #1a73e8;\n"
"}\n"
"\n"
"QDateEdit::drop-down:pressed, QTimeEdit::drop-down:pressed {\n"
"    background-color: #bbdefb;\n"
"}\n"
"\n"
"/* Custom calendar icon for DateEdit - replaces image reference with a Unicode character */\n"
"QDateEdit::down-arrow {\n"
"    image: none;\n"
"    width: 25px;\n"
"    height: 25px;\n"
"    /* Use a QLabel with text for a calendar icon */\n"
"    f"
                        "ont-family: 'Segoe UI Symbol', sans-serif;\n"
"    color: #1a73e8;\n"
"    font-size: 13px;\n"
"    qproperty-text: \"\360\237\223\205\";\n"
"}\n"
"\n"
"/* Custom clock icon for TimeEdit - replaces image reference with a Unicode character */\n"
"QTimeEdit::down-arrow {\n"
"    image: none;\n"
"    width: 25px;\n"
"    height: 25px;\n"
"    /* Use a QLabel with text for a clock icon */\n"
"    font-family: 'Segoe UI Symbol', sans-serif;\n"
"    color: #1a73e8;\n"
"    font-size: 13px;\n"
"    qproperty-text: \"\360\237\225\222\";\n"
"}\n"
"\n"
"/* ComboBox styling */\n"
"QComboBox {\n"
"    padding-right: 20px; /* Space for the arrow */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: center right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #e0e0e0;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"QComboBox::drop-down:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
""
                        "\n"
"QComboBox::down-arrow {\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 6px solid transparent;\n"
"    border-right: 6px solid transparent;\n"
"    border-top: 6px solid #455a64;\n"
"    margin: 0 6px 0 0;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #e0e0e0;\n"
"    selection-background-color: #1a73e8;\n"
"    selection-color: white;\n"
"    background-color: white;\n"
"    outline: 0px;\n"
"}\n"
"\n"
"/* Calendar widget styling */\n"
"QCalendarWidget {\n"
"    background-color: white;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    color: #263238;\n"
"    background-color: transparent;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"    background-color: whit"
                        "e;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"    color: #263238;\n"
"    background-color: white;\n"
"    selection-background-color: #1a73e8;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QCalendarWidget QWidget { \n"
"    alternate-background-color: #f5f7fa;\n"
"}\n"
"\n"
"/* Scrollbar styling */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #f5f7fa;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #cfd8dc;\n"
"    min-height: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #b0bec5;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background: #f5f7fa;\n"
"    height: 10px;\n"
"    margin: 0px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #cfd8dc;\n"
"    min-"
                        "width: 30px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"    background: #b0bec5;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* Table View styling */\n"
"QTableView {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"    selection-background-color: #e3f2fd;\n"
"    selection-color: #263238;\n"
"    alternate-background-color: #f5f7fa;\n"
"}\n"
"\n"
"QHeaderView {\n"
"    border: none;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: white;\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #e0e0e0;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    font-size: 9.5pt;\n"
"    font-weight: 600;\n"
"    color: #263238;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background-color: #f5f7fa;\n"
"}\n"
"\n"
"/* "
                        "Label styling */\n"
"QLabel {\n"
"    font-size: 9.5pt;\n"
"    color: #37474f;\n"
"}\n"
"\n"
"QLabel#labelTitle, QLabel[labelTitle=\"true\"] {\n"
"    font-weight: 600;\n"
"    font-size: 14pt;\n"
"    color: #263238;\n"
"    margin-bottom: 10px;\n"
"}\n"
"\n"
"/* Form actions container */\n"
"#formActionsContainer {\n"
"    background-color: #f5f7fa;\n"
"    border-top: 1px solid #e0e0e0;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Progress Bar */\n"
"QProgressBar {\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    background-color: #f5f7fa;\n"
"    text-align: center;\n"
"    color: #263238;\n"
"    font-size: 9pt;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #1a73e8;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Specific styling for the color indicators in the calendar */\n"
"QFrame#fullyAvailableFrame {\n"
"    background-color: #90EE90;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"QFrame#partiallyAvailableFrame {\n"
"    background-color: #FFFF99;\n"
"    border-radius: 2px;\n"
"}\n"
""
                        "\n"
"QFrame#fullyBookedFrame {\n"
"    background-color: #e74c3c;\n"
"    border-radius: 2px;\n"
"}\n"
"\n"
"/* Special styling for the Add Reservation page */\n"
"#tab_add_reservation QGroupBox {\n"
"    margin-bottom: 15px;\n"
"}\n"
"\n"
"#tab_add_reservation QLineEdit, \n"
"#tab_add_reservation QComboBox,\n"
"#tab_add_reservation QSpinBox,\n"
"#tab_add_reservation QDoubleSpinBox,\n"
"#tab_add_reservation QDateEdit,\n"
"#tab_add_reservation QTimeEdit {\n"
"    height: 30px;\n"
"}\n"
"\n"
"/* Bottom buttons in Add Reservation */\n"
"#clearButton {\n"
"    background-color: #78909c;\n"
"    color: white;\n"
"}\n"
"\n"
"#clearButton:hover {\n"
"    background-color: #607d8b;\n"
"}\n"
"\n"
"#saveButton {\n"
"    background-color: #2e7d32;\n"
"    min-width: 120px;\n"
"}\n"
"\n"
"#cancelButton {\n"
"    background-color: #d32f2f;\n"
"}\n"
"\n"
"/* TextEdit for notes */\n"
"#notesTextEdit {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 4px;\n"
"    padding: 8px;\n"
"    min-height: 80px;\n"
"}\n"
"\n"
""
                        "/* Make the check availability button more prominent */\n"
"#checkAvailabilityButton {\n"
"    background-color: #1a73e8;\n"
"    font-weight: bold;\n"
"    min-width: 150px;\n"
"}\n"
"\n"
"/* Tooltips */\n"
"QToolTip {\n"
"    background-color: #263238;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 5px;\n"
"    border-radius: 4px;\n"
"    opacity: 220;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tab_reservations = new QWidget();
        tab_reservations->setObjectName("tab_reservations");
        verticalLayout_2 = new QVBoxLayout(tab_reservations);
        verticalLayout_2->setObjectName("verticalLayout_2");
        searchGroupBox = new QGroupBox(tab_reservations);
        searchGroupBox->setObjectName("searchGroupBox");
        verticalLayout_5 = new QVBoxLayout(searchGroupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(searchGroupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        searchTypeComboBox = new QComboBox(searchGroupBox);
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->addItem(QString());
        searchTypeComboBox->setObjectName("searchTypeComboBox");

        horizontalLayout->addWidget(searchTypeComboBox);

        searchLineEdit = new QLineEdit(searchGroupBox);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        dateRangeLabel = new QLabel(searchGroupBox);
        dateRangeLabel->setObjectName("dateRangeLabel");

        horizontalLayout->addWidget(dateRangeLabel);

        fromDateEdit = new QDateEdit(searchGroupBox);
        fromDateEdit->setObjectName("fromDateEdit");
        fromDateEdit->setCalendarPopup(true);
        fromDateEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(fromDateEdit);

        toLabel = new QLabel(searchGroupBox);
        toLabel->setObjectName("toLabel");
        toLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(toLabel);

        toDateEdit = new QDateEdit(searchGroupBox);
        toDateEdit->setObjectName("toDateEdit");
        toDateEdit->setCalendarPopup(true);
        toDateEdit->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(toDateEdit);

        searchButton = new QPushButton(searchGroupBox);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);

        resetButton = new QPushButton(searchGroupBox);
        resetButton->setObjectName("resetButton");

        horizontalLayout->addWidget(resetButton);


        verticalLayout_5->addLayout(horizontalLayout);

        advancedSearchLayout = new QHBoxLayout();
        advancedSearchLayout->setObjectName("advancedSearchLayout");
        advancedSearchCheckBox = new QCheckBox(searchGroupBox);
        advancedSearchCheckBox->setObjectName("advancedSearchCheckBox");

        advancedSearchLayout->addWidget(advancedSearchCheckBox);

        roomTypeLabel = new QLabel(searchGroupBox);
        roomTypeLabel->setObjectName("roomTypeLabel");

        advancedSearchLayout->addWidget(roomTypeLabel);

        roomTypeFilterComboBox = new QComboBox(searchGroupBox);
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->addItem(QString());
        roomTypeFilterComboBox->setObjectName("roomTypeFilterComboBox");

        advancedSearchLayout->addWidget(roomTypeFilterComboBox);

        statusFilterLabel = new QLabel(searchGroupBox);
        statusFilterLabel->setObjectName("statusFilterLabel");

        advancedSearchLayout->addWidget(statusFilterLabel);

        statusFilterComboBox = new QComboBox(searchGroupBox);
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->addItem(QString());
        statusFilterComboBox->setObjectName("statusFilterComboBox");

        advancedSearchLayout->addWidget(statusFilterComboBox);

        countryFilterLabel = new QLabel(searchGroupBox);
        countryFilterLabel->setObjectName("countryFilterLabel");

        advancedSearchLayout->addWidget(countryFilterLabel);

        countryFilterComboBox = new QComboBox(searchGroupBox);
        countryFilterComboBox->addItem(QString());
        countryFilterComboBox->setObjectName("countryFilterComboBox");
        countryFilterComboBox->setEditable(true);

        advancedSearchLayout->addWidget(countryFilterComboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        advancedSearchLayout->addItem(horizontalSpacer_3);

        sortButton = new QPushButton(searchGroupBox);
        sortButton->setObjectName("sortButton");

        advancedSearchLayout->addWidget(sortButton);

        addReservationButton = new QPushButton(searchGroupBox);
        addReservationButton->setObjectName("addReservationButton");

        advancedSearchLayout->addWidget(addReservationButton);


        verticalLayout_5->addLayout(advancedSearchLayout);


        verticalLayout_2->addWidget(searchGroupBox);

        mainSplitter = new QSplitter(tab_reservations);
        mainSplitter->setObjectName("mainSplitter");
        mainSplitter->setOrientation(Qt::Orientation::Vertical);
        reservationsTableView = new QTableView(mainSplitter);
        reservationsTableView->setObjectName("reservationsTableView");
        reservationsTableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        reservationsTableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        reservationsTableView->setSortingEnabled(true);
        mainSplitter->addWidget(reservationsTableView);
        buttonContainer = new QWidget(mainSplitter);
        buttonContainer->setObjectName("buttonContainer");
        buttonLayout = new QHBoxLayout(buttonContainer);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        modifyButton = new QPushButton(buttonContainer);
        modifyButton->setObjectName("modifyButton");

        buttonLayout->addWidget(modifyButton);

        deleteButton = new QPushButton(buttonContainer);
        deleteButton->setObjectName("deleteButton");

        buttonLayout->addWidget(deleteButton);

        mainSplitter->addWidget(buttonContainer);
        statsContainer = new QWidget(mainSplitter);
        statsContainer->setObjectName("statsContainer");
        statsLayout = new QVBoxLayout(statsContainer);
        statsLayout->setSpacing(8);
        statsLayout->setObjectName("statsLayout");
        statsLayout->setContentsMargins(10, 10, 10, 10);
        dashboardWidget = new QWidget(statsContainer);
        dashboardWidget->setObjectName("dashboardWidget");
        chartsLayout = new QHBoxLayout(dashboardWidget);
        chartsLayout->setSpacing(20);
        chartsLayout->setObjectName("chartsLayout");
        chartsLayout->setContentsMargins(0, 0, 0, 0);
        trafficChartFrame = new QFrame(dashboardWidget);
        trafficChartFrame->setObjectName("trafficChartFrame");
        trafficChartFrame->setFrameShape(QFrame::StyledPanel);
        trafficChartFrame->setFrameShadow(QFrame::Raised);
        trafficFrameLayout = new QVBoxLayout(trafficChartFrame);
        trafficFrameLayout->setObjectName("trafficFrameLayout");
        trafficTitle = new QLabel(trafficChartFrame);
        trafficTitle->setObjectName("trafficTitle");
        trafficTitle->setAlignment(Qt::AlignLeft|Qt::AlignTop);

        trafficFrameLayout->addWidget(trafficTitle);

        trafficChart = new QGraphicsView(trafficChartFrame);
        trafficChart->setObjectName("trafficChart");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(trafficChart->sizePolicy().hasHeightForWidth());
        trafficChart->setSizePolicy(sizePolicy);
        trafficChart->setMinimumSize(QSize(400, 200));

        trafficFrameLayout->addWidget(trafficChart);

        trafficLegendFrame = new QFrame(trafficChartFrame);
        trafficLegendFrame->setObjectName("trafficLegendFrame");
        trafficLegendFrame->setFrameShape(QFrame::NoFrame);
        trafficLegendLayout = new QHBoxLayout(trafficLegendFrame);
        trafficLegendLayout->setSpacing(15);
        trafficLegendLayout->setObjectName("trafficLegendLayout");
        trafficLegendLayout->setContentsMargins(0, 0, 0, 0);
        copilotLegend = new QFrame(trafficLegendFrame);
        copilotLegend->setObjectName("copilotLegend");
        copilotLegend->setFrameShape(QFrame::NoFrame);
        copilotLegendLayout = new QHBoxLayout(copilotLegend);
        copilotLegendLayout->setSpacing(5);
        copilotLegendLayout->setObjectName("copilotLegendLayout");
        copilotLegendLayout->setContentsMargins(0, 0, 0, 0);
        copilotColor = new QFrame(copilotLegend);
        copilotColor->setObjectName("copilotColor");
        copilotColor->setMinimumSize(QSize(12, 12));
        copilotColor->setMaximumSize(QSize(12, 12));

        copilotLegendLayout->addWidget(copilotColor);

        copilotText = new QLabel(copilotLegend);
        copilotText->setObjectName("copilotText");

        copilotLegendLayout->addWidget(copilotText);


        trafficLegendLayout->addWidget(copilotLegend);

        personalSiteLegend = new QFrame(trafficLegendFrame);
        personalSiteLegend->setObjectName("personalSiteLegend");
        personalSiteLegend->setFrameShape(QFrame::NoFrame);
        personalSiteLegendLayout = new QHBoxLayout(personalSiteLegend);
        personalSiteLegendLayout->setSpacing(5);
        personalSiteLegendLayout->setObjectName("personalSiteLegendLayout");
        personalSiteLegendLayout->setContentsMargins(0, 0, 0, 0);
        personalSiteColor = new QFrame(personalSiteLegend);
        personalSiteColor->setObjectName("personalSiteColor");
        personalSiteColor->setMinimumSize(QSize(12, 12));
        personalSiteColor->setMaximumSize(QSize(12, 12));

        personalSiteLegendLayout->addWidget(personalSiteColor);

        personalSiteText = new QLabel(personalSiteLegend);
        personalSiteText->setObjectName("personalSiteText");

        personalSiteLegendLayout->addWidget(personalSiteText);


        trafficLegendLayout->addWidget(personalSiteLegend);

        trafficLegendSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        trafficLegendLayout->addItem(trafficLegendSpacer);


        trafficFrameLayout->addWidget(trafficLegendFrame);


        chartsLayout->addWidget(trafficChartFrame);

        countryStatsFrame = new QFrame(dashboardWidget);
        countryStatsFrame->setObjectName("countryStatsFrame");
        countryStatsFrame->setFrameShape(QFrame::StyledPanel);
        countryStatsFrame->setFrameShadow(QFrame::Raised);
        countryStatsLayout = new QVBoxLayout(countryStatsFrame);
        countryStatsLayout->setObjectName("countryStatsLayout");
        countryStatsTitle = new QLabel(countryStatsFrame);
        countryStatsTitle->setObjectName("countryStatsTitle");
        countryStatsTitle->setAlignment(Qt::AlignLeft|Qt::AlignTop);

        countryStatsLayout->addWidget(countryStatsTitle);

        countryStatsTable = new QTableWidget(countryStatsFrame);
        countryStatsTable->setObjectName("countryStatsTable");
        countryStatsTable->setColumnCount(2);

        countryStatsLayout->addWidget(countryStatsTable);


        chartsLayout->addWidget(countryStatsFrame);

        languageChartFrame = new QFrame(dashboardWidget);
        languageChartFrame->setObjectName("languageChartFrame");
        languageChartFrame->setFrameShape(QFrame::StyledPanel);
        languageChartFrame->setFrameShadow(QFrame::Raised);
        languageFrameLayout = new QVBoxLayout(languageChartFrame);
        languageFrameLayout->setObjectName("languageFrameLayout");
        languageTitle = new QLabel(languageChartFrame);
        languageTitle->setObjectName("languageTitle");
        languageTitle->setAlignment(Qt::AlignLeft|Qt::AlignTop);

        languageFrameLayout->addWidget(languageTitle);

        languageChart = new QGraphicsView(languageChartFrame);
        languageChart->setObjectName("languageChart");
        sizePolicy.setHeightForWidth(languageChart->sizePolicy().hasHeightForWidth());
        languageChart->setSizePolicy(sizePolicy);
        languageChart->setMinimumSize(QSize(400, 200));

        languageFrameLayout->addWidget(languageChart);

        languageLegendFrame = new QFrame(languageChartFrame);
        languageLegendFrame->setObjectName("languageLegendFrame");
        languageLegendFrame->setFrameShape(QFrame::NoFrame);
        languageLegendLayout = new QHBoxLayout(languageLegendFrame);
        languageLegendLayout->setSpacing(15);
        languageLegendLayout->setObjectName("languageLegendLayout");
        languageLegendLayout->setContentsMargins(0, 0, 0, 0);
        htmlLegend = new QFrame(languageLegendFrame);
        htmlLegend->setObjectName("htmlLegend");
        htmlLegend->setFrameShape(QFrame::NoFrame);
        htmlLegendLayout = new QHBoxLayout(htmlLegend);
        htmlLegendLayout->setSpacing(5);
        htmlLegendLayout->setObjectName("htmlLegendLayout");
        htmlLegendLayout->setContentsMargins(0, 0, 0, 0);
        htmlColor = new QFrame(htmlLegend);
        htmlColor->setObjectName("htmlColor");
        htmlColor->setMinimumSize(QSize(12, 12));
        htmlColor->setMaximumSize(QSize(12, 12));

        htmlLegendLayout->addWidget(htmlColor);

        htmlText = new QLabel(htmlLegend);
        htmlText->setObjectName("htmlText");

        htmlLegendLayout->addWidget(htmlText);


        languageLegendLayout->addWidget(htmlLegend);

        javascriptLegend = new QFrame(languageLegendFrame);
        javascriptLegend->setObjectName("javascriptLegend");
        javascriptLegend->setFrameShape(QFrame::NoFrame);
        javascriptLegendLayout = new QHBoxLayout(javascriptLegend);
        javascriptLegendLayout->setSpacing(5);
        javascriptLegendLayout->setObjectName("javascriptLegendLayout");
        javascriptLegendLayout->setContentsMargins(0, 0, 0, 0);
        javascriptColor = new QFrame(javascriptLegend);
        javascriptColor->setObjectName("javascriptColor");
        javascriptColor->setMinimumSize(QSize(12, 12));
        javascriptColor->setMaximumSize(QSize(12, 12));

        javascriptLegendLayout->addWidget(javascriptColor);

        javascriptText = new QLabel(javascriptLegend);
        javascriptText->setObjectName("javascriptText");

        javascriptLegendLayout->addWidget(javascriptText);


        languageLegendLayout->addWidget(javascriptLegend);

        cssLegend = new QFrame(languageLegendFrame);
        cssLegend->setObjectName("cssLegend");
        cssLegend->setFrameShape(QFrame::NoFrame);
        cssLegendLayout = new QHBoxLayout(cssLegend);
        cssLegendLayout->setSpacing(5);
        cssLegendLayout->setObjectName("cssLegendLayout");
        cssLegendLayout->setContentsMargins(0, 0, 0, 0);
        cssColor = new QFrame(cssLegend);
        cssColor->setObjectName("cssColor");
        cssColor->setMinimumSize(QSize(12, 12));
        cssColor->setMaximumSize(QSize(12, 12));

        cssLegendLayout->addWidget(cssColor);

        cssText = new QLabel(cssLegend);
        cssText->setObjectName("cssText");

        cssLegendLayout->addWidget(cssText);


        languageLegendLayout->addWidget(cssLegend);

        languageLegendSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        languageLegendLayout->addItem(languageLegendSpacer);


        languageFrameLayout->addWidget(languageLegendFrame);


        chartsLayout->addWidget(languageChartFrame);


        statsLayout->addWidget(dashboardWidget);

        proTipLabel = new QLabel(statsContainer);
        proTipLabel->setObjectName("proTipLabel");
        proTipLabel->setAlignment(Qt::AlignCenter);

        statsLayout->addWidget(proTipLabel);

        mainSplitter->addWidget(statsContainer);

        verticalLayout_2->addWidget(mainSplitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(tab_reservations);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        selectedReservationLabel = new QLabel(tab_reservations);
        selectedReservationLabel->setObjectName("selectedReservationLabel");

        horizontalLayout_2->addWidget(selectedReservationLabel);

        horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer1);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_reservations, QString());
        tab_calendar = new QWidget();
        tab_calendar->setObjectName("tab_calendar");
        verticalLayout_3 = new QVBoxLayout(tab_calendar);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        prevMonthButton = new QPushButton(tab_calendar);
        prevMonthButton->setObjectName("prevMonthButton");
        prevMonthButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(prevMonthButton);

        monthYearLabel = new QLabel(tab_calendar);
        monthYearLabel->setObjectName("monthYearLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        monthYearLabel->setFont(font);
        monthYearLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(monthYearLabel);

        nextMonthButton = new QPushButton(tab_calendar);
        nextMonthButton->setObjectName("nextMonthButton");
        nextMonthButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(nextMonthButton);

        todayButton = new QPushButton(tab_calendar);
        todayButton->setObjectName("todayButton");

        horizontalLayout_3->addWidget(todayButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        filterLayout = new QHBoxLayout();
        filterLayout->setObjectName("filterLayout");
        roomTypeLabel1 = new QLabel(tab_calendar);
        roomTypeLabel1->setObjectName("roomTypeLabel1");

        filterLayout->addWidget(roomTypeLabel1);

        roomTypeFilterComboBox1 = new QComboBox(tab_calendar);
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->addItem(QString());
        roomTypeFilterComboBox1->setObjectName("roomTypeFilterComboBox1");
        roomTypeFilterComboBox1->setMinimumWidth(150);

        filterLayout->addWidget(roomTypeFilterComboBox1);

        minRoomsLabel = new QLabel(tab_calendar);
        minRoomsLabel->setObjectName("minRoomsLabel");

        filterLayout->addWidget(minRoomsLabel);

        minRoomsSpinBox = new QSpinBox(tab_calendar);
        minRoomsSpinBox->setObjectName("minRoomsSpinBox");
        minRoomsSpinBox->setMinimum(1);
        minRoomsSpinBox->setMaximum(20);
        minRoomsSpinBox->setValue(1);

        filterLayout->addWidget(minRoomsSpinBox);

        applyFilterButton = new QPushButton(tab_calendar);
        applyFilterButton->setObjectName("applyFilterButton");

        filterLayout->addWidget(applyFilterButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        filterLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(filterLayout);

        legendLayout = new QHBoxLayout();
        legendLayout->setObjectName("legendLayout");
        legendLabel = new QLabel(tab_calendar);
        legendLabel->setObjectName("legendLabel");

        legendLayout->addWidget(legendLabel);

        fullyAvailableFrame = new QFrame(tab_calendar);
        fullyAvailableFrame->setObjectName("fullyAvailableFrame");
        fullyAvailableFrame->setMinimumSize(QSize(20, 20));
        fullyAvailableFrame->setMaximumSize(QSize(20, 20));
        fullyAvailableFrame->setFrameShape(QFrame::Box);

        legendLayout->addWidget(fullyAvailableFrame);

        fullyAvailableLabel = new QLabel(tab_calendar);
        fullyAvailableLabel->setObjectName("fullyAvailableLabel");

        legendLayout->addWidget(fullyAvailableLabel);

        partiallyAvailableFrame = new QFrame(tab_calendar);
        partiallyAvailableFrame->setObjectName("partiallyAvailableFrame");
        partiallyAvailableFrame->setMinimumSize(QSize(20, 20));
        partiallyAvailableFrame->setMaximumSize(QSize(20, 20));
        partiallyAvailableFrame->setFrameShape(QFrame::Box);

        legendLayout->addWidget(partiallyAvailableFrame);

        partiallyAvailableLabel = new QLabel(tab_calendar);
        partiallyAvailableLabel->setObjectName("partiallyAvailableLabel");

        legendLayout->addWidget(partiallyAvailableLabel);

        fullyBookedFrame = new QFrame(tab_calendar);
        fullyBookedFrame->setObjectName("fullyBookedFrame");
        fullyBookedFrame->setMinimumSize(QSize(20, 20));
        fullyBookedFrame->setMaximumSize(QSize(20, 20));
        fullyBookedFrame->setFrameShape(QFrame::Box);

        legendLayout->addWidget(fullyBookedFrame);

        fullyBookedLabel = new QLabel(tab_calendar);
        fullyBookedLabel->setObjectName("fullyBookedLabel");

        legendLayout->addWidget(fullyBookedLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        legendLayout->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(legendLayout);

        calendarWidget = new QCalendarWidget(tab_calendar);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setMinimumSize(QSize(0, 300));
        calendarWidget->setStyleSheet(QString::fromUtf8("\n"
"\n"
"/* The cell dates will be colored programmatically */\n"
""));
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::LongDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(false);
        calendarWidget->setDateEditEnabled(false);

        verticalLayout_3->addWidget(calendarWidget);

        tabWidget->addTab(tab_calendar, QString());
        tab_add_reservation = new QWidget();
        tab_add_reservation->setObjectName("tab_add_reservation");
        verticalLayout_6 = new QVBoxLayout(tab_add_reservation);
        verticalLayout_6->setObjectName("verticalLayout_6");
        scrollArea = new QScrollArea(tab_add_reservation);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 858, 500));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_7->setObjectName("verticalLayout_7");
        clientGroupBox = new QGroupBox(scrollAreaWidgetContents);
        clientGroupBox->setObjectName("clientGroupBox");
        clientLayout = new QHBoxLayout(clientGroupBox);
        clientLayout->setObjectName("clientLayout");
        clientSearchLabel = new QLabel(clientGroupBox);
        clientSearchLabel->setObjectName("clientSearchLabel");

        clientLayout->addWidget(clientSearchLabel);

        clientComboBox = new QComboBox(clientGroupBox);
        clientComboBox->setObjectName("clientComboBox");
        clientComboBox->setMinimumSize(QSize(300, 0));
        clientComboBox->setEditable(true);

        clientLayout->addWidget(clientComboBox);

        searchClientButton = new QPushButton(clientGroupBox);
        searchClientButton->setObjectName("searchClientButton");

        clientLayout->addWidget(searchClientButton);


        verticalLayout_7->addWidget(clientGroupBox);

        roomDetailsGroupBox = new QGroupBox(scrollAreaWidgetContents);
        roomDetailsGroupBox->setObjectName("roomDetailsGroupBox");
        gridLayout_2 = new QGridLayout(roomDetailsGroupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        roomTypeLabel_2 = new QLabel(roomDetailsGroupBox);
        roomTypeLabel_2->setObjectName("roomTypeLabel_2");

        gridLayout_2->addWidget(roomTypeLabel_2, 0, 0, 1, 1);

        roomTypeComboBox = new QComboBox(roomDetailsGroupBox);
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->setObjectName("roomTypeComboBox");

        gridLayout_2->addWidget(roomTypeComboBox, 0, 1, 1, 1);

        availableRoomsLabel = new QLabel(roomDetailsGroupBox);
        availableRoomsLabel->setObjectName("availableRoomsLabel");

        gridLayout_2->addWidget(availableRoomsLabel, 1, 0, 1, 1);

        roomNumberComboBox = new QComboBox(roomDetailsGroupBox);
        roomNumberComboBox->setObjectName("roomNumberComboBox");

        gridLayout_2->addWidget(roomNumberComboBox, 1, 1, 1, 1);

        rateLabel = new QLabel(roomDetailsGroupBox);
        rateLabel->setObjectName("rateLabel");

        gridLayout_2->addWidget(rateLabel, 2, 0, 1, 1);

        rateSpinBox = new QDoubleSpinBox(roomDetailsGroupBox);
        rateSpinBox->setObjectName("rateSpinBox");
        rateSpinBox->setMaximum(9999.989999999999782);
        rateSpinBox->setValue(149.990000000000009);

        gridLayout_2->addWidget(rateSpinBox, 2, 1, 1, 1);

        checkAvailabilityButton = new QPushButton(roomDetailsGroupBox);
        checkAvailabilityButton->setObjectName("checkAvailabilityButton");

        gridLayout_2->addWidget(checkAvailabilityButton, 0, 2, 1, 1);

        roomDetailsLabel = new QLabel(roomDetailsGroupBox);
        roomDetailsLabel->setObjectName("roomDetailsLabel");

        gridLayout_2->addWidget(roomDetailsLabel, 1, 2, 1, 1);


        verticalLayout_7->addWidget(roomDetailsGroupBox);

        stayDetailsGroupBox = new QGroupBox(scrollAreaWidgetContents);
        stayDetailsGroupBox->setObjectName("stayDetailsGroupBox");
        gridLayout_3 = new QGridLayout(stayDetailsGroupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        checkInLabel = new QLabel(stayDetailsGroupBox);
        checkInLabel->setObjectName("checkInLabel");

        gridLayout_3->addWidget(checkInLabel, 0, 0, 1, 1);

        checkInDateEdit = new QDateEdit(stayDetailsGroupBox);
        checkInDateEdit->setObjectName("checkInDateEdit");
        checkInDateEdit->setMinimumSize(QSize(150, 0));
        checkInDateEdit->setCalendarPopup(true);

        gridLayout_3->addWidget(checkInDateEdit, 0, 1, 1, 1);

        checkInTimeLabel = new QLabel(stayDetailsGroupBox);
        checkInTimeLabel->setObjectName("checkInTimeLabel");

        gridLayout_3->addWidget(checkInTimeLabel, 0, 2, 1, 1);

        checkInTimeEdit = new QTimeEdit(stayDetailsGroupBox);
        checkInTimeEdit->setObjectName("checkInTimeEdit");
        checkInTimeEdit->setTime(QTime(14, 0, 0));

        gridLayout_3->addWidget(checkInTimeEdit, 0, 3, 1, 1);

        checkOutLabel = new QLabel(stayDetailsGroupBox);
        checkOutLabel->setObjectName("checkOutLabel");

        gridLayout_3->addWidget(checkOutLabel, 1, 0, 1, 1);

        checkOutDateEdit = new QDateEdit(stayDetailsGroupBox);
        checkOutDateEdit->setObjectName("checkOutDateEdit");
        checkOutDateEdit->setMinimumSize(QSize(150, 0));
        checkOutDateEdit->setCalendarPopup(true);

        gridLayout_3->addWidget(checkOutDateEdit, 1, 1, 1, 1);

        checkOutTimeLabel = new QLabel(stayDetailsGroupBox);
        checkOutTimeLabel->setObjectName("checkOutTimeLabel");

        gridLayout_3->addWidget(checkOutTimeLabel, 1, 2, 1, 1);

        checkOutTimeEdit = new QTimeEdit(stayDetailsGroupBox);
        checkOutTimeEdit->setObjectName("checkOutTimeEdit");
        checkOutTimeEdit->setTime(QTime(11, 0, 0));

        gridLayout_3->addWidget(checkOutTimeEdit, 1, 3, 1, 1);

        nightsLabel = new QLabel(stayDetailsGroupBox);
        nightsLabel->setObjectName("nightsLabel");

        gridLayout_3->addWidget(nightsLabel, 2, 0, 1, 1);

        nightsSpinBox = new QSpinBox(stayDetailsGroupBox);
        nightsSpinBox->setObjectName("nightsSpinBox");
        nightsSpinBox->setMinimum(1);
        nightsSpinBox->setMaximum(365);

        gridLayout_3->addWidget(nightsSpinBox, 2, 1, 1, 1);

        adultsLabel = new QLabel(stayDetailsGroupBox);
        adultsLabel->setObjectName("adultsLabel");

        gridLayout_3->addWidget(adultsLabel, 3, 0, 1, 1);

        adultsSpinBox = new QSpinBox(stayDetailsGroupBox);
        adultsSpinBox->setObjectName("adultsSpinBox");
        adultsSpinBox->setMinimum(1);
        adultsSpinBox->setMaximum(10);
        adultsSpinBox->setValue(1);

        gridLayout_3->addWidget(adultsSpinBox, 3, 1, 1, 1);

        childrenLabel = new QLabel(stayDetailsGroupBox);
        childrenLabel->setObjectName("childrenLabel");

        gridLayout_3->addWidget(childrenLabel, 3, 2, 1, 1);

        childrenSpinBox = new QSpinBox(stayDetailsGroupBox);
        childrenSpinBox->setObjectName("childrenSpinBox");
        childrenSpinBox->setMaximum(10);

        gridLayout_3->addWidget(childrenSpinBox, 3, 3, 1, 1);


        verticalLayout_7->addWidget(stayDetailsGroupBox);

        paymentDetailsGroupBox = new QGroupBox(scrollAreaWidgetContents);
        paymentDetailsGroupBox->setObjectName("paymentDetailsGroupBox");
        gridLayout_4 = new QGridLayout(paymentDetailsGroupBox);
        gridLayout_4->setObjectName("gridLayout_4");
        paymentMethodLabel = new QLabel(paymentDetailsGroupBox);
        paymentMethodLabel->setObjectName("paymentMethodLabel");

        gridLayout_4->addWidget(paymentMethodLabel, 0, 0, 1, 1);

        paymentMethodComboBox = new QComboBox(paymentDetailsGroupBox);
        paymentMethodComboBox->addItem(QString());
        paymentMethodComboBox->addItem(QString());
        paymentMethodComboBox->addItem(QString());
        paymentMethodComboBox->addItem(QString());
        paymentMethodComboBox->addItem(QString());
        paymentMethodComboBox->setObjectName("paymentMethodComboBox");

        gridLayout_4->addWidget(paymentMethodComboBox, 0, 1, 1, 1);

        depositLabel = new QLabel(paymentDetailsGroupBox);
        depositLabel->setObjectName("depositLabel");

        gridLayout_4->addWidget(depositLabel, 1, 0, 1, 1);

        depositSpinBox = new QDoubleSpinBox(paymentDetailsGroupBox);
        depositSpinBox->setObjectName("depositSpinBox");
        depositSpinBox->setMaximum(9999.989999999999782);

        gridLayout_4->addWidget(depositSpinBox, 1, 1, 1, 1);

        totalAmountLabel = new QLabel(paymentDetailsGroupBox);
        totalAmountLabel->setObjectName("totalAmountLabel");

        gridLayout_4->addWidget(totalAmountLabel, 2, 0, 1, 1);

        totalAmountSpinBox = new QDoubleSpinBox(paymentDetailsGroupBox);
        totalAmountSpinBox->setObjectName("totalAmountSpinBox");
        totalAmountSpinBox->setMaximum(99999.990000000005239);
        totalAmountSpinBox->setReadOnly(true);

        gridLayout_4->addWidget(totalAmountSpinBox, 2, 1, 1, 1);

        statusLabel = new QLabel(paymentDetailsGroupBox);
        statusLabel->setObjectName("statusLabel");

        gridLayout_4->addWidget(statusLabel, 3, 0, 1, 1);

        statusComboBox = new QComboBox(paymentDetailsGroupBox);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");

        gridLayout_4->addWidget(statusComboBox, 3, 1, 1, 1);


        verticalLayout_7->addWidget(paymentDetailsGroupBox);

        notesGroupBox = new QGroupBox(scrollAreaWidgetContents);
        notesGroupBox->setObjectName("notesGroupBox");
        verticalLayout_8 = new QVBoxLayout(notesGroupBox);
        verticalLayout_8->setObjectName("verticalLayout_8");
        notesTextEdit = new QTextEdit(notesGroupBox);
        notesTextEdit->setObjectName("notesTextEdit");

        verticalLayout_8->addWidget(notesTextEdit);


        verticalLayout_7->addWidget(notesGroupBox);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(scrollArea);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_41 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_41);

        clearButton = new QPushButton(tab_add_reservation);
        clearButton->setObjectName("clearButton");

        horizontalLayout_5->addWidget(clearButton);

        saveButton = new QPushButton(tab_add_reservation);
        saveButton->setObjectName("saveButton");
        saveButton->setMinimumSize(QSize(120, 0));

        horizontalLayout_5->addWidget(saveButton);

        cancelButton = new QPushButton(tab_add_reservation);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_5->addWidget(cancelButton);


        verticalLayout_6->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab_add_reservation, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 44));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuReservation = new QMenu(menubar);
        menuReservation->setObjectName("menuReservation");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuService = new QMenu(menubar);
        menuService->setObjectName("menuService");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuReservation->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuService->menuAction());
        menuFile->addSeparator();
        menuFile->addSeparator();
        menuReservation->addSeparator();
        menuReservation->addSeparator();
        menuView->addSeparator();
        menuService->addSeparator();
        toolBar->addSeparator();
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Hotel Reservation System", nullptr));
        searchGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Search Reservations", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Search by:", nullptr));
        searchTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "All Fields", nullptr));
        searchTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Reservation ID", nullptr));
        searchTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Guest Name", nullptr));
        searchTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Room Number", nullptr));
        searchTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Country", nullptr));
        searchTypeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Phone", nullptr));
        searchTypeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Email", nullptr));
        searchTypeComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Check-in Date", nullptr));
        searchTypeComboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Check-out Date", nullptr));
        searchTypeComboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Status", nullptr));

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter search terms...", nullptr));
        dateRangeLabel->setText(QCoreApplication::translate("MainWindow", "Date Range:", nullptr));
        toLabel->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        advancedSearchCheckBox->setText(QCoreApplication::translate("MainWindow", "Advanced Search", nullptr));
        roomTypeLabel->setText(QCoreApplication::translate("MainWindow", "Room Type:", nullptr));
        roomTypeFilterComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "All Types", nullptr));
        roomTypeFilterComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Standard Single", nullptr));
        roomTypeFilterComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Standard Double", nullptr));
        roomTypeFilterComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Deluxe King", nullptr));
        roomTypeFilterComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Deluxe Double", nullptr));
        roomTypeFilterComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Junior Suite", nullptr));
        roomTypeFilterComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Executive Suite", nullptr));
        roomTypeFilterComboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Presidential Suite", nullptr));

        statusFilterLabel->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        statusFilterComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "All Statuses", nullptr));
        statusFilterComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Confirmed", nullptr));
        statusFilterComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Pending", nullptr));
        statusFilterComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Checked-in", nullptr));
        statusFilterComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Completed", nullptr));
        statusFilterComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Cancelled", nullptr));

        countryFilterLabel->setText(QCoreApplication::translate("MainWindow", "Country:", nullptr));
        countryFilterComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "All Countries", nullptr));

        sortButton->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        addReservationButton->setText(QCoreApplication::translate("MainWindow", "Add Reservation", nullptr));
        modifyButton->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        trafficChartFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                  QFrame {\n"
"                    background-color: white;\n"
"                    border-radius: 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                  }\n"
"                ", nullptr));
        trafficTitle->setText(QCoreApplication::translate("MainWindow", "Web Traffic Overview", nullptr));
        trafficTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        font-weight: bold;\n"
"                        font-size: 12pt;\n"
"                        border: none;\n"
"                      ", nullptr));
        trafficChart->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        background-color: white;\n"
"                        border: none;\n"
"                      ", nullptr));
        trafficLegendFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "border: none;", nullptr));
        copilotColor->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    background-color: #4e73df;\n"
"                                    border-radius: 2px;\n"
"                                  ", nullptr));
        copilotText->setText(QCoreApplication::translate("MainWindow", "CoPilot", nullptr));
        copilotText->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    font-size: 9pt;\n"
"                                  ", nullptr));
        personalSiteColor->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    background-color: #1cc88a;\n"
"                                    border-radius: 2px;\n"
"                                  ", nullptr));
        personalSiteText->setText(QCoreApplication::translate("MainWindow", "Personal Site", nullptr));
        personalSiteText->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    font-size: 9pt;\n"
"                                  ", nullptr));
        countryStatsFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        QFrame {\n"
"          background-color: white;\n"
"          border-radius: 8px;\n"
"          border: 1px solid #e0e0e0;\n"
"        }\n"
"      ", nullptr));
        countryStatsTitle->setText(QCoreApplication::translate("MainWindow", "Visitor Location Statistics", nullptr));
        countryStatsTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              font-weight: bold;\n"
"              font-size: 12pt;\n"
"              border: none;\n"
"            ", nullptr));
        countryStatsTable->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("MainWindow", "Country", nullptr),
            QCoreApplication::translate("MainWindow", "Percentage", nullptr)});
        countryStatsTable->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"              QTableWidget {\n"
"                background-color: white;\n"
"                border: none;\n"
"              }\n"
"              QHeaderView::section {\n"
"                background-color: #f8f9fc;\n"
"                padding: 4px;\n"
"                border: 1px solid #e0e0e0;\n"
"                font-weight: bold;\n"
"              }\n"
"            ", nullptr));
        languageChartFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                  QFrame {\n"
"                    background-color: white;\n"
"                    border-radius: 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                  }\n"
"                ", nullptr));
        languageTitle->setText(QCoreApplication::translate("MainWindow", "Language Overview", nullptr));
        languageTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        font-weight: bold;\n"
"                        font-size: 12pt;\n"
"                        border: none;\n"
"                      ", nullptr));
        languageChart->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                        background-color: white;\n"
"                        border: none;\n"
"                      ", nullptr));
        languageLegendFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "border: none;", nullptr));
        htmlColor->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    background-color: #1cc88a;\n"
"                                    border-radius: 2px;\n"
"                                  ", nullptr));
        htmlText->setText(QCoreApplication::translate("MainWindow", "HTML", nullptr));
        htmlText->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    font-size: 9pt;\n"
"                                  ", nullptr));
        javascriptColor->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    background-color: #f6c23e;\n"
"                                    border-radius: 2px;\n"
"                                  ", nullptr));
        javascriptText->setText(QCoreApplication::translate("MainWindow", "JavaScript", nullptr));
        javascriptText->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    font-size: 9pt;\n"
"                                  ", nullptr));
        cssColor->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    background-color: #36b9cc;\n"
"                                    border-radius: 2px;\n"
"                                  ", nullptr));
        cssText->setText(QCoreApplication::translate("MainWindow", "CSS", nullptr));
        cssText->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                                    font-size: 9pt;\n"
"                                  ", nullptr));
        proTipLabel->setText(QCoreApplication::translate("MainWindow", "Pro Tip: Don't forget to star us on github!", nullptr));
        proTipLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"            font-size: 9pt;\n"
"            color: #6c757d;\n"
"          ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Selected Reservation:", nullptr));
        selectedReservationLabel->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_reservations), QCoreApplication::translate("MainWindow", "Reservations", nullptr));
        prevMonthButton->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        monthYearLabel->setText(QCoreApplication::translate("MainWindow", "April 2025", nullptr));
        nextMonthButton->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        todayButton->setText(QCoreApplication::translate("MainWindow", "Today", nullptr));
        roomTypeLabel1->setText(QCoreApplication::translate("MainWindow", "Room Type:", nullptr));
        roomTypeFilterComboBox1->setItemText(0, QCoreApplication::translate("MainWindow", "All Room Types", nullptr));
        roomTypeFilterComboBox1->setItemText(1, QCoreApplication::translate("MainWindow", "Standard Single", nullptr));
        roomTypeFilterComboBox1->setItemText(2, QCoreApplication::translate("MainWindow", "Standard Double", nullptr));
        roomTypeFilterComboBox1->setItemText(3, QCoreApplication::translate("MainWindow", "Deluxe King", nullptr));
        roomTypeFilterComboBox1->setItemText(4, QCoreApplication::translate("MainWindow", "Deluxe Double", nullptr));
        roomTypeFilterComboBox1->setItemText(5, QCoreApplication::translate("MainWindow", "Junior Suite", nullptr));
        roomTypeFilterComboBox1->setItemText(6, QCoreApplication::translate("MainWindow", "Executive Suite", nullptr));
        roomTypeFilterComboBox1->setItemText(7, QCoreApplication::translate("MainWindow", "Presidential Suite", nullptr));

        minRoomsLabel->setText(QCoreApplication::translate("MainWindow", "Min. Available Rooms:", nullptr));
        applyFilterButton->setText(QCoreApplication::translate("MainWindow", "Apply Filter", nullptr));
        legendLabel->setText(QCoreApplication::translate("MainWindow", "Legend:", nullptr));
        fullyAvailableFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #90EE90;", nullptr));
        fullyAvailableLabel->setText(QCoreApplication::translate("MainWindow", "Many Available", nullptr));
        partiallyAvailableFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #FFFF99;", nullptr));
        partiallyAvailableLabel->setText(QCoreApplication::translate("MainWindow", "Limited Availability", nullptr));
        fullyBookedFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #e74c3c;", nullptr));
        fullyBookedLabel->setText(QCoreApplication::translate("MainWindow", "Fully Booked", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_calendar), QCoreApplication::translate("MainWindow", "Calendar View", nullptr));
        clientGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Client Selection", nullptr));
        clientSearchLabel->setText(QCoreApplication::translate("MainWindow", "Search Client:", nullptr));
        clientComboBox->setPlaceholderText(QCoreApplication::translate("MainWindow", "Type name to search clients...", nullptr));
        searchClientButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        roomDetailsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Room Details", nullptr));
        roomTypeLabel_2->setText(QCoreApplication::translate("MainWindow", "Room Type:", nullptr));
        roomTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Standard Single", nullptr));
        roomTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Standard Double", nullptr));
        roomTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Deluxe King", nullptr));
        roomTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Deluxe Double", nullptr));
        roomTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Junior Suite", nullptr));
        roomTypeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Executive Suite", nullptr));
        roomTypeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Presidential Suite", nullptr));

        availableRoomsLabel->setText(QCoreApplication::translate("MainWindow", "Available Rooms:", nullptr));
        rateLabel->setText(QCoreApplication::translate("MainWindow", "Room Rate:", nullptr));
        rateSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "$", nullptr));
        checkAvailabilityButton->setText(QCoreApplication::translate("MainWindow", "Check Availability", nullptr));
        roomDetailsLabel->setText(QCoreApplication::translate("MainWindow", "Room Details", nullptr));
        stayDetailsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Stay Details", nullptr));
        checkInLabel->setText(QCoreApplication::translate("MainWindow", "Check-in Date:", nullptr));
        checkInTimeLabel->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        checkOutLabel->setText(QCoreApplication::translate("MainWindow", "Check-out Date:", nullptr));
        checkOutTimeLabel->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        nightsLabel->setText(QCoreApplication::translate("MainWindow", "Number of Nights:", nullptr));
        adultsLabel->setText(QCoreApplication::translate("MainWindow", "Adults:", nullptr));
        childrenLabel->setText(QCoreApplication::translate("MainWindow", "Children:", nullptr));
        paymentDetailsGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Payment Details", nullptr));
        paymentMethodLabel->setText(QCoreApplication::translate("MainWindow", "Payment Method:", nullptr));
        paymentMethodComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Credit Card", nullptr));
        paymentMethodComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Debit Card", nullptr));
        paymentMethodComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Cash", nullptr));
        paymentMethodComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Bank Transfer", nullptr));
        paymentMethodComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Third-party Booking", nullptr));

        depositLabel->setText(QCoreApplication::translate("MainWindow", "Deposit Amount:", nullptr));
        depositSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "$", nullptr));
        totalAmountLabel->setText(QCoreApplication::translate("MainWindow", "Total Amount:", nullptr));
        totalAmountSpinBox->setPrefix(QCoreApplication::translate("MainWindow", "$", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Reservation Status:", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Confirmed", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Pending", nullptr));

        notesGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Additional Notes", nullptr));
        notesTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter any special requests or additional information here...", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear Form", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save Reservation", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_add_reservation), QCoreApplication::translate("MainWindow", "Add Reservation", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Client", nullptr));
        menuReservation->setTitle(QCoreApplication::translate("MainWindow", "Employe", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "Room", nullptr));
        menuService->setTitle(QCoreApplication::translate("MainWindow", "Service", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Invoice", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
