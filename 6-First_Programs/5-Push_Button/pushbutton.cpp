//When we click on the button, a clicked signal is generated.
//A slot is the method which reacts to the signal. In our case it is the quit
//slot of the main application object.
//The qApp is a global pointer to the application object.
//It is defined in the QApplication header file.
#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MyButton : public QWidget
{
public:
    MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    QPushButton *quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(520, 420, 80, 40);

    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyButton window;

    window.resize(620, 480);
    window.setWindowTitle("Push Button");
    window.show();

    return app.exec();
}
