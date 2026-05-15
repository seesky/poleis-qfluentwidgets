#pragma once

#include <QtGui/QEnterEvent>

#include <QtCore/QEvent>
#include <QtCore/Qt>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QEasingCurve>
#include <QtCore/QRectF>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtGui/QIcon>
#include <QtGui/QPainterPath>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>

#include "../../common/config.h"
#include "../../common/icon.h"
#include "../../common/style_sheet.h"
#include "setting_card.h"

class QFLUENTWIDGETS_EXPORT ExpandButton : public QAbstractButton{
    Q_OBJECT
    Q_PROPERTY(float angle READ getAngle WRITE setAngle)
public:
    ExpandButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void setHover(bool isHover);
    void setPressed(bool isPressed);
    float getAngle();
    void setAngle(float angle);

    bool isHover;
    bool isPressed;
    QPropertyAnimation *rotateAni;
    float __angle;

public slots:
    void __onClicked();

};


class QFLUENTWIDGETS_EXPORT SpaceWidget : public QWidget{
    Q_OBJECT
public:
    SpaceWidget(QWidget *parent);
};

class ExpandSettingCard;
class QFLUENTWIDGETS_EXPORT HeaderSettingCard : public SettingCard{
    Q_OBJECT
public:
    HeaderSettingCard(QVariant *icon, QString title, QString content, QWidget *parent);
    bool eventFilter(QObject *watched, QEvent *event) override;
    void addWidget(QWidget *widget);
    void paintEvent(QPaintEvent *event) override;

    ExpandButton *expandButton;
};


class QFLUENTWIDGETS_EXPORT ExpandBorderWidget : public QWidget{
    Q_OBJECT
public:
    ExpandBorderWidget(QWidget *parent);
    bool eventFilter(QObject *watched, QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
};


class QFLUENTWIDGETS_EXPORT ExpandSettingCard : public QScrollArea{
    Q_OBJECT
public:
    ExpandSettingCard(QVariant *icon, QString title, QString content, QWidget *parent);
    void __initWidget();
    void addWidget(QWidget *widget);
    void wheelEvent(QWheelEvent *e) override;
    void setExpand(bool isExpand);

    void resizeEvent(QResizeEvent *event) override;
    void _adjustViewSize();
    void setValue();

    bool isExpand;
    QFrame *scrollWidget;
    QFrame *view;
    HeaderSettingCard *card;
    QVBoxLayout *scrollLayout;
    QVBoxLayout *viewLayout;
    SpaceWidget *spaceWidget;
    ExpandBorderWidget *borderWidget;
    QPropertyAnimation *expandAni;

public slots:
    void _onExpandValueChanged();
    void toggleExpand();
};


class QFLUENTWIDGETS_EXPORT GroupSeparator : public QWidget{
    Q_OBJECT
public:
    GroupSeparator(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
};


class QFLUENTWIDGETS_EXPORT ExpandGroupSettingCard : public ExpandSettingCard{
    Q_OBJECT
public:
    ExpandGroupSettingCard(QVariant *icon, QString title, QString content, QWidget *parent);
    void addGroupWidget(QWidget *widget);
};