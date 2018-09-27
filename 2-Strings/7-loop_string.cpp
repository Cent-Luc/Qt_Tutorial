#include <QTextStream>

int main()
{
    QTextStream out(stdout);

    QString str1 = "There are many stars";

    foreach(QChar qc, str1)
    {
        out << qc << " ";
    }
    out << endl;

    for (QChar *qc = str1.begin(); qc!= str1.end(); ++qc)
    {
        out << *qc << " ";
    }
    out << endl;

    for (int i = 0; i<str1.size(); i++)
    {
        out << str1.at(i) << " ";
    }
    out << endl;

    return 0;
}
