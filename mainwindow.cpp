#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QMediaPlayer>
#include<string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,600);
    QPixmap bckgImage(".//PlayingCards//layer.png");
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->imageLabel->setPixmap(bckgImage.scaled(w,h, Qt::IgnoreAspectRatio));

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_startButton_clicked()
{
    playwindow = new PlayWindow(this);
    playwindow->show();
    this->hide();
}


void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_quitaction_triggered()
{

}

