#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);
    QDate dt = QDate::currentDate();

    out << "Today is " << dt.toString(Qt::TextDate) << endl;
    //Default date/time format
    out << "Today is " << dt.toString(Qt::ISODate) << endl;
    //The above is an international standard for displaying dates
    out << "Today is " << dt.toString(Qt::SystemLocaleShortDate) << endl;
    out << "Today is " << dt.toString(Qt::SystemLocaleLongDate) << endl;
    out << "Today is " << dt.toString(Qt::DefaultLocaleShortDate) << endl;
    out << "Today is " << dt.toString(Qt::DefaultLocaleLongDate) << endl;
    out << "Today is " << dt.toString(Qt::SystemLocaleDate) << endl;
    out << "Today is " << dt.toString(Qt::LocaleDate) << endl;

    return 0;
}
