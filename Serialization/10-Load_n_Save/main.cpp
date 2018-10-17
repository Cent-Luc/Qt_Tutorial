#include <QTextStream>
#include "track.h"

int main()
{
    QTextStream out(stdout);

    TrackDb jsonDb("advanced2.json");
    TrackData song;

    song.setTitle("Dont Cry");
    song.setArtist("Lil Wayne");
    song.setAlbum("The Carter IV");
    song.setYear("2018");
    song.addCue("Intro1", 23.0);
    song.addCue("Intro2", 32.3);
    song.addCue("Hook1", 47.3);
    song.addCue("Verse1", 86.1);

    jsonDb.addSong(song);

    song.clear();
    song.setTitle("Mask Off");
    song.setArtist("Future");
    song.setAlbum("Skrill");
    song.setYear("2016");
    song.addCue("Intro1", 18.9);
    song.addCue("Hook1", 27.7);
    song.addCue("Hook2", 83.9);
    song.addCue("Verse1", 92.9);

    jsonDb.addSong(song);

    song.clear();
    song.setTitle("Rap Saved Me");
    song.setArtist("21 Savage");
    song.setAlbum("Dawg");
    song.setYear("2017");
    song.addCue("Intro", 12.4);
    song.addCue("Verse1", 25.5);
    song.addCue("Verse2", 54.1);
    song.addCue("Hook", 67.8);
    song.addCue("Hook2", 77.7);
    song.removeCue("Hook");

    jsonDb.addSong(song);
    jsonDb.save("advancedOutput.json");

    return 0;
}
