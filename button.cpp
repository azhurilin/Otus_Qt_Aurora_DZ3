#include "button.h"
#include <QPainter>
#include <QDebug>

Button::Button(QObject* parent)
{}

Button::~Button()
{}

void Button::paintEvent(QPaintEvent* event)
{
    QPainter p(this);

    QRect  BtnRect(0, 0,width(),height());

    QPalette pal = this->palette();

    p.setRenderHint(QPainter::Antialiasing);

    p.setPen(QPen(pal.text().color(), 4, Qt::SolidLine));
    p.setBrush(pal.button());
    p.setFont(QFont("Times", width()/5, QFont::Normal));

    p.drawRoundedRect(BtnRect, 10, 10);
    p.drawText(BtnRect, Qt::AlignCenter | Qt::TextWordWrap, this->text());

}



