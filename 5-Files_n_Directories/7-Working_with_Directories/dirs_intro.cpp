#include <QTextStream>
#include <QDir>

int main()
{
    QTextStream out(stdout);
    QDir dir;

    //Create a new directory
    if(dir.mkdir("mydir"))
    {
        out << "mydir successfully created" << endl;
    }

    dir.mkdir("mydir2");
    //Check if mydir2 exists
    if(dir.exists("mydir2"))
    {
        //Rename it to newdir
        dir.rename("mydir2", "newdir");
    }

    //The mkpath() creates a new directory and all necessary parent
    //directories in one shot.
    dir.mkpath("temp/newfolder");

    return 0;
}
