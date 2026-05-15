#pragma once

#include <QtCore/QEvent>
#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtCore/QPoint>
#include <QtCore/QTimer>
#include <QtCore/Qt>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QSize>
#include <QtGui/QColor>
#include <QtGui/QCursor>
#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "../../common/style_sheet.h"

enum class ToolTipPosition{
    TOP = 0,
    BOTTOM = 1,
    LEFT = 2,
    RIGHT = 3,
    TOP_LEFT = 4,
    TOP_RIGHT = 5,
    BOTTOM_LEFT = 6,
    BOTTOM_RIGHT = 7
};

class QFLUENTWIDGETS_EXPORT ToolTip : public QFrame{
    Q_OBJECT
public:
    ToolTip(QString text, QWidget *parent);
    QString text();
    void setText(QString text);
    int duration();
    void setDuration(int duration);
    void __setQss();
    QFrame *_createContainer();
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;
    void adjustPos(QWidget *widget, ToolTipPosition position);

    QString __text;
    int __duration;
    QFrame *container;
    QTimer *timer;
    QHBoxLayout *containerLayout;
    QLabel *label;
    QPropertyAnimation *opacityAni;
    QGraphicsDropShadowEffect *shadowEffect;
};


class QFLUENTWIDGETS_EXPORT ToolTipPositionManager{
public:
    QPoint position(ToolTip *tooltip, QWidget *parent);
    virtual QPoint _pos(ToolTip *tooltip, QWidget *parent);
    static ToolTipPositionManager* make(ToolTipPosition position);
};


class QFLUENTWIDGETS_EXPORT TopToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT BottomToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT LeftToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT RightToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};



class QFLUENTWIDGETS_EXPORT TopRightToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT TopLeftToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT BottomRightToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT BottomLeftToolTipManager : public ToolTipPositionManager{
public:
    QPoint _pos(ToolTip *tooltip, QWidget *parent) override;
};


class QFLUENTWIDGETS_EXPORT ToolTipFilter : public QObject{
    Q_OBJECT
public:
    ToolTipFilter(QWidget *parent, int showDelay, ToolTipPosition position);
    bool eventFilter(QObject *watched, QEvent *event) override;
    ToolTip *_createToolTip();
    void hideToolTip();
    void showToolTip();
    void setToolTipDelay(int delay);
    virtual bool _canShowToolTip();

    bool isEnter;
    ToolTip *_tooltip;
    int _tooltipDelay;
    ToolTipPosition position;
    QTimer *timer;
};