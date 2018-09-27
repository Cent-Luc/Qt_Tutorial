#include <QTextStream>

int main()
{
    QTextStream out(stdout);
    int letters = 0, digits = 0, punctuations = 0, spaces = 0;

    QString str = "7 Roses, 2 hearts, 1 love";

    foreach(QChar l, str)
    {
        if(l.isLetter())
        {
            letters++;
        }
        else if(l.isDigit())
        {
            digits++;
        }
        else if(l.isPunct())
        {
            punctuations++;
        }
        else if(l.isSpace())
        {
            spaces++;
        }
    }

    out << "\"" << str << "\" has:" << endl;
    out << QString("\t-> %1 Letters").arg(letters);
    out << QString("\n\t-> %1 Digits").arg(digits);
    out << QString("\n\t-> %1 Spaces").arg(spaces);
    out << QString("\n\t-> %1 Punctuations").arg(punctuations) << endl;
    return 0;
}
