#include <QTextStream>
#include <QFile>

#include "saveSongs.h"

void songData::addCue(QString description, float time) {
    m_description.append(description);
    m_time.append(time);
}

void songData::removeCue(QString description) {
    for (int i=0; i< m_description.count(); i++) {
        // For comparision, convert m_description's QJsonvalue to a QString
        if (description == m_description.at(i).toString()) {
            m_description.removeAt(i);
            m_time.removeAt(i);
        }
    }
}

void songData::clearCues() {
    while(m_description.count())
    {
        m_description.pop_back();
    }
    while(m_time.count())
    {
        m_time.pop_back();
    }
}


void songData::setTitle(QString title) {
    m_title = title;
}

void songData::setArtist(QString artist) {
    m_artist = artist;
}

void songData::setAlbum(QString album) {
    m_album = album;
}

void songData::setYear(QString year) {
    m_year = year;
}

void songData::clear() {
    m_title = "";
    m_artist = "";
    m_album = "";
    m_year = "";
    clearCues();
}


void songDb::addSong(songData song) {
    QJsonObject songObj;
    QJsonObject cues;
    songObj["title"] = song.m_title;
    songObj["artist"] = song.m_artist;
    songObj["album"] = song.m_album;
    songObj["year"] = song.m_year;
    cues.insert("descriptions", song.m_description);
    cues.insert("times", song.m_time);
    songObj.insert("cues", cues);
    m_rootObj.append(songObj);
}

bool songDb::save(QString fileName) {
    QFile save_file(fileName);
    if (!save_file.open(QIODevice::WriteOnly)) {
        //Failed to open the file for writing only
        return false;
    }

    QJsonDocument json_doc(m_rootObj);
    QString json_str = json_doc.toJson();

    save_file.write(json_str.toLocal8Bit());
    save_file.close();

    return true;
}
