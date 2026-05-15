#pragma once

#include <QtCore/Qt>
#include <QtGui/QPainter>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QStyle>
#include <QtWidgets/QStyleOptionButton>
#include <QtWidgets/QWidget>

#include "../../common/icon.h"
#include "../../common/style_sheet.h"


const static std::map<QString, QString> CheckBoxIconMap = {
        {"ACCEPT", "Accept"},
        {"PARTIAL_ACCEPT", "PartialAccept"}
};

class QFLUENTWIDGETS_EXPORT CheckBoxIcon : public FluentIconBase{
public:
    QString path(Theme theme) override;
};


class QFLUENTWIDGETS_EXPORT CheckBox : public QCheckBox{
    Q_OBJECT
public:
    CheckBox(QWidget *parent);
    CheckBox(QString text, QWidget *parent);

    void paintEvent(QPaintEvent *e);
};