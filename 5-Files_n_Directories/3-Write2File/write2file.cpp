//In order to write to a file, we open the file in the write mode,
//create an output stream directed to the file,
//and use a write operator to write to that stream.
#include <QTextStream>
#include <QFile>

int main()
{
    QTextStream out(stdout);
    QFile file("distros.txt");

    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream outf(&file);

        outf << "Debian" << endl;
        outf << "Ubuntu" << endl;
        outf << "Kali" << endl;
        outf << "Mint" << endl;
        outf << "Arch" << endl;
    }
    else
    {
        out << "Could not open file for writing" << endl;
        return 1;
    }
    file.close();

    return 0;

}
