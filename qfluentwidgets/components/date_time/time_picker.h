#pragma once

#include <QtCore/Qt>
#include <QtCore/QSize>
#include "picker_base.h"

class QFLUENTWIDGETS_EXPORT TimePickerBase : public PickerBase{
    Q_OBJECT
public:
    TimePickerBase(QWidget *parent, bool showSeconds);
    virtual QTime *getTime();
    virtual void setTime(QTime *time){};
    bool isSecondVisible();
    virtual void setSecondVisible(bool isVisible){};

    QTime *_time;
    bool _isSecondVisible;
signals:
    void timeChanged(QTime);
};

class QFLUENTWIDGETS_EXPORT MiniuteFormatter : public DigitFormatter{
    Q_OBJECT
public:
    QString encode(QVariant value) override;
};

class QFLUENTWIDGETS_EXPORT AMHourFormatter : public DigitFormatter{
    Q_OBJECT
public:
    QString encode(QVariant value) override;
};


class QFLUENTWIDGETS_EXPORT AMPMFormatter : public PickerColumnFormatter{
    Q_OBJECT
public:
    AMPMFormatter();
    QString encode(QVariant value) override;

    QString AM;
    QString PM;
};


class QFLUENTWIDGETS_EXPORT TimePicker : public TimePickerBase{
    Q_OBJECT
    Q_PROPERTY(QTime* time READ getTime WRITE setTime)
    Q_PROPERTY(bool secondVisible READ isSecondVisible WRITE setSecondVisible)
public:
    TimePicker(QWidget *parent, bool showSeconds);
    void setTime(QTime *time) override;
    void setSecondVisible(bool isVisible) override;
    void _onConfirmed(QList<QString> *value);
    QList<QString> *panelInitialValue();
    QTime *getTime() override;
    bool isSecondVisible();
};



class QFLUENTWIDGETS_EXPORT AMTimePicker : public TimePickerBase{
    Q_OBJECT
    Q_PROPERTY(QTime* time READ getTime WRITE setTime)
    Q_PROPERTY(bool secondVisible READ isSecondVisible WRITE setSecondVisible)
public:
    AMTimePicker(QWidget *parent, bool showSeconds);
    void setSecondVisible(bool isVisible) override;
    void setTime(QTime *time) override;
    void _onConfirmed(QList<QString> *value);
    QList<QString> *panelInitialValue();
    QTime *getTime() override;
    bool isSecondVisible();

    QString AM;
    QString PM;
};