#include <QTextStream>
//#include <QList> Circular include causes errors

int main()
{
    QTextStream out(stdout);
    QString str = "book, cup, shoe, spoon, plate, lace";
    QStringList items = str.split(',');
    QStringListIterator it(items);
    //QStringListIterator provides a Java-style const iterator for QStringList.
    while(it.hasNext())
    {
        out << it.next().trimmed() << endl;
    }


    return 0;
}
