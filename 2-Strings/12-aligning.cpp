#include <QTextStream>

//We can use leftJustified() and rightJustified() to align our strings

int main()
{
    QTextStream out(stdout);

    QString field1, field2, field3, field4;
    field1 = "Name: ";
    field2 = "Occupation: ";
    field3 = "Residency: ";
    field4 = "Marital Status: ";

    int width = field4.length();

    out << field1.rightJustified(width, ' ') << "John Doe" << endl;
    out << field2.rightJustified(width, ' ') << "Programmer" << endl;
    out << field3.rightJustified(width, ' ') << "Nairobi" << endl;
    out << field4.rightJustified(width, ' ') << "Single" << endl;
    //The rightJustified() method returns a string having 'width' characters.
    //If the string is shorter, the rest is filled with the provided character.
    //In our case, it is a space character.
    return 0;
}
