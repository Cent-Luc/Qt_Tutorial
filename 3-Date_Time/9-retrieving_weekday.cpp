//The dayOfWeek() method returns a number which represents a day of a week,
//where 1 is Monday and 7 is Sunday.
#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);

    QDate cd = QDate::currentDate();
    int wd = cd.dayOfWeek();

    out << QDate::shortDayName(wd) << endl;
    out << QDate::longDayName(wd) << endl;
    out << QString("Today is the %1th day of the week").arg(wd) << endl;

    return 0;
}
