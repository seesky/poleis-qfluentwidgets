#pragma once

#include <QtCore/Qt>
#include <QtGui/QCloseEvent>
#include <QtGui/QCursor>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMainWindow>
#include <QtGui/QScreen>
#include "../titlebar/titlebar.h"
#ifdef Q_OS_WIN
#include "../utils/win32_utils.h"
#include "window_effect.h"
#else
class QFLUENTWIDGETS_EXPORT WindowsWindowEffect{
public:
    WindowsWindowEffect(void *){}
    void setAcrylicEffect(void *, QString = QString(), bool = true, int = 0){}
    void setMicaEffect(void *, bool = false, bool = false){}
    void setAeroEffect(void *){}
    void removeBackgroundEffect(void *){}
    void addShadowEffect(void *){}
    void addMenuShadowEffect(void *){}
    void removeShadowEffect(void *){}
    static void removeMenuShadowEffect(void *){}
    static void addWindowAnimation(void *){}
    static void disableMaximizeButton(void *){}
    void enableBlurBehindWindow(void *){}
};
#endif

class QFLUENTWIDGETS_EXPORT WindowsFramelessWindow : public QWidget{
    Q_OBJECT
public:
    WindowsFramelessWindow(QWidget *parent);
    void updateFrameless();
    void setTitleBar(TitleBar *titleBar);
    void setResizeEnabled(bool isEnabled);
    void resizeEvent(QResizeEvent *event);
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
    int BORDER_WIDTH = 5;

    TitleBar *titleBar;
    WindowsWindowEffect *windowEffect;
    bool _isResizeEnabled;
private:
public slots:
    void __onScreenChanged();
};


class QFLUENTWIDGETS_EXPORT AcrylicWindow : public WindowsFramelessWindow{
    Q_OBJECT
public:
    AcrylicWindow(QWidget *parent);
    void updateFrameless();
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
    void closeEvent(QCloseEvent *event);

    bool __closeByKey;
private:
};


class QFLUENTWIDGETS_EXPORT FramelessDialog : public QDialog{
    Q_OBJECT
public:
    FramelessDialog(QWidget *parent);
    void updateFrameless();
    void setTitleBar(TitleBar *titleBar);
    void setResizeEnabled(bool isEnabled);
    void resizeEvent(QResizeEvent *event);
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
    int BORDER_WIDTH = 5;

    TitleBar *titleBar;
    WindowsWindowEffect *windowEffect;
    bool _isResizeEnabled;
private:
public slots:
    void __onScreenChanged();

};

class QFLUENTWIDGETS_EXPORT FramelessMainWindow : public QMainWindow{
    Q_OBJECT
public:
    FramelessMainWindow(QWidget *parent);void updateFrameless();
    void setTitleBar(TitleBar *titleBar);
    void setResizeEnabled(bool isEnabled);
    void resizeEvent(QResizeEvent *event);
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
    int BORDER_WIDTH = 5;

    TitleBar *titleBar;
    WindowsWindowEffect *windowEffect;
    bool _isResizeEnabled;
private:
public slots:
    void __onScreenChanged();
};
