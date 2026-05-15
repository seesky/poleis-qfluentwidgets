#pragma once

#include <QtCore/Qt>
#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QMediaPlayer>
#include <QtWidgets/QWidget>

class QFLUENTWIDGETS_EXPORT MediaPlayerBase : public QObject{
    Q_OBJECT
public:
    MediaPlayerBase(QWidget *parent) : QObject(parent){};
    virtual bool isPlaying(){ return false; };
    virtual QMediaPlayer::MediaStatus mediaStatus(){ return QMediaPlayer::NoMedia; };
    virtual QMediaPlayer::PlaybackState playbackState(){ return QMediaPlayer::StoppedState; };
    virtual int duration(){ return 0; };
    virtual QPoint position(){ return QPoint(); };
    virtual int volume(){ return 0; };
    virtual QUrl source(){ return QUrl(); };
    virtual void pause(){};
    virtual void play(){};
    virtual void stop(){};
    virtual float playbackRate(){ return 1.0f; };
    virtual void setPosition(int position){};
    virtual void setSource(QUrl media){};
    virtual void setPlaybackRate(float rate){};
    virtual void setVolume(int volume){};
    virtual void setMuted(bool isMuted){};
    virtual QObject *videoOutput(){ return nullptr; };
    virtual void setVideoOutput(QObject *output){};

signals:
    void mediaStatusChanged(QMediaPlayer::MediaStatus);
    void palybackRateChanged(float);
    void positionChanged(int);
    void durationChanged(int);
    void sourceChanged(QUrl);
    void volumeChanged(int);
    void mutedChanged(bool);
};



class QFLUENTWIDGETS_EXPORT MediaPlayer : public QMediaPlayer{
    Q_OBJECT
public:
    MediaPlayer(QWidget *parent);
    bool isPlaying();
    int volume();
    bool isMuted();
    QUrl source();
    void setSource(QUrl media);
    void setVolume(int volume);
    void setMuted(bool isMuted);

    QAudioOutput *audioOutputDevice;
signals:
    void sourceChanged(QUrl);
    void volumeChanged(int);
    void mutedChanged(bool);
};
