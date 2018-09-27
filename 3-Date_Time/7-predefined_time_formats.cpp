#include <QTextStream>
#include <QTime>

int main()
{
    QTextStream out(stdout);
    QTime tm = QTime::currentTime();

    out << "The time is " << tm.toString(Qt::TextDate) << endl;
    //Default date/time format
    out << "The time is " << tm.toString(Qt::ISODate) << endl;
    out << "The time is " << tm.toString(Qt::SystemLocaleShortDate) << endl;
    out << "The time is " << tm.toString(Qt::SystemLocaleLongDate) << endl;
    out << "The time is " << tm.toString(Qt::DefaultLocaleShortDate) << endl;
    out << "The time is " << tm.toString(Qt::DefaultLocaleLongDate) << endl;
    out << "The time is " << tm.toString(Qt::SystemLocaleDate) << endl;
    out << "The time is " << tm.toString(Qt::LocaleDate) << endl;

    return 0;
}
