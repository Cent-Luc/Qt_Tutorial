#include <QTextStream>
#include <QFile>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

int main()
{
    QTextStream out(stdout);
    QFile file("person.json");

    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Cannot open file for reading.");
        return -1;
    }
    QTextStream contents_stream(&file);
    QString contents_string = contents_stream.readAll();
    QByteArray contents_bytes = contents_string.toLocal8Bit();

    QJsonDocument json_doc = QJsonDocument::fromJson(contents_bytes);

    if(json_doc.isNull())
    {
        qWarning("Failed to create JSON doc.");
        return -1;
    }
    if(!json_doc.isObject())
    {
        qWarning("JSON doc is not an object");
        return -1;
    }

    QJsonObject root_obj = json_doc.object();
    QVariantMap root_map = root_obj.toVariantMap();
    QVariantMap person_map = root_map["person"].toMap();
    QVariantList cars_list = root_map["cars"].toList();

    if(person_map.isEmpty() || cars_list.isEmpty())
    {
        qWarning("The JSON doc was not converted to a variant map succesfully");
        return -1;
    }

    QStringList key_list = person_map.keys();
    for(int i=0; i< key_list.count(); ++i)
    {
        QString key = key_list.at(i);
        QString person_val = person_map[key.toLocal8Bit()].toString();
        out << key << " : " << person_val << endl;
    }

    out << "Cars:" << endl;

    for(int i = 0; i<cars_list.count(); i++)
    {
        out << "\t" << cars_list.at(i).toString() << endl;
    }


    out << "\n\n " << QString().setNum(20.5) << endl;

    return 0;
}
