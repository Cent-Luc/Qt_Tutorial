#include "anothermenu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AnotherMenu window;

    window.resize(640, 480);
    window.setWindowTitle("Another Menu");
    window.show();

    return app.exec();
}
