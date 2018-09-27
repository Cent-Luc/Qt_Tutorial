//Each file has a user who is its owner. A file also belongs to a group of users
//for better management and protection of files.
#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);

    if(argc!=2)
    {
        qWarning("Usage: Owner file");
        return 1;
    }

    QString fname = argv[1];
    QFileInfo finfo(fname);

    QString owner = finfo.owner();
    QString group = finfo.group();

    out << "Owner: " << owner << endl;
    out << "Group: " << group << endl;

    return 0;
}
