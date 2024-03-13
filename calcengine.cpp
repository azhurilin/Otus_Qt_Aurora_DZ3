#include "calcengine.h"
#include "ppzudelegate.h"

#include <math.h>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QStandardItem>


#include <QCoreApplication>
#include <QPushButton>
#include <QScrollBar>
#include <QDebug>
#include <QObject>
#include <QSignalBlocker>
#include <QBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QTableView>



//DataBase=====================*******==========================================*******=====================
void CalcEngine::connectPPZUDB()
{
  auto PPZUconnect = QSqlDatabase::addDatabase("QSQLITE");

  PPZUconnect.setDatabaseName("ppzudb.sqlite");

  if(!PPZUconnect.open())  qDebug()<<PPZUconnect.lastError().text();
   else qDebug()<< "PPZU connected";
}
//=====================*******==========================================*******=====================
void CalcEngine::setupPPZUDB()
{
  QSqlQuery query;

  query.prepare("CREATE TABLE pmemory(ceil INTEGER, value INTEGER DEFAULT 0, rwcikl INTEGER DEFAULT 0)");


  if(!query.exec())
  {
   qDebug()<<query.lastError().text();
   return;
  }
  else qDebug()<< "table pmemory created";


  for(int i=0; i<1024; i++)
    {
       this->writePPZUDB(i, i);
    }


}
//=====================*******==========================================*******=====================
void CalcEngine::writePPZUDB(qint32 ceil, qint32 value)
{
  QSqlQuery query;

  query.prepare("INSERT INTO pmemory(ceil, value, rwcikl) VALUES(:ceil, :value, :rwcikl)");
  query.bindValue(":ceil", ceil);
  query.bindValue(":value", value);
  query.bindValue(":rwcikl", 3000);

  if(!query.exec())
  {
   qDebug()<<query.lastError().text();
   return;
  }
  else qDebug()<< "ceil writed";

}
//=====================*******==========================================*******=====================
void CalcEngine::updatePPZUDB(qint32 uceil, qint32 uvalue)
{
  QSqlQuery query;

  query.prepare("UPDATE pmemory SET value = ? WHERE ceil = ?");
  query.bindValue( 0, uvalue);
  query.bindValue( 1, uceil);

  if(!query.exec())
  {
   qDebug()<<query.lastError().text();
   return;
  }
  else qDebug()<< "ceil "<< uceil <<" updated";

}
//=====================*******==========================================*******=====================
int CalcEngine::readPPZUDB(int rceil)
{
  QSqlQuery query;

  query.prepare("SELECT value FROM pmemory WHERE ceil = ?");
  query.bindValue( 0, rceil);


  if(!query.exec())
  {
   qDebug()<<query.lastError().text();
   return 0;
  }
  else
   {
    query.first();
    qDebug()<< "ceil "<< rceil <<"read"<< query.value(0).toString();

    return query.value(0).toInt();
   }

}
//=====================*******==========================================*******=====================
void CalcEngine::createDialog(QDialog * parent)
{

     qDebug()<< "PPZU parent  " << parent->objectName();

     QDialog * PPZU_E = new QDialog(parent);

     QTableView * PPZUtableView_E = new QTableView(PPZU_E);
     QHBoxLayout * PPZUlayout_E = new QHBoxLayout;
     PPZUDelegate * MyDelegate = new PPZUDelegate(PPZUtableView_E);

     PPZUlayout_E->addWidget(PPZUtableView_E);
     PPZU_E->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

     PPZU_E->setLayout(PPZUlayout_E);

     PPZU_E->setGeometry(50, 50, 800, 400);
     PPZU_E->setLayout(PPZUlayout_E);
     PPZUtableView_E->setItemDelegate(MyDelegate);

//=====================*******=====================

     PPZUmodel = new QStandardItemModel(this);
     PPZUmodel->setColumnCount(8);
     PPZUmodel->setRowCount(128);

      int DBvalue=0;

      for(int r=0; r < PPZUmodel->rowCount(); r++)
       {
        for (int c=0; c < PPZUmodel->columnCount(); c++)
         {
          DBvalue = this->readPPZUDB(r*PPZUmodel->columnCount() + c);

          QStandardItem * item = new QStandardItem(QString::number(DBvalue));

          PPZUmodel->setItem(r, c, item);
         }

       }

      PPZUtableView_E->setModel(PPZUmodel);

      PPZU_E->show();
      vmemory_flag =1;

}
//=====================*******==========================================*******=====================
//=====================*******==========================================*******=====================
CalcEngine::CalcEngine(QObject *parent) : QObject(parent)
{

      RX=0;

      qDebug()<<"CalcEngine create";

//=====================*******=====================
      qDebug() << QSqlDatabase::QSqlDatabase::drivers();

      this->connectPPZUDB();

}

//=====================*******==========================================*******=====================
CalcEngine::~CalcEngine()
{

 /*    QString DBvalue=0;

      for(int r=0; r < PPZUmodel->rowCount(); r++)
       {
        for (int c=0; c < PPZUmodel->columnCount(); c++)
         {

          DBvalue = PPZUmodel->item(r,c)->text();

         // this->writePPZUDB(r*PPZUmodel->columnCount() + c,  DBvalue.toInt());

         }
       }
*/


  qDebug()<<"CalcEngine destroy";

}
//=====================*******==========================================*******=====================
void CalcEngine::AddDigit(int d)
{
    if (Calc_flag) {RX = 0; RX_E = 0; Calc_flag = 0; Point_flag = 0;}

    RX= RX*10 + d;

    if(Point_flag) RX_E++;

    dRX = RX / pow(10, RX_E);

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_1()
{
    qDebug()<<"Button 1 pressed";

    AddDigit(1);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_2()
{
    qDebug()<<"Button 2 pressed";

    AddDigit(2);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_3()
{
    qDebug()<<"Button 3 pressed";

    AddDigit(3);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_4()
{
    qDebug()<<"Button 4 pressed";

    AddDigit(4);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_5()
{
    qDebug()<<"Button 5 pressed";

    AddDigit(5);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_6()
{
    qDebug()<<"Button 6 pressed";

    AddDigit(6);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_7()
{
    qDebug()<<"Button 7 pressed";

    AddDigit(7);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_8()
{
    qDebug()<<"Button 8 pressed";

    AddDigit(8);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_9()
{
    qDebug()<<"Button 9 pressed";

    AddDigit(9);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_B_10()
{
    qDebug()<<"Button 0 pressed";

    AddDigit(0);
    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_enter()
{
    qDebug()<<"Button enter pressed";

    RT = RZ;  RT_E = RZ_E;
    RZ = RY;  RZ_E = RY_E;
    RY = RX;  RY_E = RX_E;
    RX = 0;   RX_E = 0;

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_swap()
{
    qDebug()<<"Button swap pressed";

    quint64  tmp = 0;  quint16 tmp_E = 0;

    tmp = RY;  tmp_E = RY_E;
    RY = RX;  RY_E = RX_E;
    RX = tmp;  RX_E = tmp_E;

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_sign()
{
    qDebug()<<"Button sign pressed";

    RX = -RX;

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_add()
{
    qDebug()<<"Button addition pressed";

//    quint64  tmpRX = 0;  quint16 tmpRX_E = 0;
//    quint64  tmpRY = 0;  quint16 tmpRY_E = 0;


 //  if (RX_E >= RY_E) {RY = RY * pow(10, RX_E - RY_E); RY_E = RX_E;}
 //   else {RX = RX * pow(10, RY_E - RX_E); RX_E = RY_E;}





    emit signal_updateISD();
}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_RX_M()
{
    qDebug()<<"Button X->П pressed";


     updatePPZUDB(RX, RY);

     int r =  RX/PPZUmodel->columnCount();
     int c =  RX % PPZUmodel->columnCount();

    // qDebug() << r << " " << c;

     this->PPZUmodel->item(r,c)->setData(RY, Qt::DisplayRole);

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_btn_M_RX()
{
    qDebug()<<"Button П->X pressed";

   int tmp = readPPZUDB(RX);
   RX = tmp;

   emit signal_updateISD();

}
//=====================*******==========================================*******=====================
void CalcEngine::slot_clear()
{

     qDebug()<<"Button clear pressed";

    RX = 0; RX_E = 0;

    Point_flag = 0;

    emit signal_updateISD();

}
//=====================*******==========================================*******=====================







//=====================*******==========================================*******=====================

double CalcEngine::GetRX() {

     //return RX / pow(10, RX_E);

     return dRX;

     }
//=====================*******=====================
void CalcEngine::DelDigit()
{
    RX = RX / 10; if(RX_E > 0) RX_E--;

    dRX = dRX / 10;
}
//=====================*******=====================



//=====================*******=====================
void CalcEngine::slot_btn_F()
{
     qDebug()<<"Button F pressed";

     emit signal_updateISD();
}
//=====================*******=====================

void CalcEngine::slot_sub()
{
    qDebug()<<"Button subtraction pressed";



    emit signal_updateISD();
}
//=====================*******=====================
void CalcEngine::slot_mul()
{
    qDebug()<<"Button multiply pressed";


    emit signal_updateISD();
}
//=====================*******=====================
void CalcEngine::slot_div()
{
    qDebug()<<"Button division pressed";



    emit signal_updateISD();
}

//=====================*******=====================



//=====================*******=====================
QString CPrint(){

return "CalcEngine";
}
//=====================*******=====================


