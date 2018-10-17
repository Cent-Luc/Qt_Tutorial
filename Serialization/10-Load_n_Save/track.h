#pragma once

#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>

class TrackData {
private:
    QString m_title;
    QString m_artist;
    QString m_album;
    QString m_year;
    QJsonArray m_description;
    QJsonArray m_time;
public:
    void setTitle(QString title);
    QString getTitle();
    void setArtist(QString artist);
    QString getArtist();
    void setAlbum(QString album);
    QString getAlbum();
    void setYear(QString year);
    QString getYear();
    QJsonArray getCueDescriptions();
    QJsonArray getCueTimes();
    void addCue(QString description, double time);
    void removeCue(QString description);
    void clearCues();
    void clear();
};

class TrackDb {
private:
    QJsonArray m_rootObj;
    QList<TrackData> m_tracksDb;

public:
    TrackDb(QString dbPath);
    void addSong(TrackData track);
    void serializeAll();
    bool save(QString fileName);
};
