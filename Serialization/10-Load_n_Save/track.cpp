#include <QTextStream>
#include <QFile>
#include <QVariant>

#include "track.h"

void TrackData::addCue(QString description, double time) {
    m_description.append(description);
    m_time.append(time);
}

void TrackData::removeCue(QString description) {
    for (int i=0; i< m_description.count(); i++) {
        // For comparision, convert m_description's QJsonvalue to a QString
        if (description == m_description.at(i).toString()) {
            m_description.removeAt(i);
            m_time.removeAt(i);
        }
    }
}

void TrackData::clearCues() {
    while(m_description.count())
    {
        m_description.pop_back();
    }
    while(m_time.count())
    {
        m_time.pop_back();
    }
}


void TrackData::setTitle(QString title) {
    m_title = title;
}

QString TrackData::getTitle() {
    return m_title;
}

void TrackData::setArtist(QString artist) {
    m_artist = artist;
}

QString TrackData::getArtist() {
    return m_artist;
}

void TrackData::setAlbum(QString album) {
    m_album = album;
}

QString TrackData::getAlbum() {
    return m_album;
}

void TrackData::setYear(QString year) {
    m_year = year;
}

QString TrackData::getYear() {
    return m_year;
}

QJsonArray TrackData::getCueDescriptions() {
    return m_description;
}

QJsonArray TrackData::getCueTimes() {
    return m_time;
}

void TrackData::clear() {
    m_title = "";
    m_artist = "";
    m_album = "";
    m_year = "";
    clearCues();
}


TrackDb::TrackDb (QString dbPath) {
    QFile dbFile(dbPath);
    if (!dbFile.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open file for reading");
    }

    QTextStream contentStream(&dbFile);
    QString contentString = contentStream.readAll();
    QByteArray contentBytes = contentString.toLocal8Bit();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(contentBytes);

    if (jsonDoc.isNull()) {
        qWarning("Failed to create a JSON doc");
    }
    if (!jsonDoc.isArray()) {
        qWarning("JSON doc is not an array");
    }

    QJsonArray rootArray = jsonDoc.array();
    QVariantList rootList = rootArray.toVariantList();


    // Later on it would be wise to put this for loop in its own
    // function and maybe call it "unserializer()"
    for (int i = 0; i < rootList.count(); i++) {
        QVariantMap trackMap = rootList.at(i).toMap();
        TrackData trackData;

        trackData.setTitle(trackMap["title"].toString());
        trackData.setArtist(trackMap["artist"].toString());
        trackData.setAlbum(trackMap["album"].toString());
        trackData.setYear(trackMap["year"].toString());

        QVariantMap cues = trackMap["cues"].toMap();
        QVariantList cueDescriptions = cues["descriptions"].toList();
        QVariantList cueTimes = cues["times"].toList();
        for (int i = 0; i < cueDescriptions.count(); i++)
        {
            trackData.addCue(cueDescriptions.at(i).toString(), cueTimes.at(i).toDouble());
        }

        m_tracksDb.append(trackData);
    }
}

void TrackDb::addSong(TrackData track) {
    m_tracksDb.append(track);
}

void TrackDb::serializeAll() {
    for(TrackData track : m_tracksDb) {
        QJsonObject trackObj;
        QJsonObject cues;

        trackObj["title"] = track.getTitle();
        trackObj["artist"] = track.getArtist();
        trackObj["album"] = track.getAlbum();
        trackObj["year"] = track.getYear();

        cues.insert("descriptions", track.getCueDescriptions());
        cues.insert("times", track.getCueTimes());
        trackObj.insert("cues", cues);

        m_rootObj.append(trackObj);
    }
    
}

bool TrackDb::save(QString fileName) {
    QFile save_file(fileName);
    if (!save_file.open(QIODevice::WriteOnly)) {
        //Failed to open the file for writing only
        return false;
    }

    serializeAll();

    QJsonDocument json_doc(m_rootObj);
    QString json_str = json_doc.toJson();

    save_file.write(json_str.toLocal8Bit());
    save_file.close();

    return true;
}
