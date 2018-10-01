#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

int main()
{
    QTextStream out(stdout);

    QJsonObject stats_obj;
    stats_obj["name"] = "Thor";
    stats_obj["str"] = 34;
    stats_obj["enemy"] = "Loki";

    QJsonArray inventory_list;
    inventory_list << "sword" << "shield" << "armour";

    QJsonObject root_obj;
    root_obj.insert("stats", stats_obj);
    root_obj.insert("inventory", inventory_list);

    QJsonDocument json_doc(root_obj);
    QString json_str = json_doc.toJson();

    QFile save_file("mixed.json");
    if (!save_file.open(QIODevice::WriteOnly)) {
        qWarning("Failed to open the save file");
        return -1;
    }

    save_file.write(json_str.toLocal8Bit());
    save_file.close();
    return 0;
}
