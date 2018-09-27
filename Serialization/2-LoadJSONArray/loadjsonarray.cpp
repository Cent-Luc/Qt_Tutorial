#include <QTextStream>
#include <QFile>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


int main()
{
    QTextStream out(stdout);
    QFile file("people.json");

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
        qWarning("Failed to create JSON doc");
        return -1;
    }
    if(!json_doc.isArray())
    {
        qWarning("JSON doc is not an array");
        return -1;
    }

    QJsonArray json_array = json_doc.array();

    if(json_array.isEmpty())
    {
        qWarning("The array is empty");
        return -1;
    }

    for(int i = 0; i< json_array.count(); i++)
    {
        out << json_array.at(i).toString() << endl;
    }

    return 0;
}
