#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class songData {
private:
    QString m_title;
    QString m_artist;
    QString m_album;
    QString m_year;
    QJsonArray m_description;
    QJsonArray m_time;
public:
    void setTitle(QString title);
    void setArtist(QString artist);
    void setAlbum(QString album);
    void setYear(QString year);
    void addCue(QString description, float time);
    void removeCue(QString description);
    void clearCues();
    void clear();

    friend class songDb;
};

class songDb {
private:
    QJsonArray m_rootObj;

public:
    void addSong(songData song);
    bool save(QString fileName);
};
