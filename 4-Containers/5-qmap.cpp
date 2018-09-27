//QMap is an associative array (dictionary) that stores key-value pairs.
//It provides fast lookup of the value associated with a key.
#include<QTextStream>
#include<QMap>

int main()
{
    QTextStream out(stdout);
    QMap<QString, int> items = {{"tables", 5}, {"chairs", 7}} ;

    items.insert("boards", 3);
    QList<int> values = items.values();
    QList<QString> keys = items.keys();

    out << "Values: " << endl;
    for(int value : values)
    {
        out << "\t" << value << endl;
    }
    out << "Keys: " << endl;
    for(QString key: keys)
    {
        out << "\t" << key << endl;
    }

    QMapIterator<QString, int> it(items);
    out << "Key-Value pairs" << endl;
    while(it.hasNext())
    {
        it.next();
        out << it.key() << " : " << it.value() << endl;
    }

    return 0;
}
