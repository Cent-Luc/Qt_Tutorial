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

    QJsonArray cuePoints;
    QJsonObject song1;
    song1["title"] = "Waiting for Love";
    song1["artist"] = "Avicii";
    song1["album"] = "Stories";
    song1["year"] = 2013;
    cuePoints << 20 << 60 << 90 << 120 << 150;
    song1.insert("cues", cuePoints);

    while(cuePoints.count())
    {
        cuePoints.pop_back();
    }
    QJsonObject song2;
    song2["title"] = "Survival";
    song2["artist"] = "Drake";
    song2["album"] = "Scorpion";
    song2["year"] = 2018;
    cuePoints << 23 << 68 << 92 << 125 << 157;
    song2.insert("cues", cuePoints);

    QJsonArray root_obj;
    root_obj.append(song2);
    root_obj.append(song1);

    QJsonDocument json_doc(root_obj);
    QString json_str = json_doc.toJson();

    QFile save_file("advanced.json");
    if (!save_file.open(QIODevice::WriteOnly)) {
        qWarning("Failed to open the save file");
        return -1;
    }

    save_file.write(json_str.toLocal8Bit());
    save_file.close();
    return 0;
}
