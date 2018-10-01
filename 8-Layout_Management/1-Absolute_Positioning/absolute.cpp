#include <QApplication>
#include <QDesktopWidget>
#include <QTextEdit>
#include "absolute.h"

Absolute::Absolute(QWidget* parent) : QWidget(parent) {
    QTextEdit* ledit = new QTextEdit(this);
    ledit->setGeometry(5, 5, 300, 150);
}

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Absolute window;

    window.setWindowTitle("Absolute");
    window.show();

    return app.exec();
}
