#include "simplemenu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SimpleMenu window;
    window.resize(640, 480);
    window.setWindowTitle("Simple Menu");
    window.show();

    return app.exec();
}
