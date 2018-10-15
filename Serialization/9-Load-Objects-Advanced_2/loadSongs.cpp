#include <QTextStream>
#include <QFile>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>

int main()
{
    QTextStream out(stdout);
    QFile file("advanced2.json");

    if (!file.open(QIODevice::ReadOnly))
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
        qWarning("Failed to create JSON doc.");
        return -1;
    }
    if(!json_doc.isArray())
    {
        qWarning("JSON doc is not an array.");
        return -1;
    }

    QJsonArray root_obj = json_doc.array();
    QVariantList root_list = root_obj.toVariantList();

    for(int i = 0; i < root_list.count(); i++) 
    {
        QVariantMap track = root_list.at(i).toMap();
        out << "\n\nAlbum: " << track["album"].toString() << endl;
        out << "Artist: " << track["artist"].toString() << endl;
        out << "Title: " << track["year"].toString() << endl;
        QVariantMap cues = track["cues"].toMap();
        QVariantList cueDescriptions, cueTimes;
        cueDescriptions = cues["descriptions"].toList();
        cueTimes = cues["times"].toList();
        for (int i = 0; i < cueDescriptions.count(); i++) 
        {
            out << "\t" << cueDescriptions.at(i).toString() << " : " << cueTimes.at(i).toString() << endl;
        }
    }

    return 0;
}