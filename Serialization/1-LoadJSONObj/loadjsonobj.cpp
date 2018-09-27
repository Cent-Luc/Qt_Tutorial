#include <QTextStream>
#include <QFile>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>


int main()
{
    QTextStream out(stdout);
    QFile file("person.json");

    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Cannot open file for reading");
        return -1;
    }
    QTextStream contents_stream(&file);
    QString contents_string = contents_stream.readAll();
    QByteArray contents_bytes = contents_string.toLocal8Bit();

    QJsonDocument json_doc = QJsonDocument::fromJson(contents_bytes);

    if(json_doc.isNull())
    {
        out << "Failed to create JSON doc.";
        return -1;
    }
    if(!json_doc.isObject())
    {
        out << "JSON is not an object";
        return -1;
    }

    QJsonObject json_obj = json_doc.object();

    if(json_obj.isEmpty())
    {
        out << "JSON object is empty.";
        return -1;
    }

    QVariantMap json_map = json_obj.toVariantMap();

    out << json_map["name"].toString() << endl;
    out << json_map["age"].toString() << endl;
    out << json_map["loc"].toString() << endl;

    return 0;
}
