/*#ifndef CONTROLLERTEST_H
#define CONTROLLERTEST_H
#include "songcontroller.h"
//#include "repositorytest.h"
#include <iostream>
class SongControllerTestt {
public:
    SongControllerTestt()noexcept;
    static void testSongController() {
        Repository repository;
        SongController songController(Repository& repository);

        // Create songs
        Song song1("Song Title 1", "Artist 1", "Link 1", "Lyrics 1");
        Song song2("Song Title 2", "Artist 2", "Link 2", "Lyrics 2");

        // Test addNewSong()
        try {
            songController.addNewSong("Song Title 1", "Artist 1", "Link 1", "Lyrics 1");
            songController.addNewSong("Song Title 2", "Artist 2", "Link 2", "Lyrics 2");

            std::cout << "Songs added successfully." << std::endl;
        } catch (const SongException& exception) {
            std::cerr << "Error adding songs: " << exception.what() << std::endl;
        }

        // Test search()
        try {
            songController.search(song1);
            songController.search(song2);
        } catch (const SongException& exception) {
            std::cerr << "Error searching for songs: " << exception.what() << std::endl;
        }
    }
};

#endif // CONTROLLERTEST_H*/
