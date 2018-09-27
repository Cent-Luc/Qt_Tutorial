//QVector is a template class that provides a dynamic array. It stores its items
// in adjacent memory locations and provides fast index-based access.
//For large vectors, inserting operations are slower and
//QList container is recommended instead.
#include <QTextStream>
#include <QVector>

int main()
{
    QTextStream out(stdout);
    QVector<int> vals = {21, 36, 64, 13, 93, 46, 72};

    out << "The size of the vector is " << vals.size() << endl;
    out << "The first item is " << vals.first() << endl;
    out << "The last item is " << vals.last() << endl;

    vals.append(12);
    vals.prepend(52);

    for(int val: vals)
    {
        out << val << " ";
    }
    out << endl;

    return 0;
}
