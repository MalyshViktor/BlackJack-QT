#include "playwindow.h"
#include "ui_playwindow.h"
#include "mainwindow.h"
#include<string>
#include<cstdlib>
#include"sounds.h"

#include <QTimer>


int betCoin = 0;
int simpleScore = 0;
int playerCredit = 1000;
QString betValue="";
QString deck[52] = { "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "c10", "cJ", "cQ", "cK", "cA",
                 "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "d10", "dJ", "dQ", "dK", "dA",
                 "h2", "h3", "h4", "h5", "h6", "h7", "h8", "h9", "h10", "hJ", "hQ", "hK", "hA",
                 "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "sJ", "sQ", "sK", "sA"};

int coins[6]={5,20,100,200,500,1000};
int playerScore = 0;
int dealerScore = 0;
int numOfCards = 0;
bool firstClick = false;
int plrCountA = 0;
int dlrCountA = 0;
int deskNumb = 0;

PlayWindow::PlayWindow(MainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow),
    parent(parent)
{
    ui->setupUi(this);
    //set background image
    this->setFixedSize(950,600);
    QPixmap pix(".//Blackjack_table.png");
    int w = ui->background->width();
    int h = ui->background->height();
    ui->background->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
    Sounds bg;
    bg.bgAudio();

    //shuffle
    srand(time(NULL));

    for (int i = 51; i >= 0; i--)
    {
        int j = rand() % (i + 1);

        QString tmp = deck[j];
        deck[j] = deck[i];
        deck[i] = tmp;
    }


    //ui->dealButton->setVisible(false);
    //ui->hitButton->setVisible(false);
    //ui->standButton->setVisible(false);

    ui->coin5->setEnabled(true);
    ui->coin20->setEnabled(true);
    ui->coin50->setEnabled(true);
    ui->coin100->setEnabled(true);
    ui->coin500->setEnabled(true);
    ui->coin1000->setEnabled(true);


}

void scoreCounter(int n, QString name = ""){
    int score = 0;
    int countA = 0;
    if (name == "p"){
        score = playerScore;
        countA = plrCountA;
    }
    if (name == "d"){
        score = dealerScore;
        countA = dlrCountA;
    }

    if(deck[n] == "c2"||deck[n] == "d2"||deck[n] == "h2"||deck[n] == "s2"){
        score += 2;
    }
    else if(deck[n]== "c3"||deck[n] == "d3"||deck[n] == "h3"||deck[n] == "s3"){
        score += 3;
    }
    else if(deck[n]== "c4"||deck[n] == "d4"||deck[n] == "h4"||deck[n] == "s4"){
        score += 4;
    }
    else if(deck[n]== "c5"||deck[n] == "d5"||deck[n] == "h5"||deck[n] == "s5"){
        score += 5;
    }
    else if(deck[n]== "c6"||deck[n] == "d6"||deck[n] == "h6"||deck[n] == "s6"){
        score += 6;
    }
    else if(deck[n]== "c7"||deck[n] == "d7"||deck[n] == "h7"||deck[n] == "s7"){
        score += 7;
    }
    else if(deck[n]== "c8"||deck[n] == "d8"||deck[n] == "h8"||deck[n] == "s8"){
        score += 8;
    }
    else if(deck[n]== "c9"||deck[n] == "d9"||deck[n] == "h9"||deck[n] == "s9"){
        score += 9;
    }
    else if(deck[n]== "c10"||deck[n] == "d10"||deck[n] == "h10"||deck[n] == "s10"
                    ||deck[n] == "cJ"||deck[n] == "dJ"||deck[n] == "hJ"||deck[n] == "sJ"
                    ||deck[n] == "cQ"||deck[n] == "dQ"||deck[n] == "hQ"||deck[n] == "sQ"
                    ||deck[n] == "cK"||deck[n] == "dK"||deck[n] == "hK"||deck[n] == "sK"){
        score += 10;
    }
    else if(deck[n]== "cA"||deck[n] == "dA"||deck[n] == "hA"||deck[n] == "sA"){
        score += 11;
        countA++;
    }

    if(score>21&&countA>=1)
    {
        countA-=1;
        score-=10;
    }
    if(name=="p")
    {
        score = playerScore;
        countA = plrCountA;
    }
    if(name=="d")
    {
        score = dealerScore;
        countA = dlrCountA;
    }
}

void PlayWindow::dealer()
{
    numOfCards = 2;
    ui->hitButton->setVisible(false);
    ui->standButton->setVisible(false);

    QPixmap dcard1(":/PlayingCards/cards/"+deck[2]+".png");
    ui->dCard1->setPixmap(dcard1.scaled(50,80, Qt::KeepAspectRatio));
    ui->dScore->setText(QString::number(dealerScore));

    if(playerScore>21){
        end();
    }else{
        while(dealerScore<17){

            QPixmap dcard1(":/PlayingCards/cards/"+deck[deskNumb]+".png");

            if(numOfCards == 2){
                ui->dCard3->setPixmap(dcard1);
            }else if(numOfCards==3){
                ui->dCard4->setPixmap(dcard1);
            }else if(numOfCards==4){
                ui->dCard5->setPixmap(dcard1);
            }else if(numOfCards==5){
               // ui->dCard6->setPixmap(d1);
            }else{
               // ui->dCard7->setPixmap(d1);
            }

            scoreCounter(deskNumb,"d");
            ui->dScore->setText(QString::number(dealerScore));

            deskNumb++;
            numOfCards++;
        }
    }

}

    void PlayWindow::end(){
     // ui->link->setPixmap(z1);
      if(playerScore>21){
            ui->link->setText("Dealer wins!");
           // ui->link->setText(":/images/lose.png");
        }else if(dealerScore>21){
            playerCredit+=betCoin*2;
            ui->link->setText("You win!");
        }else if(playerScore==dealerScore){
            playerCredit+=betCoin;
            ui->link->setText("Push!");
        }else if(playerScore>dealerScore){
            playerCredit+=betCoin*2;
            ui->link->setText("You win!");
        }else{
            ui->link->setText("Dealer wins!");
       //     ui->link->setText(":/images/lose.png");
        }
        ui->money->setText(QString::number(playerCredit).append(" $"));

        //QTimer::singleShot(5*1000, this, SLOT(nextGame()));

       // if(money==0){
        //   nextGame();
      //  }
    }

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::on_dealButton_clicked()
{

    ui->dealButton->setVisible(false);
    ui->hitButton->setVisible(true);
    ui->standButton->setVisible(true);

    ui->coin5->setHidden(true);
    ui->coin20->setHidden(true);
    ui->coin50->setHidden(true);
    ui->coin100->setHidden(true);
    ui->coin500->setHidden(true);
    ui->coin1000->setHidden(true);

    ui->betLabel->setVisible(true);
    ui->Bet->hide();
    ui->betValue->move(1000, 150);

    QPixmap pcard1(":/PlayingCards/cards/"+deck[deskNumb] +".png");
    QPixmap pcard2(":/PlayingCards/cards/"+deck[deskNumb+1] +".png");
    QPixmap dcard1(":/PlayingCards/cards/back100.png");
    QPixmap dcard2(":/PlayingCards/cards/"+deck[deskNumb+3] +".png");

    ui->pCard1->setPixmap(pcard1);
    ui->pCard2->setPixmap(pcard2);
    ui->dCard1->setPixmap(dcard1);
    ui->dCard2->setPixmap(dcard2);

    scoreCounter(deskNumb,"p"); scoreCounter(deskNumb+1,"p");
    scoreCounter(deskNumb+2,"d"); scoreCounter(3);
    dealerScore+=simpleScore;
}


void PlayWindow::on_hitButton_clicked()
{

    QPixmap p1(":/PlayingCards/cards/"+deck[deskNumb]+".png");


    if(numOfCards == 2){
        ui->pCard3->setPixmap(p1);
    }else if(numOfCards==3){
        ui->pCard4->setPixmap(p1);
    }else if(numOfCards==4){
        ui->pCard5->setPixmap(p1);
    }else if(numOfCards==5){
       // ui->pCard6->setPixmap(p1);
    }else{
       // ui->pCard7->setPixmap(p1);
    }

    scoreCounter(deskNumb,"p");
    ui->Score->setText(QString::number(playerScore));

    deskNumb++;
    numOfCards++;

    if(playerScore>=21){
        dealer();
    }
}


void PlayWindow::on_standButton_clicked()
{
    dealer();
}


void PlayWindow::on_actionquit_triggered()
{

}

