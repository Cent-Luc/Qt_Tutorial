#include <QTextStream>

int main()
{
    QTextStream out(stdout);

    QString str1 = "I am c3n7";
    out << str1 << endl ;

    QString str2("I hate QT");
    out << str2 << endl ;

    std::string s1 = "Good old WxWidgets";
    QString str3 = s1.c_str();
    out << str3 << endl;

    std::string s2 = "Any time or day";
    QString str4 = (QString::fromLatin1(s2.data(), s2.size()));

    char s3[] = "Yep. That is it";
    QString str5(s3);
    out << str4 << endl;

    return 0;

}
