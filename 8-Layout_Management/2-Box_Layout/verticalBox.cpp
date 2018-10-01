#include "verticalBox.h"
#include <QVBoxLayout>
#include <QPushButton>

VerticalBox::VerticalBox(QWidget* parent) : QWidget(parent) {

    // Create a layout with 1px spacing among child widgets
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);

    // By default, buttons are expanded horizontally and have a fixed vertical
    // size. Make all buttons expandable in both directions
    QPushButton* settings = new QPushButton("Settings", this);
    settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* accounts = new QPushButton("Accounts", this);
    accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* loans = new QPushButton("Loans", this);
    loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* cash = new QPushButton("Cash" , this);
    cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* debts = new QPushButton("Debts", this);
    debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add the widgets to the layout manager
    vbox->addWidget(settings);
    vbox->addWidget(accounts);
    vbox->addWidget(loans);
    vbox->addWidget(cash);
    vbox->addWidget(debts);


    // Set the QVboxLayout as the layout manager for the window
    setLayout(vbox);
}
