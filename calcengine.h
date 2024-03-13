#ifndef CALCENGINE_H
#define CALCENGINE_H


#include "ppzudelegate.h"

#include <QObject>
#include <QDebug>
#include <QDialog>

#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QBoxLayout>



//=====================*******==========================================*******=====================
class CalcEngine : public QObject
{
    Q_OBJECT

public:
    explicit CalcEngine(QObject *parent = nullptr);

            ~CalcEngine();


    QDialog * PPZU_E ;
    QStandardItemModel * PPZUmodel;

     QTableView * PPZUtableView_E;
     QHBoxLayout * PPZUlayout_E;
     PPZUDelegate * MyDelegate;


   void createDialog(QDialog * parent);


   void connectPPZUDB();
   void setupPPZUDB();
   void writePPZUDB(qint32 ceil, qint32 value);
   void updatePPZUDB(qint32 uceil, qint32 uvalue);
   int readPPZUDB(int ceil);


   void AddDigit(int d);




   double GetRX();

   void DelDigit();
   void CalcResult();

   QString CPrint();


//=====================*******=====================
signals:
    void signal_updateISD();


//=====================*******=====================
public slots:


void slot_btn_F();
void slot_btn_RX_M();
void slot_btn_M_RX();



void slot_btn_B_1();
void slot_btn_B_2();
void slot_btn_B_3();
void slot_btn_B_4();
void slot_btn_B_5();
void slot_btn_B_6();
void slot_btn_B_7();
void slot_btn_B_8();
void slot_btn_B_9();
void slot_btn_B_10();//0


void slot_enter();
void slot_swap();
void slot_sign();

void slot_add();
void slot_sub();
void slot_mul();
void slot_div();











//=====================*******==========================================*******=====================



//=====================*******=====================
    void slot_point(){
     qDebug()<<"Button point pressed";

    Point_flag = 1;

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_clear();
//=====================*******=====================


//=====================*******=====================
  void slotPrint()
    {
        qDebug()<<"CalcEngine";
    }
//=====================*******=====================
private:

   qint64  RX = 0;  qint16 RX_E = 0;
   qint64  RY = 0;  qint16 RY_E = 0;
   qint64  RZ = 0;  qint16 RZ_E = 0;
   qint64  RT = 0;  qint16 RT_E = 0;






   double  dRX = 0;
   double  dRY = 0;

   bool Point_flag = 0;


   bool Calc_flag = 0;


   bool Memory_flag = 0;
   bool vmemory_flag = 0;



 //  quint8  R1 = 0;



};
//=====================*******==========================================*******=====================
#endif // CALCENGINE_H
