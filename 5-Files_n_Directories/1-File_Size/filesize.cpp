#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);

    if(argc !=2 )
    {
        out << "Usage: FileSize file" << endl;
        return 1;
    }

    QString fileName =argv[1];

    if(!QFile(fileName).exists())
    {
        qWarning("The file does not exists");
        //If the file does not exists exist the program
        return 1;
    }

    QFileInfo fileInfo(fileName);

    qint64 size = fileInfo.size();
    out << fileName << " has " << size << " bytes." << endl;

    return 0;
}
