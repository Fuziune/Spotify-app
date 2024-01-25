#ifndef SONGCONTROLLER_H
#define SONGCONTROLLER_H
#include <iostream>
#include "song.h"
#include <vector>
#include <QString>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdexcept>
#include <stack>
#include <algorithm>
#include <random>
using namespace std;
#include"repository.h"
#include "song.h"


class Action {
public:
    virtual void apply(Repository& repository) = 0;
    virtual ~Action() {}
};

class ActionAdd : public Action {
public:
    ActionAdd(Repository& repository, const Song& song)
        : repository(repository), song(song) {}

    void apply(Repository& repository) override {
        repository.store(song);
    }

private:
    Repository& repository;
    Song song;
};

class ActionDelete : public Action {
public:
    ActionDelete(Repository& repository, const Song& song)
        : repository(repository), song(song) {}

    void apply(Repository& repository) override {
        repository.remove(song);
    }

private:
    Repository& repository;
    Song song;
};

class SongController {
public:
    void addNewSong(Repository& repository, const Song& song) {
        performAction(new ActionAdd(repository, song));
    }

    void removeSong(Repository& repository, const Song& song) {
        performAction(new ActionDelete(repository, song));
    }
    void printSongs(){
        repo.displaysongs();
    }
    void performAction(Action* action) {
        action->apply(repo);
        undoStack.push(action);

        while (!redoStack.empty()) {
            delete redoStack.top();
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            Action* action = undoStack.top();
            undoStack.pop();
            action->apply(repo);
            redoStack.push(action);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            Action* action = redoStack.top();
            redoStack.pop();
            action->apply(repo);
            undoStack.push(action);
        }
    }

private:
    Repository repo;
    std::stack<Action*> undoStack;
    std::stack<Action*> redoStack;
};

/*class Playlist {
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
};*/

class Playlist {
public:
    void addSong(const Song& song) {
        songs.push_back(song);
    }
    //int b=-1;
    void removeSong(const Song& song) {
        for(auto it=songs.begin();it!=songs.end();++it)
            if(it->artist==song.getArtist() && it->artist==song.getTitle())
            songs.erase(it);
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



#endif // SONGCONTROLLER_H
