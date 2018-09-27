//We can compute the number of days in a particular month using
//the daysInMonth() method
//and the number of days in a year using the daysInYear() method.

#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);
    QList<QString> months;

    months.append("January");
    months.append("February");
    months.append("March");
    months.append("April");
    months.append("May");
    months.append("June");
    months.append("July");
    months.append("August");
    months.append("September");
    months.append("October");
    months.append("November");
    months.append("December");

    QDate dt1(2016, 12, 23);
    QDate dt2(2017, 02, 2);
    QDate dt3(2016, 05, 3);
    QDate dt4(2017, 10, 24);

    out << "There are " << dt1.daysInMonth() << " days in "
        << months.at(dt1.month() - 1) << endl;
    out << "There are " << dt2.daysInMonth() << " days in "
            << months.at(dt2.month() - 1) << endl;
    out << "There are " << dt3.daysInMonth() << " days in "
            << months.at(dt3.month() - 1) << endl;
    out << "There are " << dt4.daysInMonth() << " days in "
            << months.at(dt1.month() - 1) << endl;
    out << "There are " << dt4.daysInYear() << " days in "
            << dt4.year() << endl;

    return 0;
}
