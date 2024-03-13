#ifndef PPZUDELEGATE_H
#define PPZUDELEGATE_H

#include <QObject>

#include <QApplication>

#include <QStyledItemDelegate>
#include <QAbstractItemDelegate>

#include <QPainter>
#include <QSlider>
#include <QLCDNumber>

#include <QStyleOptionViewItem>
#include <QModelIndex>

#include <QTextOption>


class PPZUDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PPZUDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent)
    {}

    virtual ~PPZUDelegate()
    {}


//=====================*******=====================
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {

    int value = index.data().toInt();

    QStyleOptionProgressBar progressBar;
    progressBar.minimum = 0;
    progressBar.maximum = 1024;
    progressBar.rect = option.rect;
    progressBar.progress = value;

    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBar, painter);
     {
      painter->save();

      QTextOption toptions(Qt::AlignCenter);

      painter->setPen(Qt::darkGreen);
      painter->drawText(option.rect, QString::number(value, 16), toptions);
      painter->restore();

     }

    }
//=====================*******=====================
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
     {


      QLCDNumber * editor = new QLCDNumber(parent);
      editor->setMode(QLCDNumber::Hex);
      editor->setAutoFillBackground(true);

      return editor;
     }
//=====================*******=====================
    void setEditorData(QWidget *editor, const QModelIndex &index) const
    {
      QLCDNumber* lcdnumber = static_cast<QLCDNumber*>(editor);
      lcdnumber->setProperty("value", QVariant(index.data().toInt()));

    }
//=====================*******=====================
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
    {
      QLCDNumber* lcdnumber = static_cast<QLCDNumber*>(editor);
      model->setData(index, lcdnumber->value());

    }
//=====================*******=====================
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
     editor->setGeometry(option.rect);
    }

//=====================*******=====================
};

#endif // PPZUDELEGATE_H
