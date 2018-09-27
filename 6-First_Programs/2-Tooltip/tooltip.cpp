#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    window.resize(620, 480);
    window.move(50, 30);
    window.setWindowTitle("Tooltip");
    window.setToolTip("The Window");
    window.show();

    return app.exec();
}
