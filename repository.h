#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "song.h"
#include <vector>
#include <QString>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <stack>
using namespace std;
//class Song;
class SongException;
class Repository
{protected:
    vector<Song> repo;
public:
    Repository();
    void store(const Song& s);
    const Song& find(std::string title, std::string artist) ;
    void remove(const Song& s);
    std::vector<Song> getRepo() const;
    void setRepo(const Song& s);
    friend ostream& operator<<(ostream& os, const Repository& r);
   // Repository(const Repository &other)=delete;
    Repository& operator=(Repository& other);
    void displaysongs();
};
class FileRepository:public Repository{
protected:
    std:: string filepath;
public:
    void load();
    void save();
};
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




#endif // REPOSITORY_H

