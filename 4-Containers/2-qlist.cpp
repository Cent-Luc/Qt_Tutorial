//QVector is a template class that provides a dynamic array. It stores its items
//in adjacent memory locations and provides fast index-based access.
//For large vectors, inserting operations are slower and
//QList container is recommended instead.
#include <QTextStream>
#include <QList>
#include <algorithm>

int main()
{
    QTextStream out(stdout);
    QList<QString> authors = {"Baalzac", "Tolstoy", "Kasparov", "London",
        "Alderson"};

    for(int i=0; i < authors.size(); i++)
    {
        out << authors.at(i) << endl;
    }

    authors << "Orvolsky" << "Watumu";

    out << "****************************" << endl;

    std::sort(authors.begin(), authors.end());
    out << "Sorted" << endl;

    for(QString author : authors)
    {
        out << author << endl;
    }
    return 0;
}
