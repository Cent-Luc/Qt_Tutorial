#include "plusminus.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PlusMinus window;

    window.resize(640, 480);
    window.setWindowIcon(QIcon("batLogo.png"));
    window.setWindowTitle("Plus Minus");
    window.show();

    return app.exec();
}
