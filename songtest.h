#ifndef SONGTEST_H
#define SONGTEST_H
#include "song.h"

class SongTestt {
public:
    SongTestt()noexcept;
    static void testSong() {
        // Create songs
        Song song1("Song Title 1", "Artist 1", "Link 1", "Lyrics 1", "Duration 1", "Year 1");
        Song song2("Song Title 2", "Artist 2", "Link 2", "Lyrics 2");

        // Test getters and setters
        std::cout << "Song 1 - Title: " << song1.getTitle().toStdString() << ", Artist: " << song1.getArtist().toStdString() << std::endl;
        std::cout << "Song 2 - Title: " << song2.getTitle().toStdString() << ", Artist: " << song2.getArtist().toStdString() << std::endl;

        // Test operator=
        Song song3;
        song3 = song1;
        std::cout << "Song 3 - Title: " << song3.getTitle().toStdString() << ", Artist: " << song3.getArtist().toStdString() << std::endl;

        // Test ostream operator<<
        std::cout << "Song 1: " << song1 << std::endl;
        std::cout << "Song 2: " << song2 << std::endl;
    }
};

#endif // SONGTEST_H
