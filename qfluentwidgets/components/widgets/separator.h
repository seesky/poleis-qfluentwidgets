#pragma once

#include <QtCore/Qt>
#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtWidgets/QWidget>

#include "../../common/style_sheet.h"

class QFLUENTWIDGETS_EXPORT HorizontalSeparator : public QWidget{
    Q_OBJECT
public:
    HorizontalSeparator(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
};


class QFLUENTWIDGETS_EXPORT VerticalSeparator : public QWidget{
    Q_OBJECT
public:
    VerticalSeparator(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
};