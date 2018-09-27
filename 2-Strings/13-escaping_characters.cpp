#include <QTextStream>
#include <QFile>
//Qt5 has a toHtmlEscaped() method, which converts a plain text string
//to an HTML string with HTML metacharacters <, >, &
//and " replaced by HTML named entities.
int main()
{
    QTextStream out(stdout);

    QFile file("1-basic.cpp");

    if(!file.open(QIODevice::ReadOnly))
    {
        out << "Cannot open the file for reading" << endl;
    }

    QTextStream in(&file);
    QString str = in.readAll();
    out << str.toHtmlEscaped() << endl;

    file.close();
    return 0;
}
