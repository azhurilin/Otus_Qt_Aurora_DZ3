#include "switch.h"
#include <QPainter>
#include <QDebug>



Switch::Switch(QObject* parent)
{}

Switch::~Switch()
{}

void Switch::paintEvent(QPaintEvent* event)
{
    QPainter p(this);

    QPalette pal = this->palette();

    p.setRenderHint(QPainter::Antialiasing);




    p.setPen(QPen(pal.text().color(), 4, Qt::SolidLine));
    p.setBrush(pal.button());
    p.setFont(QFont("Times", width()/8, QFont::Normal));

    QRect  lineRect(0.05*width(), 0.05*height(), 0.95*width(), 0.95*height());
    p.drawRect(lineRect);



    p.setPen(Qt::yellow);
    p.setBrush(Qt::blue);
    QRect  circleRect(0, 0, 0.3*width(), height());





    switch (checkState())
    {
    case Qt::Unchecked:
    {
       circleRect = circleRect.translated(0.1*width(), 0);
    }
        break;
    case Qt::PartiallyChecked:
    {

       circleRect = circleRect.translated(0.4*width(), 0);
    }
        break;
    case Qt::Checked:
    {

        circleRect = circleRect.translated(0.7*width(), 0);
    }
        break;
    }

    p.drawRoundedRect(circleRect, 10, 10);


    p.setPen(Qt::white);
    p.drawText(0.15, height(), this->Transparant1 );
    p.drawText(0.4*width(), height(), this->Transparant3);
    p.drawText(0.7*width(), height(), this->Transparant2);


}
