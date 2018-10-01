#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextStream>

int main()
{
    QTextStream out(stdout);
    QJsonObject json_obj;
    json_obj["name"] = "John";
    json_obj["str"] = 34;
    json_obj["enemy"] = "Pac Man";

    QJsonDocument json_doc(json_obj);
    QString json_string = json_doc.toJson();

    QFile save_file("simple.json");
    if (!save_file.open(QIODevice::WriteOnly)) {
        qWarning("Failed to open the save file");
        return -1;
    }

    save_file.write(json_string.toLocal8Bit());
    save_file.close();
    return 0;
}
