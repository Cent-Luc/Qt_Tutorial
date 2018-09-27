#include <QTextStream>
#include <QFileInfo>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    if(argc!=2)
    {
        qWarning("Usage: FileTimes file");
        return 1;
    }

    QString fname(argv[1]);
    QFileInfo finfo(fname);

    QDateTime readDt = finfo.lastRead();
    QDateTime modDt = finfo.lastModified();

    out << "Last Read: " << readDt.toString() << endl;
    out << "Last Modified " << modDt.toString() << endl;

    return 0;
}
