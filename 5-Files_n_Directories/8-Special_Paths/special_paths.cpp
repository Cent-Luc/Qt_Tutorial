//The QDir class is used to get the special paths in the system.
#include <QTextStream>
#include <QDir>

int main()
{
    QTextStream out(stdout);

    QString str1("Current Path: ");
    QString str2("Home Path: ");
    QString str3("Temporary Path: ");
    QString str4("Root Path: ");
    int w = str3.length();

    out << str1.rightJustified(w, ' ') << QDir::currentPath() << endl;
    out << str2.rightJustified(w, ' ') << QDir::homePath() << endl;
    out << str3.rightJustified(w, ' ') << QDir::tempPath() << endl;
    out << str4.rightJustified(w, ' ') << QDir::rootPath() << endl;

    return 0;
}
