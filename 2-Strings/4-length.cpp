#include <QTextStream>

int main()
{
    QTextStream out(stdout);

    QString str1("London");
    QString str2("London\n");
    QString str3 = "London ";
    QString str4 = "Op£n$";
    out << str1.length() << endl;
    out << str2.length() << endl;
    out << str3.length() << endl;
    out << str4.length() << endl;

    return 0;
}
