#ifndef SONG_H
#define SONG_H
#pragma once
#include <string>

#include <QString>
#include <vector>
#include <exception>
#include <iostream>
using namespace std;
class Repository; // Forward declaration of Repository class

class Song {
public:
    QString title;
    QString artist;
    QString duration;
    QString lyrics;
    QString link;
    QString year;

public:
    Song();
    Song(QString t, QString a, QString li, QString ly,QString d, QString y);
    Song(QString t, QString a, QString li, QString ly);
    Song& operator=(const Song& other);
    void setTitle(const QString &newTitle);
    QString getTitle() const;
    void setArtist(const QString &newArtist);
    QString getArtist() const;
    void setDuration(const QString &newDuration);
    QString getDuration() const;
    void setLink(const QString &newLink);
    QString getLink() const;
    void setYear(const QString &newYear);
    QString getYear() const;
    void setLyrics(const QString &newLyrics);
    QString getLyrics() const;
    friend ostream& operator<<(ostream& os, const Song& s);
};


class SongException : public std::exception {
public:
    explicit SongException(const std::string& errorDescription) : description(errorDescription) {}

    const char* what() const noexcept override {
        return description.c_str();
    }

private:
    std::string description;
};

#endif // SONG_H
