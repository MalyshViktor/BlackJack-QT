#include "sounds.h"

#include<QMediaPlayer>
#include<QAudioOutput>

Sounds::Sounds()
{

}

void Sounds::bgAudio()
{
    //play background music
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/sounds/sounds/casino.mp3"));
    player->setLoops(QMediaPlayer::Infinite);
    audioOutput->volumeChanged(0.05);
    player->play();
}
