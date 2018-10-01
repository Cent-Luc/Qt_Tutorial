#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

int main()
{
    QTextStream out(stdout);

    QJsonArray json_array;
    json_array.append("Barbie");
    json_array.append("Jacob");
    json_array.append("Ann");

    QJsonDocument json_doc(json_array);
    QString json_string = json_doc.toJson();

    QFile save_file("array.json");
    if (!save_file.open(QIODevice::WriteOnly)) {
        qWarning("Failed to open the save file");
        return -1;
    }

    save_file.write(json_string.toLocal8Bit());
    save_file.close();
    return 0;
}
