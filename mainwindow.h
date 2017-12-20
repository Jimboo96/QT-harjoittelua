#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtimer.h>
#include <QDebug>
#include <QLabel>
#include <QMultimedia>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Timer()
    {
    timer = new QTimer(this);
    this->connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    updateTime();
    timer->start(1000);
    }

    Bling()
    {
        player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("c:/temp/mikro.mp3"));
        volume: player->setVolume(50);
        player->play();
    }

    void timeUpdate();

private slots:

    void on_dial_valueChanged(int value);

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_avaaButton_clicked();

public slots:

    void updateTime();

    void doorClicked();

private:
    bool startToggle;
    bool stopToggle;
    bool doorStatus;
    int timeLeft;
    Ui::MainWindow *ui;
    QTimer* timer;
    QLabel *microWaveDoor;
    QMediaPlayer *player;
};

#endif // MAINWINDOW_H
