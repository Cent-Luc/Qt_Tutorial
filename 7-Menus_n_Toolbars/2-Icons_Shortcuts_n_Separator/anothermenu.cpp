#include "anothermenu.h"

AnotherMenu::AnotherMenu(QWidget *parent) : QMainWindow(parent)
{
    QPixmap newpix("new.png");
    QPixmap openpix("open.png");
    QPixmap closepix("close.png");

    QAction *newa = new QAction(newpix, "&New", this);
    QAction *opena = new QAction(openpix, "&Open", this);
    QAction *quita = new QAction(closepix, "&Close", this);
    quita->setShortcut(tr("CTRL+Q"));

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(newa);
    file->addAction(opena);
    file->addSeparator();
    file->addAction(quita);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quita, &QAction::triggered, qApp, &QApplication::quit);
}

//In some environments, the menu icons are not shown by default.
//In this case we can disable the Qt::AA_DontShowIconsInMenus attribute.
