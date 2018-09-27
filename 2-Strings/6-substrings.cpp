#include <QTextStream>

int main()
{
    QTextStream out(stdout);

    QString str1 = "the night train";
    out << str1.right(5) << endl;
    //train
    out << str1.left(9) << endl;
    //the night
    out << str1.mid(4, 5) << endl;
    //night

    QString str2 = "the big apple";
    //The QStringRef class is a read-only version of a QString .
    //Here we create a QStringRef of a portion of the str2 string. The second
    //parameter is the position and the third is the length of the substring.
    QStringRef str3(&str2, 4, 9);
    out << str3 << endl;

}
