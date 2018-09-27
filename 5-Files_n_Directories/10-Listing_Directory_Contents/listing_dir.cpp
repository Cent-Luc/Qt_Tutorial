#include <QTextStream>
#include <QFileInfo>
#include <QDir>

int main(int argc, char* argv[])
{
    QTextStream out(stdout);
    if(argc != 2)
    {
        qWarning("Usage: ListDir file");
        return 1;
    }

    QString directory(argv[1]);
    QDir dir(directory);
    if(!dir.exists())
    {
        qWarning("The directory does not exist");
        return 1;
    }
    //Specify the kind of files that should be returned by entryInfoList()
    dir.setFilter(QDir::Files | QDir::AllDirs);
    //Specify the sort order to be used by the entryInfoList() method.
    dir.setSorting(QDir::Size | QDir::Reversed);
    //The entryInfoList() method returns a list of QFileInfo objects for all the
    //files and folders in directory, filtered and ordered by the filtering and
    //ordering methods. QFileInfoList is a synonym for QList<QFileInfo>
    QFileInfoList fileInfoList= dir.entryInfoList();

    int max_size = 0;
    foreach(QFileInfo fileInfo, fileInfoList)
    {
        QString name = fileInfo.fileName();
        int size = name.length();

        if(size > max_size)
        {
            max_size = size;
        }
    }

    int len = max_size + 2;

    out << QString("File Name").leftJustified(len).append("Bytes") << endl;

    for(int i = 0; i < fileInfoList.size(); i++)
    {
        QFileInfo fileInfo = fileInfoList.at(i);
        QString str = fileInfo.fileName().leftJustified(len);
        str.append(QString("%1").arg(fileInfo.size()));
        out << str << endl;
    }

    return 0;
}
