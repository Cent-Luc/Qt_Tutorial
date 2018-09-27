#include <QApplication>
#include <QWidget>
#include <QIcon>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    window.resize(620, 480);
    window.setWindowTitle("Icon");
    window.setWindowIcon(QIcon("batLogo.png"));
    window.setToolTip("Window with an icon");
    window.show();

    return app.exec();
}
