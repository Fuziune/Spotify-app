
#include "mainwindow.h"

#include <QApplication>
#include"song.h"
//#include "songcontroller.h"
//include "songtest.h"
#include"repository.h"
//#include "repositorytest.h"
#include "songcontroller.h"
//#include "controllertest.h"
#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{   //SongTestt::testSong();
    //RepositoryTestt::testRepository();
    //SongControllerTestt::testSongController();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Song b;
    Song a1("mama","tata","mama","bunicu");
    Song b2("ra","ta","ta","ta");
    Song c("re","ghe","ton","ton");
    Repository repo;
    SongController daa;
    repo.store(a1);
    repo.store(b2);
    repo.store(c);
    daa.performAction(new ActionAdd(repo,a1));
   // daa.undo();
    daa.performAction(new ActionAdd(repo,b2));
   // daa.printSongs();
    //SongController contr();
    daa.performAction(new ActionDelete(repo,a1));
   // daa.printSongs();
     //daa.undo();
    daa.performAction(new ActionAdd(repo,c));
    //daa.printSongs();
    //daa.undo();
  daa.printSongs();
    return a.exec();
    return 0;
}
