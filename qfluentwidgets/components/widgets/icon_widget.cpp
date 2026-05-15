#include "icon_widget.h"

IconWidget::IconWidget(QWidget *parent) : QWidget(parent)
{
    this->ownsIcon = false;
    this->setOwnedIcon(QVariant::fromValue<QIcon>(QIcon()));
}


IconWidget::IconWidget(QVariant *icon, QWidget *parent) : QWidget(parent)
{
    this->ownsIcon = false;
    this->setIcon(icon);
}


IconWidget::IconWidget(FluentIcon icon, QWidget *parent) : QWidget(parent)
{
    this->ownsIcon = false;
    QVariant ownedIcon;
    ownedIcon.setValue(icon);
    this->setOwnedIcon(ownedIcon);
}

IconWidget::IconWidget(InfoBarIcon *icon, QWidget *parent)
{
    this->ownsIcon = false;
    QVariant ownedIcon;
    ownedIcon.setValue(icon);
    this->setOwnedIcon(ownedIcon);
}

IconWidget::IconWidget(QIcon icon, QWidget *parent) : QWidget(parent)
{
    this->ownsIcon = false;
    QVariant ownedIcon;
    ownedIcon.setValue(icon);
    this->setOwnedIcon(ownedIcon);
}

IconWidget::IconWidget(QString icon, QWidget *parent)
{
    this->ownsIcon = false;
    QVariant ownedIcon;
    ownedIcon.setValue(icon);
    this->setOwnedIcon(ownedIcon);
}

IconWidget::~IconWidget()
{
    if(this->ownsIcon){
        delete this->_icon;
    }
}

QIcon IconWidget::getIcon()
{
    return MIcon().toQIcon(this->_icon);
}

void IconWidget::setIcon(QVariant *icon)
{
    if(this->ownsIcon){
        delete this->_icon;
        this->ownsIcon = false;
    }
    this->_icon = icon;
    this->update();
}

void IconWidget::setOwnedIcon(const QVariant &icon)
{
    if(this->ownsIcon){
        delete this->_icon;
    }
    this->_icon = new QVariant(icon);
    this->ownsIcon = true;
    this->update();
}

void IconWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    MIcon().drawIcon(this->_icon, &painter, this->rect(), nullptr, QIcon::State::Off);
}






