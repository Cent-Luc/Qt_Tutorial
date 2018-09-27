//The QDateTime object contains a calendar date and a clock time.
//It is a combination of the QDate and QTime classes. It has man
//similar methods and the usage is identical to those two classes.
#include <QTextStream>
#include <QDateTime>

int main()
{
    QTextStream out(stdout);
    QDateTime cdt = QDateTime::currentDateTime();

    out << QString("Datetime: ").rightJustified(10, ' ')
        << cdt.toString() << endl;
    out << QString("Date: ").rightJustified(10, ' ')
        << cdt.date().toString() << endl;
    out << QString("Time: ").rightJustified(10, ' ')
        << cdt.time().toString() << endl;

    return 0;
}
