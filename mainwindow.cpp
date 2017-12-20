#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include "microWaveLabel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    doorStatus = true;
    startToggle = true;
    stopToggle = true;

    microWaveDoor = new microWaveLabel("",this);
    QPixmap doorClosedPicture("c:/temp/mikrokiinni.jpg");
    microWaveDoor->setPixmap(doorClosedPicture);
    microWaveDoor->resize(550,350);
    microWaveDoor->move(25,25);
    QPixmap scaledPicture = doorClosedPicture.scaled(microWaveDoor->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    microWaveDoor->setPixmap(scaledPicture);
    connect(microWaveDoor, SIGNAL(microWaveClicked()), this, SLOT(doorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete microWaveDoor;
}


void MainWindow::on_dial_valueChanged(int value)
{
    timeLeft = value;
    ui->lcd->display(timeLeft);
}

void MainWindow::on_startButton_clicked()
{
    if(doorStatus == true)
    {
        if(startToggle == true)
        {
            Timer();
            startToggle = false;
            stopToggle = false;

        }
        if(stopToggle == true)
        {
            Timer();
            stopToggle = false;
        }
        else
        {
            return;
        }
    }
    if(doorStatus == false)
    {
        return;
    }
}

void MainWindow::timeUpdate()
{
    if(timeLeft >= 0)
    {
        ui->lcd->display(timeLeft);
        ui->dial->setValue(timeLeft);
        return;
    }
    else
    {
        timer->stop();
        Bling();
        startToggle = true;
        return;
    }
}

void MainWindow::on_stopButton_clicked()
{
    if(stopToggle == false)
    {
        timer->stop();
        stopToggle = true;
    }
    else
    {
        startToggle = true;
        stopToggle = true;
        timeLeft = 0;
        ui->lcd->display(timeLeft);
        ui->dial->setValue(timeLeft);
        return;
    }
}

void MainWindow::doorClicked()
{
    if(startToggle == true)
    {
        if(doorStatus == true)
        {
            qDebug()<<"klikattu";
            QPixmap doorOpened("c:/temp/mikroauki.JPG");
            QPixmap scaledPicture = doorOpened.scaled(microWaveDoor->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            microWaveDoor->setPixmap(scaledPicture);
            doorStatus = false;
        }
        else
        {
            qDebug()<<"klikattu";
            QPixmap doorClosedPicture("c:/temp/mikrokiinni.JPG");
            QPixmap scaledPicture = doorClosedPicture.scaled(microWaveDoor->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            microWaveDoor->setPixmap(scaledPicture);
            doorStatus = true;
        }
    }
    if(startToggle == false)
    {
        return;
    }
}

void MainWindow::on_avaaButton_clicked()
{
    if(startToggle == true)
    {
        if(doorStatus == true)
        {
            qDebug()<<"klikattu";
            QPixmap doorOpened("c:/temp/mikroauki.JPG");
            QPixmap scaledPicture = doorOpened.scaled(microWaveDoor->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            microWaveDoor->setPixmap(scaledPicture);
            doorStatus = false;
        }
    }
    if(startToggle == false)
    {
        return;
    }
}

void MainWindow::updateTime()
{
    if (!(--timeLeft))
    qDebug()<<timeLeft;
    timeUpdate();
}
