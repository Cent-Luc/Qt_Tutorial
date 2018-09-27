#include <QTextStream>
#include <QDate>

//QList requires C++11 support

int main()
{
    QTextStream out(stdout);

    QList<int> years({2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017});

    foreach(int year, years)
    {
        if(QDate::isLeapYear(year))
        {
            out << year << " is a leap year" << endl;
        }
        else
        {
            out << year << " is not a leap year" << endl;
        }
    }

    return 0;
}
