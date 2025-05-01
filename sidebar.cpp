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
            // For non-highlighted items, use a simple label with icon and text
            QWidget* menuItem = new QWidget(sidebar);
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
        }
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