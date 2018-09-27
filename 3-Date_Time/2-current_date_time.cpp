#include <QTextStream>
#include <QDate>
#include <QTime>

int main()
{
    QTextStream out(stdout);
    QDate cd = QDate::currentDate();
    QTime tm = QTime::currentTime();

    out << "The date is: " << cd.toString() << endl;
    out << "The time is: " << tm.toString() << endl;

    return 0;
}
