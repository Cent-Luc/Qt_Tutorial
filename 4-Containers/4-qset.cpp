//QSet provides a single-valued mathematical set with fast lookups.
//The values are stored in an unspecified order.
#include <QTextStream>
#include <QSet>
#include <algorithm>

 int main()
 {
     QTextStream out(stdout);
     QSet<QString> cols1 = {"bananas", "mangoes", "oranges", "guavas"};
     QSet<QString> cols2 = {"beef", "bacon", "oranges", "hamburger"};

     out << "There are " << cols1.size() << " in cols1" << endl;
     cols1.insert("lemons");
     out << "There are " << cols1.size() << " in cols1" << endl;
     cols1.unite(cols2);
    //The unite() method performs a union of two sets.
    //The cols1 set will have all items inserted from
    //cols2 set that are not already present; in our case, all except for the
    //Oranges.
     out << "There are " << cols1.size() << " in cols1" << endl;

     for(QString val : cols1)
     {
         out << val << " ";
     }
     out << endl;

     QList<QString> lcols = cols1.values();
     std::sort(lcols.begin(), lcols.end());
     for(QString val : lcols)
     {
         out << val << " ";
     }
     out << endl;

     return 0;
 }
