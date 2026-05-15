#pragma once

#include <QtGui/QEnterEvent>

#include <QtCore/Qt>
#include <QtCore/QUrl>
#include <QtCore/QSizeF>
#include <QtCore/QTimer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include "../common/style_sheet.h"
#include "../multimedia/media_play_bar.h"

/*
class QFLUENTWIDGETS_EXPORT GraphicsVideoItem : public QGraphicsVideoItem{
    Q_OBJECT
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
*/


class QFLUENTWIDGETS_EXPORT VideoWidget : public QWidget{
    Q_OBJECT
public:
    VideoWidget(QWidget *parent);
    void setVideo(QUrl url);
    void hideEvent(QHideEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    
    void play();
    void pause();
    void stop();
    void togglePlayState();
    void resizeEvent(QResizeEvent *event) override;
    QVariant *player();

    bool isHover;
    QTimer *timer;
    QVBoxLayout *vBoxLayout;
    QVideoWidget *videoItem;
    StandardMediaPlayBar *playBar;

public slots:
    void _onHideTimeOut();
};
