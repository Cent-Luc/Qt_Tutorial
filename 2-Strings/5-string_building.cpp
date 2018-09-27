#include <QTextStream>

int main()
{
    QTextStream out(stdout);

    QString str1 = "I have %1 legs";
    int a = 2;
    out << str1.arg(a) << endl;

    QString str2 = "I am %2 metres tall";
    float b =  5.65;
    out << str2.arg(b) << endl;

    QString str3 = "The %1 facts and no reasons";
    QChar c = 'H';
    out << str3.arg(c) << endl;

    return 0;
}
