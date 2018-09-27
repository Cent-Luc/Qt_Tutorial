//In order to read the contents of a file, we must first open the file for
//reading. Then an input file stream is created; from this stream,
// the data is read.
#include <QTextStream>
#include <QFile>

int main()
{
    QTextStream out(stdout);
    QFile file("colours.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Cannot open file for reading");
        return 1;
    }
    QTextStream contents(&file);

    while(!contents.atEnd())
    {
        QString line = contents.readLine();
        out << line << endl;
    }
    file.close();

    return 0;
}
