#pragma once

#include <QtCore/Qt>
#include <QtCore/QSize>
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include <QtGui/QPalette>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStyledItemDelegate>
#include <QtWidgets/QStyle>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QApplication>

#include "../../common/style_sheet.h"
#include "../../common/font.h"
#include "scroll_bar.h"

class TreeView;
class QFLUENTWIDGETS_EXPORT TreeItemDelegate : public QStyledItemDelegate{
    Q_OBJECT
public:
    TreeItemDelegate(QTreeView *parent);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const override;
};



class QFLUENTWIDGETS_EXPORT TreeWidget : public QTreeWidget{
    Q_OBJECT
public:
    TreeWidget(QWidget *parent);
    void drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const override;
    void setBorderVisible(bool isVisible);
    void setBorderRadius(int radius);

    SmoothScrollDelegate *scrollDelagate;
};



class QFLUENTWIDGETS_EXPORT TreeView : public QTreeView{
    Q_OBJECT
public:
    TreeView(QWidget *parent);
    void drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const override;
    void setBorderVisible(bool isVisible);
    void setBorderRadius(int radius);

    SmoothScrollDelegate *scrollDelagate;
};