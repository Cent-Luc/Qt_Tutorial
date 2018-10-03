#include <QTextStream>
#include "saveSongs.h"

songData song;
songDb jsonDb;

int main()
{
    QTextStream out(stdout);
    song.setTitle("Planes");
    song.setArtist("Jeremih");
    song.setAlbum("Retro Lover");
    song.setYear("2017");
    song.addCue("Intro1", 20.0);
    song.addCue("Intro2", 30.3);
    song.addCue("Hook1", 40.3);
    song.addCue("Verse1", 56.1);

    jsonDb.addSong(song);

    song.clear();
    song.setTitle("Micasa");
    song.setArtist("Cashy");
    song.setAlbum("Papa Jones");
    song.setYear("2015");
    song.addCue("Intro1", 17.9);
    song.addCue("Hook1", 20.8);
    song.addCue("Hook2", 43.9);
    song.addCue("Verse1", 62.2);

    jsonDb.addSong(song);

    song.clear();
    song.setTitle("Going Up");
    song.setArtist("Iggy Azalea");
    song.setAlbum("Good");
    song.setYear("2017");
    song.addCue("Intro", 15.7);
    song.addCue("Verse1", 25.8);
    song.addCue("Verse2", 44.7);
    song.addCue("Hook", 62.3);
    song.addCue("Hook2", 70.6);
    song.removeCue("Hook");

    jsonDb.addSong(song);
    jsonDb.save("advanced2.json");

    return 0;
}
