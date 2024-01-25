
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "song.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
using namespace std;
//listwidget
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void add_song();
    void delete_song();
    void display_playlist();
    void display_all_songs();
    void add_to_playlist();
    void display_message();
private:
    vector<Song> all_songs;
    vector<Song> playlist;
    QWidget* central_Widget;
    QFormLayout *Left_Layout;
    QFormLayout *Mid_Layout;
    QFormLayout *Right_Layout;
    QHBoxLayout* main_Layout;
    QHBoxLayout* buttons_Layout;
    QHBoxLayout* buttons_Layout1;
    QVBoxLayout* buttons_Layout2;
    QLabel* allsongs_title;
    QListWidget* allsongs_label;
    QLabel* title_label;
    QLineEdit* title_text;
    QLabel* artist_label;
    QLineEdit* artist_text;
    QLabel* duration_label;
    QLineEdit* duration_text;
    QLabel* link_label;
    QLineEdit* link_text;
    QLabel* playlist_label;
    QTextEdit* playlist_text;
    QPushButton* add_button;
    QPushButton* delete_button;
    QPushButton* update_button;
    QPushButton* filter_button;
    QPushButton* greater_button;
    QPushButton* play_button;
    QPushButton* next_button;
};

#endif // MAINWINDOW_H
