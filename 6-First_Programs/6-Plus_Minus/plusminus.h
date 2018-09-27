#pragma once

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QIcon>

class PlusMinus : public QWidget
{
Q_OBJECT

public:
    PlusMinus(QWidget *parent = 0);
private slots:
    void onPlus();
    void onMinus();

private:
    QLabel *lbl;
};
