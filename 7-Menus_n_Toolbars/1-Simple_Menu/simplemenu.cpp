//We have a menubar, a menu and an action. In order to work with menus,
//we must inherit from a QMainWindow widget.
#include "simplemenu.h"

SimpleMenu::SimpleMenu(QWidget *parent) : QMainWindow(parent)
{
    //Create an action
    QAction *quit = new QAction("&Quit", this);

    //Create a file menu and add the quit action
    QMenu *file ;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);

    //connect the quit action to the Application quit slot
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}
