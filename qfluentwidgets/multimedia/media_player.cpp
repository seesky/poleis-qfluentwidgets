#include "media_player.h"

MediaPlayer::MediaPlayer(QWidget *parent) : QMediaPlayer(parent)
{
    this->audioOutputDevice = new QAudioOutput(this);
    this->setAudioOutput(this->audioOutputDevice);
}


bool MediaPlayer::isPlaying()
{   
    return this->playbackState() == QMediaPlayer::PlayingState;
}

int MediaPlayer::volume()
{
    return qRound(this->audioOutputDevice->volume() * 100.0);
}

bool MediaPlayer::isMuted()
{
    return this->audioOutputDevice->isMuted();
}

QUrl MediaPlayer::source()
{
    return QMediaPlayer::source();
}


void MediaPlayer::setSource(QUrl media)
{
    QMediaPlayer::setSource(media);
    emit(sourceChanged(media));
}

void MediaPlayer::setVolume(int volume)
{
    int boundedVolume = qBound(0, volume, 100);
    this->audioOutputDevice->setVolume(static_cast<float>(boundedVolume) / 100.0f);
    emit(volumeChanged(boundedVolume));
}

void MediaPlayer::setMuted(bool isMuted)
{
    this->audioOutputDevice->setMuted(isMuted);
    emit(mutedChanged(isMuted));
}
