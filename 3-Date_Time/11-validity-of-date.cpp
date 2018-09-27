//There is a isValid() method which checks whether a date is valid.
#include <QTextStream>
#include <QDate>

int main()
{
    QTextStream out(stdout);
    QList<QDate> dates({QDate(2018, 12, 30), QDate(2018, 11, 31),
        QDate(2018, 2, 28)});

    for(int i=0; i < dates.size(); i++)
    {
        if(dates.at(i).isValid())
        {
            out << "The date is valid" << endl;
        }
        else
        {
            out << "The date is not valid" << endl;
        }
    }

    return 0;
}
