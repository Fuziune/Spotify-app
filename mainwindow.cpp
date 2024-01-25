#include <vector>
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"
#include "song.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    central_Widget = new QWidget{};
    central_Widget->setWindowTitle("PlaylistQT");
    main_Layout = new QHBoxLayout();
    buttons_Layout = new QHBoxLayout();
    buttons_Layout1 = new QHBoxLayout();
    buttons_Layout2 = new QVBoxLayout();
    allsongs_title = new QLabel("All songs");
    playlist_label = new QLabel("Playlist:");
    allsongs_label = new QListWidget(this);
    title_label = new QLabel("Title:");
    title_text = new QLineEdit();
    artist_label = new QLabel("Artist:");
    artist_text = new QLineEdit();
    duration_label = new QLabel("Duration:");
    duration_text = new QLineEdit();
    link_label = new QLabel("Link:");
    link_text = new QLineEdit();
    playlist_text = new QTextEdit();
    add_button = new QPushButton("Add",this);
    delete_button = new QPushButton("Delete",this);
    update_button = new QPushButton("Update",this);
    filter_button = new QPushButton("Filter",this);
    greater_button = new QPushButton(">",this);
    play_button = new QPushButton("Play");
    next_button = new QPushButton("Next");


    buttons_Layout->addWidget(add_button);
    buttons_Layout->addWidget(delete_button);
    buttons_Layout->addWidget(update_button);


    buttons_Layout1->addWidget(filter_button,0,Qt::AlignCenter);

    buttons_Layout2->addStretch();
    buttons_Layout2->addWidget(greater_button,Qt::AlignCenter);
    buttons_Layout2->addStretch();
    buttons_Layout2->setAlignment(Qt::AlignVCenter);


    Right_Layout = new QFormLayout();
    Right_Layout->addRow(allsongs_title);
    Right_Layout->addRow(allsongs_label);
    Right_Layout->addRow(title_label, title_text);
    Right_Layout->addRow(artist_label, artist_text);
    Right_Layout->addRow(duration_label, duration_text);
    Right_Layout->addRow(link_label,link_text);
    Right_Layout->addRow(add_button);
    Right_Layout->addRow(buttons_Layout);
    Right_Layout->addRow(buttons_Layout1);

    Mid_Layout = new QFormLayout();
    Mid_Layout->addRow(buttons_Layout2);
    buttons_Layout2->setAlignment(Qt::AlignVCenter);

    Left_Layout = new QFormLayout;
    Left_Layout->addRow(playlist_label);
    Left_Layout->addRow(playlist_text);
    Left_Layout->addRow(play_button,next_button);

    main_Layout->addLayout(Right_Layout);
    main_Layout->addStretch();
    main_Layout->addLayout(Mid_Layout);
    main_Layout->addStretch();
    main_Layout->addLayout(Left_Layout);
    main_Layout->setAlignment(Right_Layout,Qt::AlignLeft);
    main_Layout->setAlignment(Mid_Layout,Qt::AlignCenter);
    main_Layout->setAlignment(Left_Layout,Qt::AlignRight);


    central_Widget->setLayout(main_Layout);

    connect(add_button,&QPushButton::clicked,this,&MainWindow::add_song);
    connect(delete_button,&QPushButton::clicked,this,&MainWindow::delete_song);
    connect(greater_button,&QPushButton::clicked,this,&MainWindow::add_to_playlist);
    connect(update_button,&QPushButton::clicked,this,&MainWindow::display_message);
    connect(filter_button,&QPushButton::clicked,this,&MainWindow::display_message);

    this->setCentralWidget(central_Widget);

}
void MainWindow::display_message()
{
    QMessageBox::information(this,"Message","Not implemented yet");
}
void MainWindow::display_all_songs()
{
    int nr=1;
    for(const auto& song : all_songs)
    {

        allsongs_label->addItem(QString::number(nr) + ". " + song.title);
        nr++;
    }
}
void MainWindow::display_playlist()
{
    playlist_text->clear();
    int nr=1;
    for(const auto& song : playlist)
    {
        playlist_text->append(QString::number(nr) + ". " + song.title);
        nr++;
    }
}

void MainWindow::add_song()
{
    QString title = title_text->text();
    QString artist = artist_text->text();
    QString duration = duration_text->text();
    QString link = link_text->text();

    title_text->clear();
    artist_text->clear();
    duration_text->clear();
    link_text->clear();

    Song newsong(title,artist,link,duration);

    if(title!=""&&artist!=""&&duration!=""&&link!="")
    {
        all_songs.push_back(newsong);
        allsongs_label->clear();
        display_all_songs();
    }
}
void MainWindow::delete_song()
{
    QListWidgetItem* song = allsongs_label->currentItem();
    int i = allsongs_label->row(song);
    if(song)
    {
        delete allsongs_label->takeItem(i);
        all_songs.erase(all_songs.begin()+i);
    }
    allsongs_label->clear();
    display_all_songs();
    display_playlist();

}
void MainWindow::add_to_playlist()
{
    QListWidgetItem* song = allsongs_label->currentItem();
    int i = allsongs_label->row(song);
    Song s=all_songs.at(i);
    if(song)
    {
        playlist.push_back(s);
        display_playlist();
    }
}
MainWindow::~MainWindow()
{
}

