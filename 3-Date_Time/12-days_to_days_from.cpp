//We can easily calculate a date n days from a particular date.
//We use the addDays() method. The daysTo() method returns the
//number of days to a chosen date.
#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);
    QDate dt1(2018, 04, 3);
    QDate dt2 = dt1.addDays(47);
    QDate xmass(2018, 12, 25);

    out << "47 days from " << dt1.toString() << " is "
        << dt2.toString() << endl;
    out << "Christmas is " << QDate::currentDate().daysTo(xmass)
        << " days away" <<endl;
        
    return 0;
}
