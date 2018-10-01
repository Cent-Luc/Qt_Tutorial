#include "buttons.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Buttons::Buttons(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox = new QHBoxLayout(this);

    okBtn = new QPushButton("OK", this);
    applyBtn = new QPushButton("Apply", this);

    // The 1st param: The child widget
    // The 2nd: The Stretch factor. By setting it to 1, we give it space from
    //the left side of the window
    // The 3rd: This will constantly align the widget to the right side of
    //the parent
    hbox->addWidget(okBtn, 1, Qt::AlignRight);
    hbox->addWidget(applyBtn, 0);

    // Put an empty expendable space into the vertical box by calling the
    //method below, then add the horizontal box layout to the vbox layout
    vbox->addStretch(1);
    vbox->addLayout(hbox);
}
