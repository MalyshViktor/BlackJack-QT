#ifndef SOUNDS_H
#define SOUNDS_H
#include<QMediaPlayer>

class Sounds: public QMediaPlayer
{
public:
    Sounds();
    void bgAudio();
private:
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
};

#endif // SOUNDS_H
