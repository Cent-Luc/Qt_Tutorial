#include <QTextStream>

int main()
{
    QTextStream out(stdout);
    QString s1 ,s2, s3, s4, s5;

    s1 = "12";
    s2 = "14";

    //Convert s1 and s2 to integers
    out << s1.toInt() + s2.toInt() << endl;

    int n1 = 40;
    int n2 = 32;

    //Store n1 and n2 as strings in s3 and s4
    out << s3.setNum(n1) + s4.setNum(n2) << endl;

    return 0;
}
