#ifndef SWITCH_H
#define SWITCH_H

#include <QCheckBox>
#include <QObject>
#include <QPushButton>

#include <QPaintEvent>

class Switch : public QCheckBox
{
    Q_OBJECT
public:
    Switch(QObject* parent = nullptr);
    ~Switch();

    void setTransparant(QString S, int pos)
    {

      switch (pos)
      {
       case 1:
        {Transparant1 = S;}
       break;
       case 2:
        {Transparant2 = S;}
        break;
       case 3:
        {Transparant3 = S;}
        break;
      }

    }

protected:
    void paintEvent(QPaintEvent* event) override;

    QString Transparant1;
    QString Transparant2;
    QString Transparant3;


};


#endif // SWITCH_H
