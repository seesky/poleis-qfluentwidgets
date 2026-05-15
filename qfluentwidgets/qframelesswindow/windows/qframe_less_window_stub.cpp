#include "qframe_less_window.h"

WindowsFramelessWindow::WindowsFramelessWindow(QWidget *parent) : QWidget(parent)
{
    this->titleBar = nullptr;
    this->windowEffect = new WindowsWindowEffect(this);
    this->_isResizeEnabled = true;
}

void WindowsFramelessWindow::updateFrameless()
{
    this->setWindowFlag(Qt::FramelessWindowHint, true);
}

void WindowsFramelessWindow::setTitleBar(TitleBar *titleBar)
{
    this->titleBar = titleBar;
}

void WindowsFramelessWindow::setResizeEnabled(bool isEnabled)
{
    this->_isResizeEnabled = isEnabled;
}

void WindowsFramelessWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

bool WindowsFramelessWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    return QWidget::nativeEvent(eventType, message, result);
}

void WindowsFramelessWindow::__onScreenChanged()
{
}

AcrylicWindow::AcrylicWindow(QWidget *parent) : WindowsFramelessWindow(parent)
{
    this->__closeByKey = false;
}

void AcrylicWindow::updateFrameless()
{
    WindowsFramelessWindow::updateFrameless();
}

bool AcrylicWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    return WindowsFramelessWindow::nativeEvent(eventType, message, result);
}

void AcrylicWindow::closeEvent(QCloseEvent *event)
{
    QWidget::closeEvent(event);
}

FramelessDialog::FramelessDialog(QWidget *parent) : QDialog(parent)
{
    this->titleBar = nullptr;
    this->windowEffect = new WindowsWindowEffect(this);
    this->_isResizeEnabled = true;
}

void FramelessDialog::updateFrameless()
{
    this->setWindowFlag(Qt::FramelessWindowHint, true);
}

void FramelessDialog::setTitleBar(TitleBar *titleBar)
{
    this->titleBar = titleBar;
}

void FramelessDialog::setResizeEnabled(bool isEnabled)
{
    this->_isResizeEnabled = isEnabled;
}

void FramelessDialog::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
}

bool FramelessDialog::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    return QDialog::nativeEvent(eventType, message, result);
}

void FramelessDialog::__onScreenChanged()
{
}

FramelessMainWindow::FramelessMainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->titleBar = nullptr;
    this->windowEffect = new WindowsWindowEffect(this);
    this->_isResizeEnabled = true;
}

void FramelessMainWindow::updateFrameless()
{
    this->setWindowFlag(Qt::FramelessWindowHint, true);
}

void FramelessMainWindow::setTitleBar(TitleBar *titleBar)
{
    this->titleBar = titleBar;
}

void FramelessMainWindow::setResizeEnabled(bool isEnabled)
{
    this->_isResizeEnabled = isEnabled;
}

void FramelessMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

bool FramelessMainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    return QMainWindow::nativeEvent(eventType, message, result);
}

void FramelessMainWindow::__onScreenChanged()
{
}
