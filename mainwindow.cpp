#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include "reservationModel.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QTableView>
#include <QHeaderView>
#include <QDate>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHeaderView>
#include <qpdfwriter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupSidebar();
    // Create and set up the reservation model
    m_reservationModel = new ReservationModel(this);

    connect(m_reservationModel, &ReservationModel::dataChanged, this, &MainWindow::onReservationDataChanged);

    // Setup UI elements
    setupReservationsTab();
    setupDashboard();

    // Set window title
    setWindowTitle("Hotel Management System");
}

MainWindow::~MainWindow()
{
    delete ui;
    m_currentYearSeries = nullptr;
    m_previousYearSeries = nullptr;
    m_statusSeries = nullptr;
    m_reservationChart = nullptr;
    m_statusChart = nullptr;
    m_countryStatsTableView = nullptr;
    m_reservationYAxis = nullptr;
}

void MainWindow::onReservationDataChanged()
{
    // Update dashboard with the new data
    updateDashboard();
}

void MainWindow::setupSidebar() {
    // Get the central widget and its layout
    QWidget* centralWidget = this->centralWidget();
    QVBoxLayout* mainLayout = qobject_cast<QVBoxLayout*>(centralWidget->layout());

    // Create a new horizontal layout to hold the sidebar and the existing content
    QHBoxLayout* horizontalLayout = new QHBoxLayout();

    // Create the sidebar frame
    QFrame* sidebar = new QFrame(centralWidget);
    sidebar->setObjectName("sidebar");
    sidebar->setFixedWidth(180);  // Width to match image
    sidebar->setStyleSheet("background-color: #1e2b38;"); // Dark blue background

    // Create the sidebar layout
    QVBoxLayout* sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setSpacing(8); // Space between items
    sidebarLayout->setContentsMargins(15, 15, 15, 15); // Margins around items

    // Add logo space at the top
    QFrame* logoFrame = new QFrame(sidebar);
    logoFrame->setFixedHeight(80); // Adjust height as needed for your logo
    logoFrame->setStyleSheet("background-color: transparent;");
    QHBoxLayout* logoLayout = new QHBoxLayout(logoFrame);
    logoLayout->setContentsMargins(0, 0, 0, 0);

    // Add a placeholder for the logo (you can replace this with your actual logo)
    QLabel* logoLabel = new QLabel(logoFrame);
    logoLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setStyleSheet("color: white; font-size: 16pt; font-weight: bold;");
    logoLabel->setText("LOGO"); // Replace with your actual logo using setPixmap()
    logoLayout->addWidget(logoLabel);

    // Add logo frame to sidebar
    sidebarLayout->addWidget(logoFrame);

    // Add some spacing between logo and menu items
    sidebarLayout->addSpacing(345);

    // Add sidebar items
    struct MenuOption {
        QString name;
        QString iconSymbol;
        bool highlighted; // Whether button is highlighted blue or plain text
    };

    QList<MenuOption> menuItems = {
        {"Clients", "\uf0c0", true},       // Font Awesome users icon
        {"Reservation", "\uf073", true},   // Font Awesome calendar icon
        {"Employee", "\uf007", true},      // Font Awesome user icon
        {"Rooms", "\uf236", true},         // Font Awesome bed icon
        {"Services", "\uf0ad", true},      // Font Awesome wrench icon
        {"Invoice", "\uf15c", true},       // Font Awesome file/document icon
        {"Statistics", "    \uf080", false}, // Font Awesome chart/bar-chart icon
        {"Export", "    \uf1c3", false}    // Font Awesome file-export/print icon
    };

    QWidget* exportWidget = nullptr; // Keep track of the export widget/button
    foreach(const MenuOption& item, menuItems) {
        // Create either a button (for highlighted items) or a label (for non-highlighted items)
        if (item.highlighted) {
            QPushButton* menuButton = new QPushButton(sidebar);

            // Set up button layout with icon and text
            QHBoxLayout* buttonLayout = new QHBoxLayout(menuButton);
            buttonLayout->setContentsMargins(10, 0, 0, 0);
            buttonLayout->setSpacing(8);

            // Add icon
            QLabel* iconLabel = new QLabel(menuButton);
            iconLabel->setText(item.iconSymbol);
            iconLabel->setStyleSheet("color: white; background: transparent;");
            buttonLayout->addWidget(iconLabel);

            // Add text
            QLabel* textLabel = new QLabel(item.name, menuButton);
            textLabel->setStyleSheet("color: white; background: transparent;");
            buttonLayout->addWidget(textLabel);
            buttonLayout->addStretch();

            // Style the button
            menuButton->setStyleSheet(
                "QPushButton {"
                "    background-color: #0078d7;" // Bright blue color
                "    border-radius: 4px;"
                "    color: white;"
                "    padding: 8px 8px;"
                "    text-align: left;"
                "    border: none;"
                "}"
                "QPushButton:hover {"
                "    background-color: #0086f0;" // Slightly lighter blue for hover
                "}"
                );
            menuButton->setFixedHeight(36); // Match button height in image
            sidebarLayout->addWidget(menuButton);
        } else {
            QWidget* menuItem = new QWidget(sidebar);
            menuItem->setObjectName("menu_" + item.name.toLower());
            QHBoxLayout* itemLayout = new QHBoxLayout(menuItem);
            itemLayout->setContentsMargins(10, 8, 10, 8);
            itemLayout->setSpacing(8);

            QLabel* iconLabel = new QLabel(menuItem);
            iconLabel->setText(item.iconSymbol);
            iconLabel->setStyleSheet("color: white;");

            QLabel* textLabel = new QLabel(item.name, menuItem);
            textLabel->setStyleSheet("color: white;");

            itemLayout->addWidget(iconLabel);
            itemLayout->addWidget(textLabel);
            itemLayout->addStretch();

            sidebarLayout->addWidget(menuItem);

            // Save reference to the export widget if this is it
            if (item.name == "Export") {
                exportWidget = menuItem;

                // Make it clickable
                menuItem->setCursor(Qt::PointingHandCursor);
                menuItem->setStyleSheet("QWidget:hover { background-color: #2d3e50; }");
            }
        }
    }

    // Connect the Export widget to the exportToPdf slot
    if (exportWidget) {
        exportWidget->installEventFilter(this);
    }


    sidebarLayout->addStretch(); // Push all items to the top

    // Create content container for the existing widgets
    QFrame* contentContainer = new QFrame(centralWidget);
    contentContainer->setObjectName("contentContainer");

    // Take the tab widget out of the main layout
    QTabWidget* tabWidget = findChild<QTabWidget*>("tabWidget");
    if (tabWidget) {
        mainLayout->removeWidget(tabWidget);
    }

    // Create a layout for the content container
    QVBoxLayout* contentLayout = new QVBoxLayout(contentContainer);
    contentLayout->setContentsMargins(0, 0, 0, 0);

    // Add the tabWidget to the content layout if it exists
    if (tabWidget) {
        contentLayout->addWidget(tabWidget);
    }

    // Add sidebar and content container to the horizontal layout
    horizontalLayout->addWidget(sidebar);
    horizontalLayout->addWidget(contentContainer, 1); // Give content area stretch priority
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout->setSpacing(0);

    // Clear the original layout and add our new horizontal layout
    QLayoutItem* item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item;
    }
    mainLayout->addLayout(horizontalLayout);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // Check if this is a click on the Export widget
    if (obj->objectName() == "menu_export" && event->type() == QEvent::MouseButtonPress) {
        // Call our export function
        exportToPdf();
        return true; // Event handled
    }

    // Standard event processing
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::exportToPdf()
{
    // Get the file name and path from the user
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export to PDF"),
                                                    QDir::homePath() + "/hotel_export.pdf",
                                                    tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    // Create a PDF writer
    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMarginsF(30, 30, 30, 30));

    // Create a painter to paint on the PDF writer
    QPainter painter(&pdfWriter);

    // Get the current tab widget and active tab
    QTabWidget* tabWidget = findChild<QTabWidget*>("tabWidget");
    if (!tabWidget) {
        QMessageBox::warning(this, tr("Export Error"),
                             tr("Cannot find the tab widget to export."));
        return;
    }

    QWidget* currentTab = tabWidget->currentWidget();
    if (!currentTab) {
        QMessageBox::warning(this, tr("Export Error"),
                             tr("No active tab to export."));
        return;
    }

    // Add a header with the hotel name and current date
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(QRect(0, 0, pdfWriter.width(), 100),
                     Qt::AlignHCenter | Qt::AlignTop,
                     tr("Hotel Management System"));

    // Add current date
    painter.setFont(QFont("Arial", 10));
    painter.drawText(QRect(0, 50, pdfWriter.width(), 100),
                     Qt::AlignHCenter | Qt::AlignTop,
                     QDate::currentDate().toString("yyyy-MM-dd"));

    // Add the tab name as a subheader
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.drawText(QRect(0, 100, pdfWriter.width(), 100),
                     Qt::AlignHCenter | Qt::AlignTop,
                     tabWidget->tabText(tabWidget->currentIndex()));

    // Create a smaller scaled area for the content
    painter.translate(0, 150);  // Move down past the headers

    // Determine the scale factor to fit the content on the page
    double scaleFactorW = pdfWriter.width() / static_cast<double>(currentTab->width());
    double scaleFactorH = (pdfWriter.height() - 150) / static_cast<double>(currentTab->height());
    double scaleFactor = qMin(scaleFactorW, scaleFactorH);

    // Scale the painter to fit the content
    painter.scale(scaleFactor, scaleFactor);

    // Render the current tab
    currentTab->render(&painter);

    // End painting
    painter.end();

    // Show a success message
    QMessageBox::information(this, tr("Export Successful"),
                             tr("The current view has been exported to PDF successfully!"));
}

void MainWindow::setupTableViewAppearance(QTableView *tableView)
{
    // Customize table view appearance
    tableView->horizontalHeader()->setStretchLastSection(false);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    // Optional: Set selection behavior
    tableView->setSelectionMode(QAbstractItemView::NoSelection);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Style the header to match other charts
    tableView->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "    background-color: #f8f9fc;"
        "    padding: 4px;"
        "    border: 1px solid #e0e0e0;"
        "    font-weight: bold;"
        "}"
        );

    // Set alternate row colors for better readability
    tableView->setAlternatingRowColors(true);
    tableView->setStyleSheet(
        "QTableView {"
        "    alternate-background-color: #f8f9fc;"
        "    background-color: white;"
        "}"
        );
}

void MainWindow::setupCountryStatsTable(QTableView *tableView)
{
    // Create standard model for the table
    QStandardItemModel *model = new QStandardItemModel(0, 2, this);

    // Set header labels
    model->setHorizontalHeaderLabels({"Country", "Percentage"});

    // Get all reservations from the model
    const QList<Reservation> &allReservations = m_reservationModel->reservations();

    // Count reservations by country
    QMap<QString, int> countryCounts;
    int totalReservations = allReservations.size();

    // If there are no reservations, display a message with better formatting
    if (totalReservations == 0) {
        QStandardItem *noDataItem = new QStandardItem("No reservation data available");
        QStandardItem *emptyItem = new QStandardItem("");

        // Style the "no data" message
        QFont boldFont;
        boldFont.setBold(true);
        noDataItem->setFont(boldFont);
        noDataItem->setForeground(QBrush(QColor("#6c757d")));

        model->appendRow({noDataItem, emptyItem});

        // Set the model to the table view
        tableView->setModel(model);
        setupTableViewAppearance(tableView);
        return;
    }

    // Count reservations by country
    for (const Reservation &reservation : allReservations) {
        QString country = reservation.country();
        countryCounts[country]++;
    }

    // If no real data exists, use sample data
    if (countryCounts.isEmpty()) {
        // Create sample data that matches the style of your charts
        countryCounts["United States"] = 45;
        countryCounts["Canada"] = 25;
        countryCounts["United Kingdom"] = 15;
        countryCounts["Germany"] = 10;
        countryCounts["France"] = 8;
        countryCounts["Japan"] = 7;
        countryCounts["Australia"] = 6;

        totalReservations = 0;
        for (auto count : countryCounts.values()) {
            totalReservations += count;
        }
    }

    // Convert to a list of pairs for sorting
    QList<QPair<QString, int>> countryList;
    QMapIterator<QString, int> i(countryCounts);
    while (i.hasNext()) {
        i.next();
        countryList.append(qMakePair(i.key(), i.value()));
    }

    // Sort by count in descending order
    std::sort(countryList.begin(), countryList.end(),
              [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
                  return a.second > b.second;
              });

    // Take top 5 countries (or fewer if less are available)
    int numCountriesToShow = qMin(5, countryList.size());
    int otherCount = 0;

    // Color list to match the pie chart colors
    QList<QColor> colorList = {
        QColor("#4e73df"),  // Blue
        QColor("#1cc88a"),  // Green
        QColor("#f6c23e"),  // Yellow
        QColor("#36b9cc"),  // Cyan
        QColor("#e74a3b")   // Red
    };

    // Calculate percentages and add to model
    for (int i = 0; i < countryList.size(); ++i) {
        if (i < numCountriesToShow) {
            // For top countries, add them individually
            QString country = countryList[i].first;
            int count = countryList[i].second;
            double percentage = static_cast<double>(count) / totalReservations * 100.0;

            QStandardItem *countryItem = new QStandardItem(country);
            QStandardItem *percentageItem = new QStandardItem(QString("%1%").arg(percentage, 0, 'f', 1));

            // Add color indicator to match chart style
            if (i < colorList.size()) {
                countryItem->setData(colorList[i], Qt::DecorationRole);
            }

            // Formatting
            countryItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            percentageItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

            // Make the top country bold
            if (i == 0) {
                QFont boldFont;
                boldFont.setBold(true);
                countryItem->setFont(boldFont);
                percentageItem->setFont(boldFont);
            }

            model->appendRow({countryItem, percentageItem});
        } else {
            // Count all other countries together
            otherCount += countryList[i].second;
        }
    }

    // If there are other countries, add an "Other" row
    if (otherCount > 0) {
        double percentage = static_cast<double>(otherCount) / totalReservations * 100.0;

        QStandardItem *countryItem = new QStandardItem("Other");
        QStandardItem *percentageItem = new QStandardItem(QString("%1%").arg(percentage, 0, 'f', 1));

        // Style the "Other" row differently
        countryItem->setData(QColor("#858796"), Qt::DecorationRole);
        countryItem->setForeground(QBrush(QColor("#858796")));
        percentageItem->setForeground(QBrush(QColor("#858796")));

        countryItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        percentageItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        model->appendRow({countryItem, percentageItem});
    }

    // Add a title to the table
    QHeaderView* headerView = tableView->horizontalHeader();
    headerView->setVisible(true);

    // Style the table title to match chart titles
    headerView->setStyleSheet(
        "QHeaderView::section {"
        "    background-color: #f8f9fc;"
        "    color: #5a5c69;"
        "    font-weight: bold;"
        "    padding: 8px 4px;"
        "    border: 1px solid #e0e0e0;"
        "    border-bottom: 2px solid #dddfeb;"
        "}"
        );

    // Set the model to the table view
    tableView->setModel(model);

    // Set up appearance to match the new chart style
    tableView->setFrameShape(QFrame::Box);
    tableView->setFrameShadow(QFrame::Plain);
    tableView->setStyleSheet(
        "QTableView {"
        "    alternate-background-color: #f8f9fc;"
        "    background-color: white;"
        "    border: 1px solid #e3e6f0;"
        "    border-radius: 5px;"
        "}"
        "QTableView::item {"
        "    padding: 6px 4px;"
        "    border-bottom: 1px solid #e3e6f0;"
        "}"
        );

    // Set selection style
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::NoSelection);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set alternating row colors for better readability
    tableView->setAlternatingRowColors(true);

    // Set proper column widths
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

    // Add a title label above the table
    QLabel* titleLabel = new QLabel("Guest Origin Distribution", tableView->parentWidget());
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font-size: 11pt; "
        "font-weight: bold; "
        "color: #5a5c69; "
        "padding-bottom: 5px;"
        );

    // Find the layout of the parent and add the title
    if (tableView->parentWidget() && tableView->parentWidget()->layout()) {
        QBoxLayout* parentLayout = qobject_cast<QBoxLayout*>(tableView->parentWidget()->layout());
        if (parentLayout) {
            // Find the index of the table view in the layout
            int index = parentLayout->indexOf(tableView);
            if (index != -1) {
                // Insert the title before the table
                parentLayout->insertWidget(index, titleLabel);
            }
        }
    }
}


void MainWindow::setupDashboard()
{
    // Create line chart for Reservation Volume
    m_currentYearSeries = new QLineSeries();
    m_previousYearSeries = new QLineSeries();

    // Set names and appearance
    QDate currentDate = QDate::currentDate();
    int currentYear = currentDate.year();
    int previousYear = currentYear - 1;

    m_currentYearSeries->setName(QString("%1").arg(currentYear));
    m_previousYearSeries->setName(QString("%1").arg(previousYear));

    QPen currentYearPen(QColor("#4e73df"));
    currentYearPen.setWidth(2);
    m_currentYearSeries->setPen(currentYearPen);

    QPen prevYearPen(QColor("#1cc88a"));
    prevYearPen.setWidth(2);
    m_previousYearSeries->setPen(prevYearPen);

    // Create chart and add series
    m_reservationChart = new QChart();
    m_reservationChart->addSeries(m_currentYearSeries);
    m_reservationChart->addSeries(m_previousYearSeries);
    m_reservationChart->setTitle("Monthly Reservation Volume");
    m_reservationChart->legend()->setVisible(true);
    m_reservationChart->legend()->setAlignment(Qt::AlignBottom);

    // Set up axes
    QDateTime startTime(QDate(currentYear, 1, 1), QTime(0, 0));
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MMM");
    axisX->setTickCount(12);
    axisX->setRange(startTime, startTime.addMonths(11));
    axisX->setTitleText("Month");

    m_reservationYAxis = new QValueAxis;
    m_reservationYAxis->setRange(0, 100); // Will be updated in updateDashboardData
    m_reservationYAxis->setLabelFormat("%d");
    m_reservationYAxis->setTitleText("Number of Reservations");

    m_reservationChart->addAxis(axisX, Qt::AlignBottom);
    m_reservationChart->addAxis(m_reservationYAxis, Qt::AlignLeft);

    m_currentYearSeries->attachAxis(axisX);
    m_currentYearSeries->attachAxis(m_reservationYAxis);
    m_previousYearSeries->attachAxis(axisX);
    m_previousYearSeries->attachAxis(m_reservationYAxis);

    // Create chart view
    QChartView *reservationChartView = new QChartView(m_reservationChart);
    reservationChartView->setRenderHint(QPainter::Antialiasing);

    // Create pie chart for reservation status
    m_statusSeries = new QPieSeries();

    // Create status chart
    m_statusChart = new QChart();
    m_statusChart->addSeries(m_statusSeries);
    m_statusChart->setTitle("Reservation Status");
    m_statusChart->legend()->setVisible(true);
    m_statusChart->legend()->setAlignment(Qt::AlignBottom);

    // Create status chart view
    QChartView *statusChartView = new QChartView(m_statusChart);
    statusChartView->setRenderHint(QPainter::Antialiasing);

    // Create country stats table view
    m_countryStatsTableView = new QTableView();
    m_countryStatsTableView->setObjectName("countryStatsTableView");

    // Set up dashboard layout
    QHBoxLayout *chartsLayout = new QHBoxLayout();
    chartsLayout->addWidget(reservationChartView);
    chartsLayout->addWidget(m_countryStatsTableView);
    chartsLayout->addWidget(statusChartView);

    QVBoxLayout *dashboardLayout = new QVBoxLayout();
    dashboardLayout->addLayout(chartsLayout);

    // Add the pro tip
    QLabel *proTipLabel = new QLabel("Pro Tip: Increase direct bookings by offering special rates on your website!");
    proTipLabel->setAlignment(Qt::AlignCenter);
    proTipLabel->setStyleSheet("font-size: 9pt; color: #6c757d;");
    dashboardLayout->addWidget(proTipLabel);

    // Find the dashboard container in your UI
    QWidget *statsContainer = ui->statsContainer;
    if (statsContainer) {
        // Clear any existing layout
        if (statsContainer->layout()) {
            QLayoutItem *item;
            while ((item = statsContainer->layout()->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            delete statsContainer->layout();
        }
        statsContainer->setLayout(dashboardLayout);
    }

    // Now populate the charts with data
    updateDashboard();
}


void MainWindow::updateDashboard()
{
    if (!m_currentYearSeries || !m_previousYearSeries || !m_statusSeries || !m_countryStatsTableView) {
        // Charts haven't been initialized yet, nothing to update
        return;
    }

    // Get the reservation data
    const QList<Reservation> &allReservations = m_reservationModel->reservations();

    // Get current year and previous year
    QDate currentDate = QDate::currentDate();
    int currentYear = currentDate.year();
    int previousYear = currentYear - 1;

    // Initialize data
    QVector<int> currentYearData(12, 0);
    QVector<int> previousYearData(12, 0);

    // Count reservations by month if we have real data
    if (!allReservations.isEmpty()) {
        for (const Reservation &reservation : allReservations) {
            QDate checkInDate = reservation.checkInDate();
            int year = checkInDate.year();
            int month = checkInDate.month() - 1; // 0-based index

            if (year == currentYear && month >= 0 && month < 12) {
                currentYearData[month]++;
            } else if (year == previousYear && month >= 0 && month < 12) {
                previousYearData[month]++;
            }
        }
    } else {
        // Sample data if no reservations exist
        currentYearData = {42, 58, 69, 74, 83, 95, 86, 79, 88, 64, 72, 68};
        previousYearData = {38, 52, 61, 68, 75, 82, 78, 73, 80, 59, 67, 63};
    }

    // Update line chart series
    m_currentYearSeries->clear();
    m_previousYearSeries->clear();

    QDateTime startTime(QDate(currentYear, 1, 1), QTime(0, 0));
    QDateTime prevYearStartTime(QDate(previousYear, 1, 1), QTime(0, 0));

    for (int month = 0; month < 12; ++month) {
        QDateTime currentYearTime = startTime.addMonths(month);
        QDateTime prevYearTime = prevYearStartTime.addMonths(month);

        qint64 currentTimestamp = currentYearTime.toMSecsSinceEpoch();
        qint64 prevTimestamp = prevYearTime.toMSecsSinceEpoch();

        m_currentYearSeries->append(currentTimestamp, currentYearData[month]);
        m_previousYearSeries->append(prevTimestamp, previousYearData[month]);
    }

    // Update Y-axis range
    int maxValue = 100;
    for (int val : currentYearData) maxValue = qMax(maxValue, val);
    for (int val : previousYearData) maxValue = qMax(maxValue, val);
    m_reservationYAxis->setRange(0, maxValue * 1.1); // Add 10% headroom

    // Update status pie chart data
    m_statusSeries->clear();

    // Count reservations by status
    int pendingCount = 0;
    int confirmedCount = 0;
    int checkedInCount = 0;
    int completedCount = 0;
    int cancelledCount = 0;

    // If we have real data, use it
    if (!allReservations.isEmpty()) {
        for (const Reservation &reservation : allReservations) {
            switch (reservation.status()) {
            case Reservation::Pending: pendingCount++; break;
            case Reservation::Confirmed: confirmedCount++; break;
            case Reservation::CheckedIn: checkedInCount++; break;
            case Reservation::Completed: completedCount++; break;
            case Reservation::Cancelled: cancelledCount++; break;
            }
        }
    } else {
        // Sample data if no reservations exist
        pendingCount = 12;
        confirmedCount = 45;
        checkedInCount = 18;
        completedCount = 25;
        cancelledCount = 8;
    }

    // Add data to pie chart only if value > 0
    if (pendingCount > 0) m_statusSeries->append("Pending", pendingCount);
    if (confirmedCount > 0) m_statusSeries->append("Confirmed", confirmedCount);
    if (checkedInCount > 0) m_statusSeries->append("Checked In", checkedInCount);
    if (completedCount > 0) m_statusSeries->append("Completed", completedCount);
    if (cancelledCount > 0) m_statusSeries->append("Cancelled", cancelledCount);

    // Set colors for pie slices
    if (m_statusSeries->count() > 0) {
        int index = 0;
        if (pendingCount > 0) {
            m_statusSeries->slices().at(index)->setBrush(QColor("#f6c23e")); // Yellow
            m_statusSeries->slices().at(index)->setExploded(true);
            m_statusSeries->slices().at(index)->setLabelVisible(true);
            index++;
        }
        if (confirmedCount > 0) {
            m_statusSeries->slices().at(index)->setBrush(QColor("#4e73df")); // Blue
            m_statusSeries->slices().at(index)->setLabelVisible(true);
            index++;
        }
        if (checkedInCount > 0) {
            m_statusSeries->slices().at(index)->setBrush(QColor("#1cc88a")); // Green
            m_statusSeries->slices().at(index)->setLabelVisible(true);
            index++;
        }
        if (completedCount > 0) {
            m_statusSeries->slices().at(index)->setBrush(QColor("#36b9cc")); // Cyan
            m_statusSeries->slices().at(index)->setLabelVisible(true);
            index++;
        }
        if (cancelledCount > 0) {
            m_statusSeries->slices().at(index)->setBrush(QColor("#e74a3b")); // Red
            m_statusSeries->slices().at(index)->setLabelVisible(true);
        }
    }

    // Update country stats table
    setupCountryStatsTable(m_countryStatsTableView);
}
void MainWindow::setupReservationsTab()
{
    // Set the model for the table view
    ui->reservationsTableView->setModel(m_reservationModel);

    // Configure the table view
    ui->reservationsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->reservationsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->reservationsTableView->setSortingEnabled(true);
    ui->reservationsTableView->horizontalHeader()->setStretchLastSection(true);

    // Set column widths
    ui->reservationsTableView->setColumnWidth(ReservationModel::IdColumn, 60);
    ui->reservationsTableView->setColumnWidth(ReservationModel::GuestNameColumn, 150);
    ui->reservationsTableView->setColumnWidth(ReservationModel::RoomNumberColumn, 70);
    ui->reservationsTableView->setColumnWidth(ReservationModel::RoomTypeColumn, 120);
    ui->reservationsTableView->setColumnWidth(ReservationModel::CountryColumn, 100);
    ui->reservationsTableView->setColumnWidth(ReservationModel::PhoneColumn, 120);
    ui->reservationsTableView->setColumnWidth(ReservationModel::EmailColumn, 180);
    ui->reservationsTableView->setColumnWidth(ReservationModel::CheckInDateColumn, 100);
    ui->reservationsTableView->setColumnWidth(ReservationModel::CheckOutDateColumn, 100);
    ui->reservationsTableView->setColumnWidth(ReservationModel::StatusColumn, 100);

    // Initialize date pickers
    QDate today = QDate::currentDate();
    ui->fromDateEdit->setDate(today);
    ui->toDateEdit->setDate(today.addDays(30));

    ui->checkInDateEdit->setDate(today);
    ui->checkOutDateEdit->setDate(today.addDays(1));

    // Initially hide the date range controls
    ui->dateRangeLabel->setVisible(false);
    ui->fromDateEdit->setVisible(false);
    ui->toLabel->setVisible(false);
    ui->toDateEdit->setVisible(false);

    // IMPORTANT - Disconnect any existing connections first to avoid duplicate connections
    // that could cause the dialog issues and restart problems

    // Disconnect existing signals if any exist
    ui->searchTypeComboBox->disconnect();
    ui->searchButton->disconnect();
    ui->resetButton->disconnect();
    ui->addReservationButton->disconnect();
    ui->advancedSearchCheckBox->disconnect();
    ui->modifyButton->disconnect();
    ui->deleteButton->disconnect();
    ui->saveButton->disconnect();
    ui->cancelButton->disconnect();
    ui->clearButton->disconnect();
    ui->checkAvailabilityButton->disconnect();
    ui->checkInDateEdit->disconnect();
    ui->checkOutDateEdit->disconnect();
    ui->nightsSpinBox->disconnect();
    ui->roomTypeComboBox->disconnect();

    // Now connect signals/slots
    connect(ui->searchTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_searchTypeComboBox_currentIndexChanged);

    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
    // Connect buttons to slots
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::on_resetButton_clicked);
    connect(ui->addReservationButton, &QPushButton::clicked, this, &MainWindow::on_addReservationButton_clicked);
    connect(ui->advancedSearchCheckBox, &QCheckBox::toggled, this, &MainWindow::on_advancedSearchCheckBox_toggled);
    connect(ui->modifyButton, &QPushButton::clicked, this, &MainWindow::on_modifyButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);

    // Connect the form buttons in the Add Reservation tab
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &MainWindow::on_cancelButton_clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
    connect(ui->checkAvailabilityButton, &QPushButton::clicked, this, &MainWindow::on_checkAvailabilityButton_clicked);

    // Connect date and night changes
    connect(ui->checkInDateEdit, &QDateEdit::dateChanged, this, &MainWindow::on_checkInDateEdit_dateChanged);
    connect(ui->checkOutDateEdit, &QDateEdit::dateChanged, this, &MainWindow::on_checkOutDateEdit_dateChanged);
    connect(ui->nightsSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::on_nightsSpinBox_valueChanged);
    connect(ui->roomTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_roomTypeComboBox_currentIndexChanged);

    // Update button state based on selection changes
    connect(ui->reservationsTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this](const QItemSelection &selected, const QItemSelection &deselected) {
                bool hasSelection = !selected.isEmpty();
                ui->modifyButton->setEnabled(hasSelection);
                ui->deleteButton->setEnabled(hasSelection);
            });

    // Initially disable modify and delete buttons
    ui->modifyButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);

    // Initially hide advanced search options
    ui->roomTypeLabel->setVisible(false);
    ui->roomTypeFilterComboBox->setVisible(false);
    ui->statusFilterLabel->setVisible(false);
    ui->statusFilterComboBox->setVisible(false);
    ui->countryFilterLabel->setVisible(false);
    ui->countryFilterComboBox->setVisible(false);

    // Populate country combo box
    populateCountryComboBox();
}

void MainWindow::populateCountryComboBox()
{
    //QStringList countries = Reservation::getCountryList();
    ui->countryFilterComboBox->clear();
    ui->countryFilterComboBox->addItem("All Countries");
    //ui->countryFilterComboBox->addItems(countries);
}

void MainWindow::on_searchTypeComboBox_currentIndexChanged(int index)
{
    // Show date range controls for check-in or check-out date searches
    bool showDateRange = (index == 7 || index == 8);  // Check-in Date or Check-out Date
    ui->dateRangeLabel->setVisible(showDateRange);
    ui->fromDateEdit->setVisible(showDateRange);
    ui->toLabel->setVisible(showDateRange);
    ui->toDateEdit->setVisible(showDateRange);
}

void MainWindow::on_advancedSearchCheckBox_toggled(bool checked)
{
    // Show/hide advanced search options
    ui->roomTypeLabel->setVisible(checked);
    ui->roomTypeFilterComboBox->setVisible(checked);
    ui->statusFilterLabel->setVisible(checked);
    ui->statusFilterComboBox->setVisible(checked);
    ui->countryFilterLabel->setVisible(checked);
    ui->countryFilterComboBox->setVisible(checked);
}

void MainWindow::on_sortButton_clicked()
{
    // Sort the reservation data by name
    m_reservationModel->sortByName();

    // Show a temporary status message
    statusBar()->showMessage(tr("Reservations sorted by guest name"), 2000);
}


void MainWindow::on_searchButton_clicked()
{
    QString searchText = ui->searchLineEdit->text();
    int searchType = ui->searchTypeComboBox->currentIndex();
    QDate fromDate = ui->fromDateEdit->date();
    QDate toDate = ui->toDateEdit->date();

    // Get advanced search parameters if enabled
    QString roomType = "All Types";
    QString status = "All Statuses";
    QString country = "All Countries";

    if (ui->advancedSearchCheckBox->isChecked()) {
        roomType = ui->roomTypeFilterComboBox->currentText();
        status = ui->statusFilterComboBox->currentText();
        country = ui->countryFilterComboBox->currentText();
    }

    // Use the model's filter function
    m_reservationModel->filterReservations(searchText, searchType, fromDate, toDate,
                                           roomType, status, country);
}

void MainWindow::on_resetButton_clicked()
{
    // Clear search text
    ui->searchLineEdit->clear();

    // Reset date range
    QDate today = QDate::currentDate();
    ui->fromDateEdit->setDate(today);
    ui->toDateEdit->setDate(today.addDays(30));

    // Reset advanced search options
    ui->advancedSearchCheckBox->setChecked(false);
    ui->roomTypeFilterComboBox->setCurrentIndex(0);
    ui->statusFilterComboBox->setCurrentIndex(0);
    ui->countryFilterComboBox->setCurrentIndex(0);

    // Reset search type
    ui->searchTypeComboBox->setCurrentIndex(0);

    // Reset the filter
    m_reservationModel->resetFilter();
}

int MainWindow::getNextReservationId()
{
    // Find the highest ID and increment it by 1
    int maxId = 1000; // Start from 1000 if no reservations exist

    const QList<Reservation> &allReservations = m_reservationModel->reservations();
    for (const Reservation &reservation : allReservations) {
        if (reservation.id() > maxId) {
            maxId = reservation.id();
        }
    }

    return maxId + 1;
}

void MainWindow::showInfoMessage(const QString &title, const QString &message)
{
    // Process pending events before showing message box
    QApplication::processEvents();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Set window flags to ensure it stays on top and gets focus
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint);
    msgBox.setWindowModality(Qt::ApplicationModal);

    // Process events again to ensure UI is up to date
    QApplication::processEvents();

    // Execute dialog
    msgBox.exec();
}

void MainWindow::showWarningMessage(const QString &title, const QString &message)
{
    // Process pending events before showing message box
    QApplication::processEvents();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    // Set window flags to ensure it stays on top and gets focus
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint);
    msgBox.setWindowModality(Qt::ApplicationModal);

    // Process events again to ensure UI is up to date
    QApplication::processEvents();

    // Execute dialog
    msgBox.exec();
}

bool MainWindow::showConfirmationMessage(const QString &title, const QString &message)
{
    // Process pending events before showing message box
    QApplication::processEvents();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    // Set window flags to ensure it stays on top and gets focus
    msgBox.setWindowFlags(msgBox.windowFlags() | Qt::WindowStaysOnTopHint);
    msgBox.setWindowModality(Qt::ApplicationModal);

    // Process events again to ensure UI is up to date
    QApplication::processEvents();

    // Return true if user clicked Yes
    return (msgBox.exec() == QMessageBox::Yes);
}

void MainWindow::on_addReservationButton_clicked()
{
    // Clear any existing data in the form
    clearReservationForm();

    // Switch to the Add Reservation tab
    ui->tabWidget->setCurrentWidget(ui->tab_add_reservation);

    // Set default values for new reservation
    ui->checkInDateEdit->setDate(QDate::currentDate().addDays(1));
    ui->checkOutDateEdit->setDate(QDate::currentDate().addDays(4));

    // Generate a new reservation ID
    m_currentReservationId = getNextReservationId();

    // Set window title to indicate we're adding a new reservation
    ui->tab_add_reservation->setWindowTitle("Add New Reservation");
}

void MainWindow::on_reservationsTableView_cellDoubleClicked(int row, int column)
{
    // Get the reservation ID from the selected row
    QModelIndex index = m_reservationModel->index(row, ReservationModel::IdColumn);
    if (!index.isValid())
        return;

    int id = m_reservationModel->data(index, Qt::DisplayRole).toInt();

    showInfoMessage(tr("Reservation Selected"),
                    tr("Reservation has been Selected double click to Edit it."));

    // Call edit function
    editReservation(id);
}

void MainWindow::on_modifyButton_clicked()
{
    // Get the currently selected row
    QModelIndex currentIndex = ui->reservationsTableView->selectionModel()->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, tr("No Selection"),
                             tr("Please select a reservation to modify."));
        return;
    }

    // Get the reservation ID from the first column
    QModelIndex idIndex = m_reservationModel->index(currentIndex.row(), ReservationModel::IdColumn);
    if (!idIndex.isValid())
        return;

    int id = m_reservationModel->data(idIndex, Qt::DisplayRole).toInt();

    // Call the edit function with this ID
    editReservation(id);
}

void MainWindow::on_deleteButton_clicked()
{
    // Get the currently selected row
    QModelIndex currentIndex = ui->reservationsTableView->selectionModel()->currentIndex();
    if (!currentIndex.isValid()) {
        showWarningMessage(tr("No Selection"), tr("Please select a reservation to delete."));
        return;
    }

    // Get the reservation ID and name from the model
    QModelIndex idIndex = m_reservationModel->index(currentIndex.row(), ReservationModel::IdColumn);
    QModelIndex nameIndex = m_reservationModel->index(currentIndex.row(), ReservationModel::GuestNameColumn);
    if (!idIndex.isValid() || !nameIndex.isValid())
        return;

    int id = m_reservationModel->data(idIndex, Qt::DisplayRole).toInt();
    QString guestName = m_reservationModel->data(nameIndex, Qt::DisplayRole).toString();

    // Use improved confirmation dialog
    bool confirmed = showConfirmationMessage(
        tr("Confirm Deletion"),
        tr("Are you sure you want to delete the reservation for %1 (ID: %2)?").arg(guestName).arg(id)
        );

    if (confirmed) {
        // Remove from the model
        m_reservationModel->removeReservation(id);

        // Clear selection after deletion
        ui->reservationsTableView->clearSelection();

        showInfoMessage(tr("Reservation Deleted"),
                        tr("Reservation for %1 has been deleted.").arg(guestName));

        updateDashboard();
    }
}

void MainWindow::clearReservationForm()
{
    // Reset all form fields to their default values
    ui->clientComboBox->setCurrentText("");
    ui->roomTypeComboBox->setCurrentIndex(0);
    ui->roomNumberComboBox->clear();
    ui->rateSpinBox->setValue(149.99);
    ui->checkInDateEdit->setDate(QDate::currentDate());
    ui->checkOutDateEdit->setDate(QDate::currentDate().addDays(1));
    ui->nightsSpinBox->setValue(1);
    ui->adultsSpinBox->setValue(1);
    ui->childrenSpinBox->setValue(0);
    ui->paymentMethodComboBox->setCurrentIndex(0);
    ui->depositSpinBox->setValue(0.0);
    ui->totalAmountSpinBox->setValue(0.0);
    ui->statusComboBox->setCurrentIndex(0);
    ui->notesTextEdit->clear();

    // Reset current reservation ID
    m_currentReservationId = -1;
}

void MainWindow::on_saveButton_clicked()
{
    // Validate the form data
    if (ui->clientComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Missing Information"),
                             tr("Please select a client."));
        return;
    }

    if (ui->roomNumberComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Missing Information"),
                             tr("Please select a room."));
        return;
    }

    // Create a new Reservation object with the form data
    Reservation newReservation(
        m_currentReservationId > 0 ? m_currentReservationId : getNextReservationId(),
        ui->clientComboBox->currentText(),
        ui->roomNumberComboBox->currentText(),
        ui->roomTypeComboBox->currentText(),
        "Unknown", // Country - would need to be populated from client data
        "", // Phone - would need to be populated from client data
        "", // Email - would need to be populated from client data
        ui->checkInDateEdit->date(),
        ui->checkOutDateEdit->date(),
        ui->statusComboBox->currentText() == "Confirmed" ? Reservation::Confirmed : Reservation::Pending
        );

    // If this is an edit operation, remove the old reservation first
    if (m_currentReservationId > 0) {
        m_reservationModel->removeReservation(m_currentReservationId);
    }

    // Add the reservation to the model
    m_reservationModel->addReservation(newReservation);

    // Show success message
    showInfoMessage(tr("Reservation Saved"),
                    tr("Reservation has been successfully saved."));

    // Switch back to the reservations tab
    ui->tabWidget->setCurrentWidget(ui->tab_reservations);
    updateDashboard();
}

void MainWindow::on_cancelButton_clicked()
{
    // Ask for confirmation if form has been modified
    // For simplicity, we'll just switch tabs without checking for changes
    ui->tabWidget->setCurrentWidget(ui->tab_reservations);
}

void MainWindow::on_clearButton_clicked()
{
    // Clear the form
    clearReservationForm();
}


// Add these methods to handle room availability
void MainWindow::on_checkAvailabilityButton_clicked()
{
    // In a real implementation, this would query the database for available rooms
    // For now, we'll just populate with dummy data
    ui->roomNumberComboBox->clear();

    // Dummy room numbers based on room type
    QString roomType = ui->roomTypeComboBox->currentText();
    QStringList roomNumbers;

    if (roomType == "Standard Single") {
        roomNumbers << "101" << "102" << "103";
    } else if (roomType == "Standard Double") {
        roomNumbers << "201" << "202" << "203";
    } else if (roomType == "Deluxe King") {
        roomNumbers << "301" << "302";
    } else if (roomType == "Deluxe Double") {
        roomNumbers << "401" << "402";
    } else if (roomType == "Junior Suite") {
        roomNumbers << "501" << "502";
    } else if (roomType == "Executive Suite") {
        roomNumbers << "601";
    } else if (roomType == "Presidential Suite") {
        roomNumbers << "701";
    }

    // Add available rooms to the combo box
    ui->roomNumberComboBox->addItems(roomNumbers);

    // Update room details
    updateRoomDetails();
}


void MainWindow::updateRoomDetails()
{
    // In a real implementation, this would display room details
    // For now, we'll just show a placeholder text
    QString roomType = ui->roomTypeComboBox->currentText();
    QString roomNumber = ui->roomNumberComboBox->currentText();

    if (!roomNumber.isEmpty()) {
        ui->roomDetailsLabel->setText(roomType + " - Room " + roomNumber);

        // Set a default rate based on room type
        double rate = 149.99; // Default rate

        if (roomType == "Standard Single") {
            rate = 149.99;
        } else if (roomType == "Standard Double") {
            rate = 179.99;
        } else if (roomType == "Deluxe King") {
            rate = 229.99;
        } else if (roomType == "Deluxe Double") {
            rate = 249.99;
        } else if (roomType == "Junior Suite") {
            rate = 329.99;
        } else if (roomType == "Executive Suite") {
            rate = 499.99;
        } else if (roomType == "Presidential Suite") {
            rate = 999.99;
        }

        ui->rateSpinBox->setValue(rate);

        // Update total amount
        calculateTotalAmount();
    } else {
        ui->roomDetailsLabel->setText("No room selected");
    }
}


void MainWindow::calculateTotalAmount()
{
    // Calculate the total amount based on rate and nights
    double rate = ui->rateSpinBox->value();
    int nights = ui->nightsSpinBox->value();

    double totalAmount = rate * nights;
    ui->totalAmountSpinBox->setValue(totalAmount);
}

// Add method to update nights when check-in or check-out dates change
                                                     void MainWindow::on_checkInDateEdit_dateChanged(const QDate &date)
{
    // Update nights
    updateNights();
}

void MainWindow::on_checkOutDateEdit_dateChanged(const QDate &date)
{
    // Update nights
    updateNights();
}

void MainWindow::updateNights()
{
    QDate checkIn = ui->checkInDateEdit->date();
    QDate checkOut = ui->checkOutDateEdit->date();

    // Ensure check-out is after check-in
    if (checkOut <= checkIn) {
        ui->checkOutDateEdit->setDate(checkIn.addDays(1));
        checkOut = checkIn.addDays(1);
    }

    int nights = checkIn.daysTo(checkOut);
    ui->nightsSpinBox->setValue(nights);

    // Update total amount
    calculateTotalAmount();
}

// Update nights when nights spinbox is changed
void MainWindow::on_nightsSpinBox_valueChanged(int nights)
{
    QDate checkIn = ui->checkInDateEdit->date();
    ui->checkOutDateEdit->setDate(checkIn.addDays(nights));

    // Update total amount
    calculateTotalAmount();
}

// Update room availability when room type changes
void MainWindow::on_roomTypeComboBox_currentIndexChanged(int index)
{
    ui->roomNumberComboBox->clear();
    ui->roomDetailsLabel->setText("Room Details");
}

void MainWindow::editReservation(int id)
{
    // Find the reservation in the model's data
    const QList<Reservation> &allReservations = m_reservationModel->reservations();

    for (int i = 0; i < allReservations.size(); ++i) {
        if (allReservations[i].id() == id)
        {
            const Reservation &reservation = allReservations[i];

            // Clear the form first
            clearReservationForm();

            // Store the current reservation ID being edited
            m_currentReservationId = id;

            // Populate the form with the reservation's data

            // Client selection - typically would search and select client,
            // but for now just populate the combo box with the name
            ui->clientComboBox->setCurrentText(reservation.guestName());

            // Room details
            ui->roomTypeComboBox->setCurrentText(reservation.roomType());
            ui->roomNumberComboBox->addItem(reservation.roomNumber());
            ui->roomNumberComboBox->setCurrentText(reservation.roomNumber());

            // Stay details
            ui->checkInDateEdit->setDate(reservation.checkInDate());
            ui->checkOutDateEdit->setDate(reservation.checkOutDate());

            // Calculate number of nights
            int nights = reservation.checkInDate().daysTo(reservation.checkOutDate());
            ui->nightsSpinBox->setValue(nights);

            // Set reservation status
            QString statusText;
            switch (reservation.status()) {
            case Reservation::Pending: statusText = "Pending"; break;
            case Reservation::Confirmed: statusText = "Confirmed"; break;
            case Reservation::CheckedIn: statusText = "Checked-in"; break;
            case Reservation::Completed: statusText = "Completed"; break;
            case Reservation::Cancelled: statusText = "Cancelled"; break;
            }
            ui->statusComboBox->setCurrentText(statusText);

            // Switch to the Add Reservation tab
            ui->tabWidget->setCurrentWidget(ui->tab_add_reservation);

            // Update title to indicate we're editing
            ui->tab_add_reservation->setWindowTitle("Edit Reservation #" + QString::number(id));

            return;
        }
    }

    QMessageBox::warning(this, tr("Error"), tr("Reservation not found."));
}

Reservation* MainWindow::findReservationById(int id)
{
    // This method is only for compatibility with your existing code
    // We're not using it in the new implementation
    return nullptr;
}
