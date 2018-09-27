/*
d - The day as a number without a leading zero (1 to 31)
dd - The day as a number with a leading zero (01 to 31)
ddd - The abbreviated localized day name (e.g. 'Mon' to 'Sun'). Uses QDate::shortDayName().
dddd - The long localized day name (e.g. 'Monday' to 'Sunday'). Uses QDate::longDayName().
M - The month as a number without a leading zero (1 to 12)
MM - The month as a number with a leading zero (01 to 12)
MMM - The abbreviated localized month name (e.g. 'Jan' to 'Dec'). Uses QDate::shortMonthName().
MMMM - The long localized month name (e.g. 'January' to 'December'). Uses QDate::longMonthName().
yy - The year as two digit number (00 to 99)
yyyy - The year as four digit number. If the year is negative, a minus sign is prepended in addition.
*/
#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);
    QDate dt = QDate::currentDate();

    out << "Today is " << dt.toString("dd-M-yyyy") << endl;
    out << "Today is " << dt.toString("ddd dth MMMM, yyyy") << endl;
    out << "Today is " << dt.toString("yy MMM dddd") << endl;
    out << "Today is " << dt.toString("d/M/yy") << endl;

    return 0;
}
