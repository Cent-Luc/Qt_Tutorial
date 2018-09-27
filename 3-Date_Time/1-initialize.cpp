#include <QTextStream>
#include <QDate>
#include <QTime>

int main()
{
    QTextStream out(stdout);

    QDate dt1(2018, 7, 11);
    //Year, month day
    out << dt1.toString() << endl;

    QDate dt2;
    dt2.setDate(2016, 12, 30);
    out << dt2.toString() << endl;

    QTime tm1(12, 48, 30, 155);
    out << tm1.toString("hh:mm:ss:zzz") << endl;

    QTime tm2;
    tm2.setHMS(10, 30, 59, 452);
    out << tm2.toString("hh:mm:ss:zzz") << endl;

    return 0;
}
