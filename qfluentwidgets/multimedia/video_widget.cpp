#include "video_widget.h"

/*
void GraphicsVideoItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setCompositionMode(QPainter::CompositionMode_Difference);
}
*/

VideoWidget::VideoWidget(QWidget *parent) : QWidget(parent)
{
    this->isHover = false;
    this->timer = new QTimer(this);

    this->vBoxLayout = new QVBoxLayout(this);
    this->videoItem = new QVideoWidget(this);
    this->playBar = new StandardMediaPlayBar(this);

    this->setMouseTracking(true);
    this->vBoxLayout->setContentsMargins(0, 0, 0, 0);
    this->vBoxLayout->addWidget(this->videoItem);

    this->player()->value<MediaPlayer*>()->setVideoOutput(this->videoItem);
    FluentStyleSheet().apply(this, FluentStyleSheetMap.value("MEDIA_PLAYER"), Theme::AUTO);

    connect(this->timer, &QTimer::timeout, this, &VideoWidget::_onHideTimeOut);
}


void VideoWidget::setVideo(QUrl url)
{
    this->player()->value<MediaPlayer*>()->setSource(url);
}


void VideoWidget::hideEvent(QHideEvent *event)
{
    this->pause();
    event->accept();
}


void VideoWidget::wheelEvent(QWheelEvent *event)
{
    return;
}

void VideoWidget::enterEvent(QEnterEvent *event)
{
    this->isHover = true;
    this->playBar->fadeIn();
}

void VideoWidget::leaveEvent(QEvent *event)
{
    this->isHover = false;
    this->timer->start(3000);
}



void VideoWidget::_onHideTimeOut()
{
    if(!this->isHover){
        this->playBar->fadeOut();
    }
}


void VideoWidget::play()
{
    this->playBar->play();
}

void VideoWidget::pause()
{
    this->playBar->pause();
}


void VideoWidget::stop()
{
    this->playBar->pause();
}


void VideoWidget::togglePlayState()
{
    if(this->player()->value<MediaPlayer*>()->isPlaying()){
        this->pause();
    }else{
        this->play();
    }
}

void VideoWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    this->videoItem->setGeometry(this->rect());
    this->playBar->move(11, this->height() - this->playBar->height() - 11);
    this->playBar->setFixedSize(this->width() - 22, this->playBar->height());
}

QVariant *VideoWidget::player()
{
    return this->playBar->player;
}
