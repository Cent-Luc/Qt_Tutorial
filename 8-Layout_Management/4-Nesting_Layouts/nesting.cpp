// No need to include both. Apparently, including one is enough as it automatically
//includes the other
//#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include "nesting.h"

Layouts::Layouts(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout(this);

    QListWidget* lw = new QListWidget(this);
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");

    QPushButton* add = new QPushButton("Add", this);
    QPushButton* rename = new QPushButton("Rename", this);
    QPushButton* remove = new QPushButton("Remove", this);
    QPushButton* removeAll = new QPushButton("Remove All", this);

    vbox->setSpacing(3);
    vbox->addStretch(1);
    vbox->addWidget(add);
    vbox->addWidget(rename);
    vbox->addWidget(remove);
    vbox->addWidget(removeAll);
    vbox->addStretch(1);

    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);
}
