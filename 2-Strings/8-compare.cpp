#include <QTextStream>

#define STR_EQUAL 0
//STR-LOWER is if compare returns a number less than 0
//STR-Greater is if compare returns a number greater than 0

int main()
{
    QTextStream out(stdout);

    QString str1 = "Widgets";
    QString str2 = "widgets";
    QString str3 = "widgets\n";

    if(QString::compare(str1, str2) == STR_EQUAL)
    {
        out << "Str1 and Str2 are equal" << endl;
    }
    else
    {
        out << "Str1 and Str2 are not equal" << endl;
    }

    out << "Case insensitive comparison: " << endl;

    if(QString::compare(str1, str2, Qt::CaseInsensitive) == STR_EQUAL)
    {
        out << "Str1 and Str2 are equal" << endl;
    }
    else
    {
        out << "Str1 and Str2 are not equal" << endl;
    }

    out << "Comparing str2 and str3" << endl;

    if(QString::compare(str2, str3) == STR_EQUAL)
    {
        out << "Str2 and Str3 are equal" << endl;
    }
    else
    {
        out << "Str2 and Str3 are not equal" << endl;
    }
    out << "After stripping the newline character" << endl;

    str3.chop(1);

    if(QString::compare(str2, str3) == STR_EQUAL)
    {
        out << "Str2 and Str3 are equal" << endl;
    }
    else
    {
        out << "Str2 and Str3 are not equal" << endl;
    }

    return 0;

}
