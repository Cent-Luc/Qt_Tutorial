#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);

    if(argc != 2)
    {
        qWarning("Usage: FilePath file");
        return 1;
    }

    QString fname(argv[1]);
    QFileInfo finfo(fname);

    QString str1("Absolute File Path: ");
    QString str2("Base Name: ");
    QString str3("Complete Base Name: ");
    QString str4("File Name: ");
    QString str5("Suffix: ");
    QString str6("Complete Suffix: ");
    int w = str1.size();

    //Absolute file path including file name
    out << str1.rightJustified(w, ' ') << finfo.absoluteFilePath() << endl;
    //The base name — the name of the file without the path.
    out << str2.rightJustified(w, ' ') << finfo.baseName() << endl;
    //The complete base name — all characters in the file up to
    //(but not including) the last dot character.
    out << str3.rightJustified(w, ' ') << finfo.completeBaseName() << endl;
    //The file name, i.e. the base name and the extension.
    out << str4.rightJustified(w, ' ') << finfo.fileName() << endl;
    //The file ending, i.e. all characters in the file after (but not including)
    //the last dot character.
    out << str5.rightJustified(w, ' ') << finfo.suffix() << endl;
    //All characters in the file after (but not including) the first dot
    //character
    out << str6.rightJustified(w, ' ') << finfo.completeSuffix() << endl;

    return 0;
}
