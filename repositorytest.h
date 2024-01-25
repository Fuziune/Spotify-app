#ifndef REPOSITORYTEST_H
#define REPOSITORYTEST_H
#include "repository.h"
#include "song.h"
#include <iostream>
class RepositoryTestt {
public:
    RepositoryTestt()noexcept;
    static void testRepository() {
        Repository repository;

        // Create songs
        Song song1("Song Title 1", "Artist 1", "Link 1", "Lyrics 1", "Duration 1", "Year 1");
        Song song2("Song Title 2", "Artist 2", "Link 2", "Lyrics 2", "Duration 2", "Year 2");

        // Test storing songs
        repository.store(song1);
        repository.store(song2);

        // Test getRepo()
        std::vector<Song> songList = repository.getRepo();
        std::cout << "Songs in the repository:" << std::endl;
        for (const auto& song : songList) {
            std::cout << song << std::endl;
        }

        // Test find()
        try {
            const Song& foundSong = repository.find("Song Title 1", "Artist 1");
            std::cout << "Found song: " << foundSong << std::endl;

           // const Song& notFoundSong = repository.find("Unknown Title", "Unknown Artist");
        } catch (const SongException& exception) {
            std::cerr << "Error finding song: " << exception.what() << std::endl;
        }

        // Test remove()
        try {
            repository.remove(song1);
            std::cout << "Song removed successfully." << std::endl;

            repository.remove(song1);  // Try removing a song that doesn't exist
        } catch (const SongException& exception) {
            std::cerr << "Error removing song: " << exception.what() << std::endl;
        }
    }
};
#endif // REPOSITORYTEST_H
