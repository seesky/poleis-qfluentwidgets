#pragma once

#include <QtCore/QTranslator>
#include <QtCore/QLocale>
#include <QtCore/QDebug>

class QFLUENTWIDGETS_EXPORT FluentTranslator : public QTranslator{
    Q_OBJECT
public:
    FluentTranslator(QLocale *locale, QObject *parent);
    void load(QLocale *locale);
};