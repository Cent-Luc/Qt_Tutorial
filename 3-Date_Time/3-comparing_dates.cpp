#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);

    QDate dt1(2018, 10, 27);
    QDate dt2(2018, 10, 28);

    if( dt1 > dt2)
    {
        out << dt1.toString() << " comes after " << dt2.toString() << endl;
    }
    else
    {
        out << dt2.toString() << " comes after " << dt1.toString() << endl;
    }

    return 0;
}
