#include "plusminus.h"

 PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent)
 {
     QPushButton *plusBtn = new QPushButton("+", this);
     QPushButton *minBtn = new QPushButton("-", this);
     plusBtn->setToolTip("Add 1");
     minBtn->setToolTip("Subtract 1");
     lbl = new QLabel("0", this);

     QGridLayout *grid = new QGridLayout(this);
     grid->addWidget(plusBtn, 0, 0);
     grid->addWidget(minBtn, 0, 1);
     grid->addWidget(lbl, 1, 1);

     setLayout(grid);

     connect(plusBtn, &QPushButton::clicked, this, &PlusMinus::onPlus);
     connect(minBtn, &QPushButton::clicked, this, &PlusMinus::onMinus);
 }

 void PlusMinus::onPlus()
 {
     int val = lbl->text().toInt();
     val++;
     lbl->setText(QString::number(val));
 }

 void PlusMinus::onMinus()
 {
     int val = lbl->text().toInt();
     val--;
     lbl->setText(QString::number(val));
 }
