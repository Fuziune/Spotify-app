#include "repository.h"
#include "song.h"
#include <exception>
using namespace std;
std::vector<Song> Repository::getRepo() const {
    return repo;
}

void Repository::setRepo(const Song& s) {
    repo.push_back(s);
}

Repository::Repository() {}

void Repository::store(const Song& s) {
    for (const auto& song : repo) {
        if (song.getArtist() == s.getArtist() && song.getTitle() == s.getTitle()) {
            throw SongException(std::string("A song '") + s.getTitle().toStdString() + "' by '" + s.getArtist().toStdString() + "' already exists.");
        }
    }
    repo.push_back(s);
}
const Song& Repository::find(std::string title, std::string artist) {
    for (const auto& song : repo) {
        if (song.getArtist().toStdString() == artist && song.getTitle().toStdString() == title) {
            return song;
        }}
        throw SongException(std::string ("The song")+title+"by"+artist+"already exist");
}
void Repository:: remove(const Song& s){
        int i=0;
        for (auto it = repo.begin(); it != repo.end(); ++it) {
        if (it->getTitle() == s.getTitle() && it->getArtist()==s.getArtist()) {
            repo.erase(it);
            i++;
            break;
        }
        }

        if(i==0){
         throw SongException(std::string ("The song")+s.getTitle().toStdString()+"by"+s.getArtist().toStdString()+"does not exist exist");
        }
}
void Repository::displaysongs(){
        for(const auto& song:repo){
         cout<<song<<endl;
        }}
 ostream& operator<<(ostream& os, const Repository& r){
        for(int i=0;i<r.repo.size();i++)
        {
         os<<r.repo[i]<<endl;
        }
        return os;
}
 Repository& Repository:: operator=(Repository& other){
        for(int i=0;i<other.repo.size();i++){
         this->repo[i]=other.repo[i];
        }
        return *this;
 }
void FileRepository::load(){
        //fstream filee;
        //filepath.open("songtxt");
         std::ifstream inputFile(filepath);
        if(inputFile.is_open())
        {
         Song ari;
         QString title;
         QString artist;
         QString lyrics;
         QString link;
         QString year;
         string word;
         while(getline(inputFile,word)){
                if (word.find("ARTIST") != std::string::npos) {
                    word.replace(0, 7, "");
                    QString qstr = QString::fromStdString(word);
                    ari.setArtist(qstr);
                    artist=qstr;
                }
                else if (word.find("TITLE") != std::string::npos) {
                    word.replace(0, 6, "");
                    QString qstr = QString::fromStdString(word);
                    ari.setTitle(qstr);
                }
                else if (word.find("LYRICS") != std::string::npos) {
                    word.replace(0, 7, "");
                    QString qstr = QString::fromStdString(word);
                    ari.setLyrics(qstr);
                }
               /* else {
                    lyrics += word;
                    lyrics += " ";
                    if (word == "\"") {
                        Song song(artist, title, lyrics);
                        collection.push_back(song);
                    }
                }*/
         }
         }
        else{
        throw std::runtime_error("Failed to open file: " + filepath);
         }}
void FileRepository::save(){
         std::ofstream outputFile(filepath);
         if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to save songs to file: " + filepath);
         }

         //for (const auto& song : getRepo()) {
         for(int i=0;i<repo.size();i++){
        outputFile << repo[i] << std::endl;
         }

         outputFile.close();
}
RepositoryTestt::RepositoryTestt()noexcept
{

}
