#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include <stack>
#include "song.h"
#include <algorithm>
#include <random>


class Playlist {
public:
    void addSong(const Song& song) {
        songs.push_back(song);
    }

    void removeSong(const Song& song) {
        songs.erase(std::remove(songs.begin(), songs.end(), song), songs.end());
    }

    void clear() {
        songs.clear();
    }

    void generateRandom(std::vector<Song>& songList, int n) {
        if (songList.empty())
            return;

        std::random_device rd;
        std::mt19937 gen(rd());

        std::shuffle(songList.begin(), songList.end(), gen);

        int count = std::min(n, static_cast<int>(songList.size()));
        songs.assign(songList.begin(), songList.begin() + count);
    }

private:
    std::vector<Song> songs;
};
#endif // PLAYLIST_H
