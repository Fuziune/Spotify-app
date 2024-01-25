#include "song.h"

// Song class implementation
void Song::setLyrics(const QString &newLyrics)
{
    lyrics = newLyrics;
}

QString Song::getLyrics() const
{
    return lyrics;
}

Song::Song() {
    this->artist="";
    this->duration="";
    this->link="";
    this->lyrics="";
    this->title="";
    this->year="";
}

Song::Song(QString t, QString a, QString li,QString ly, QString d, QString y)
    : title(t), artist(a),  duration(d), lyrics(ly),link(li),year(y) {}
Song::Song(QString t, QString a, QString li,QString ly)
    : title(t), artist(a), lyrics(ly),link(li) {}
void Song::setTitle(const QString& newTitle) {
    title = newTitle;
}

QString Song::getTitle() const {
    return title;
}

void Song::setArtist(const QString& newArtist) {
    artist = newArtist;
}

QString Song::getArtist() const {
    return artist;
}

void Song::setDuration(const QString& newDuration) {
    duration = newDuration;
}

QString Song::getDuration() const {
    return duration;
}

void Song::setLink(const QString& newLink) {
    link = newLink;
}

QString Song::getLink() const {
    return link;
}

void Song::setYear(const QString& newYear) {
    year = newYear;
}

QString Song::getYear() const {
    return year;
}
ostream& operator<<(ostream& os, const Song& s) {
    os <<"artist="<< s.artist.toStdString() << endl;
    os <<"title="<< s.title.toStdString() << endl;
    os<<"duration="<<s.duration.toStdString()<<endl;
    os<<"link="<<s.link.toStdString()<<endl;
    os<<"lyrics="<<s.lyrics.toStdString()<<endl;
    os<<"year="<<s.year.toStdString()<<endl;

    return os;}
Song& Song::operator=(const Song& other){
    this->setArtist(other.getArtist());
    this->setDuration(other.getDuration());
    this->setLink(other.getLink());
    this->setLyrics(other.getLyrics());
    this->setYear(other.getYear());
    this->setTitle(other.getTitle());
    return *this;
}
