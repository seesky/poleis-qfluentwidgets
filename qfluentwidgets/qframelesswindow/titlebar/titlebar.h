#pragma once

#include "title_bar_buttons.h"
#include <QtCore/QEvent>
#include <QtCore/Qt>
#include <QtGui/QIcon>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#ifdef Q_OS_WIN
#include "../utils/win32_utils.h"
#endif

class QFLUENTWIDGETS_EXPORT TitleBarBase : public QWidget{
    Q_OBJECT
public:
    TitleBarBase(QWidget *parent);
    bool eventFilter(QObject *watched, QEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool _isDragRegion(QPoint *pos);
    bool _hasButtonPressed();
    virtual bool canDrag(QPoint *pos);
    void setDoubleClickEnabled(bool isEnabled);

    MinimizeButton *minBtn;
    CloseButton *closeBtn;
    MaximizeButton *maxBtn;
    bool _isDoubleClickEnabled;
private:
public slots:
    void __toggleMaxState();
};

class QFLUENTWIDGETS_EXPORT TitleBar : public TitleBarBase{
    Q_OBJECT
public:
    TitleBar(QWidget *parent);
    QHBoxLayout *hBoxLayout;
private:
};

class QFLUENTWIDGETS_EXPORT StandardTitleBar : public TitleBar{
    Q_OBJECT
public:
    StandardTitleBar(QWidget *parent);


    QLabel *iconLabel;
    QLabel *titleLabel;

private:
public slots:
    void setTitle(QString title);
    //void setIcon(QVariant *icon);
    void setIcon(QIcon icon);
};
