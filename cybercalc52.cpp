#include "cybercalc52.h"
#include "ui_cybercalc52.h"
#include "calcengine.h"

#include "ppzudelegate.h"

#include <QCoreApplication>
#include <QPushButton>
#include <QScrollBar>
#include <QDebug>
#include <QObject>
#include <QSignalBlocker>

#include <QBoxLayout>
#include <QGridLayout>
#include <QTableView>


//=====================*******==========================================*******=====================
void CyberCalc52::setEngine(CalcEngine *E)
{
  CEngine = E;
  CEngine->createDialog(this);


  QObject::connect(this->ui->btn_A_1,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_F()));

  QObject::connect(this->ui->btn_A_3,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_M_RX()));

  QObject::connect(this->ui->btn_A_6,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_RX_M()));


  QObject::connect(this->ui->btn_B_1,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_1()));
  QObject::connect(this->ui->btn_B_2,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_2()));
  QObject::connect(this->ui->btn_B_3,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_3()));
  QObject::connect(this->ui->btn_B_4,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_4()));
  QObject::connect(this->ui->btn_B_5,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_5()));
  QObject::connect(this->ui->btn_B_6,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_6()));
  QObject::connect(this->ui->btn_B_7,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_7()));
  QObject::connect(this->ui->btn_B_8,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_8()));
  QObject::connect(this->ui->btn_B_9,  SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_9()));
  QObject::connect(this->ui->btn_B_10, SIGNAL(clicked()), CEngine, SLOT(slot_btn_B_10()));

  QObject::connect(this->ui->btn_B_11, SIGNAL(clicked()), CEngine, SLOT(slot_point()));
  QObject::connect(this->ui->btn_B_12, SIGNAL(clicked()), CEngine, SLOT(slot_sign()));
  QObject::connect(this->ui->btn_B_13, SIGNAL(clicked()), CEngine, SLOT(slot_sub()));
  QObject::connect(this->ui->btn_B_14, SIGNAL(clicked()), CEngine, SLOT(slot_add()));
  QObject::connect(this->ui->btn_B_15, SIGNAL(clicked()), CEngine, SLOT(slot_swap()));
  //QObject::connect(this->ui->btn_B_16, SIGNAL(clicked()), CEngine, SLOT(slot_result()));
  QObject::connect(this->ui->btn_B_17, SIGNAL(clicked()), CEngine, SLOT(slot_div()));
  QObject::connect(this->ui->btn_B_18, SIGNAL(clicked()), CEngine, SLOT(slot_mul()));
  QObject::connect(this->ui->btn_B_19, SIGNAL(clicked()), CEngine, SLOT(slot_enter()));
  QObject::connect(this->ui->btn_B_20, SIGNAL(clicked()), CEngine, SLOT(slot_clear()));

//=====================*******=====================








//=====================*******=====================

  QObject::connect(CEngine, SIGNAL(signal_updateISD()), this, SLOT(slot_updateISD()));

}
//=====================*******==========================================*******=====================
void CyberCalc52::slot_updateISD(){

     ui->lcdNumber->setProperty("value", QVariant(CEngine->GetRX()));
     ui->lcdNumber->display(CEngine->GetRX());

     ui->lcdNumber->repaint(); ui->lcdNumber->update();

     this->repaint();

     qDebug()<<"updateISD";
    }
//=====================*******==========================================*******=====================
CyberCalc52::CyberCalc52(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CyberCalc52)
{
    ui->setupUi(this);

    qDebug()<<"CyberCalc52 create";

//=====================*******=====================

    QHBoxLayout * Sliderlayout = new QHBoxLayout;
    Sliderlayout->addWidget(ui->checkBox);
    Sliderlayout->addWidget(ui->checkBox_2);
    Sliderlayout->addWidget(ui->checkBox_3);
    Sliderlayout->addWidget(ui->checkBox_4);


    //Sliderlayout->setMargin(0);
    Sliderlayout->setContentsMargins(1,1,1,1);

    ui->SliderFrame->setLayout(Sliderlayout);
    ui->SliderFrame->setStyleSheet("background-color:grey;");
    ui->SliderFrame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QVBoxLayout * ICDlayout = new QVBoxLayout;
    ICDlayout->addWidget(ui->lcdNumber);
    ICDlayout->addWidget(ui->SliderFrame);
    ui->ICDFrame->setLayout(ICDlayout);

    QGridLayout *AddBtnlayout = new QGridLayout;
    AddBtnlayout->addWidget(ui->btn_A_1, 1, 1);
    AddBtnlayout->addWidget(ui->btn_A_2, 1, 2);
    AddBtnlayout->addWidget(ui->btn_A_3, 1, 3);

    AddBtnlayout->addWidget(ui->btn_A_4, 2, 1);
    AddBtnlayout->addWidget(ui->btn_A_5, 2, 2);
    AddBtnlayout->addWidget(ui->btn_A_6, 2, 3);

    AddBtnlayout->addWidget(ui->btn_A_7, 3, 1);
    AddBtnlayout->addWidget(ui->btn_A_8, 3, 2);
    AddBtnlayout->addWidget(ui->btn_A_9, 3, 3);

    AddBtnlayout->addWidget(ui->btn_A_10, 4, 1);
    AddBtnlayout->addWidget(ui->btn_A_11, 4, 2);
    AddBtnlayout->addWidget(ui->btn_A_12, 4, 3);

    ui->AddButtonFrame->setLayout(AddBtnlayout);
    ui->AddButtonFrame->setStyleSheet("background-color:grey;");


    QGridLayout *BaseBtnlayout = new QGridLayout;
    BaseBtnlayout->addWidget(ui->btn_B_7, 1, 1);
    BaseBtnlayout->addWidget(ui->btn_B_4, 2, 1);
    BaseBtnlayout->addWidget(ui->btn_B_1, 3, 1);
    BaseBtnlayout->addWidget(ui->btn_B_10, 4, 1);

    BaseBtnlayout->addWidget(ui->btn_B_8, 1, 2);
    BaseBtnlayout->addWidget(ui->btn_B_5, 2, 2);
    BaseBtnlayout->addWidget(ui->btn_B_2, 3, 2);
    BaseBtnlayout->addWidget(ui->btn_B_11, 4, 2);

    BaseBtnlayout->addWidget(ui->btn_B_9, 1, 3);
    BaseBtnlayout->addWidget(ui->btn_B_6, 2, 3);
    BaseBtnlayout->addWidget(ui->btn_B_3, 3, 3);
    BaseBtnlayout->addWidget(ui->btn_B_12, 4, 3);

    BaseBtnlayout->addWidget(ui->btn_B_13, 1, 4);
    BaseBtnlayout->addWidget(ui->btn_B_14, 2, 4);
    BaseBtnlayout->addWidget(ui->btn_B_15, 3, 4);
    BaseBtnlayout->addWidget(ui->btn_B_16, 4, 4);

    BaseBtnlayout->addWidget(ui->btn_B_17, 1, 5);
    BaseBtnlayout->addWidget(ui->btn_B_18, 2, 5);
    BaseBtnlayout->addWidget(ui->btn_B_19, 3, 5);
    BaseBtnlayout->addWidget(ui->btn_B_20, 4, 5);

    ui->BaseButtonFrame->setLayout(BaseBtnlayout);
    ui->BaseButtonFrame->setStyleSheet("background-color:grey;");

     QHBoxLayout * Mainlayout = new QHBoxLayout;
     Mainlayout->addWidget(ui->ICDFrame);
     Mainlayout->addWidget(ui->AddButtonFrame);
     Mainlayout->addWidget(ui->BaseButtonFrame);

     this->setLayout(Mainlayout);

//=====================*******=====================

     ui->checkBox->setStyleSheet("color:black; background-color:darkGrey;");
     ui->checkBox->setTransparant(QString::fromUtf8(""), 1);
     ui->checkBox->setTransparant(QString::fromUtf8("ВКЛ"), 2);
     ui->checkBox->setTransparant(QString::fromUtf8(""), 3);

     ui->checkBox_2->setStyleSheet("color:black; background-color:darkGrey;");
     ui->checkBox_2->setTransparant(QString::fromUtf8("С"), 1);
     ui->checkBox_2->setTransparant(QString::fromUtf8("СЧ"), 2);
     ui->checkBox_2->setTransparant(QString::fromUtf8("З"), 3);

     ui->checkBox_3->setText("ON"); ui->checkBox_3->setStyleSheet("color:black; background-color:darkGrey;");
     ui->checkBox_3->setTransparant(QString::fromUtf8("Р"), 1);
     ui->checkBox_3->setTransparant(QString::fromUtf8("Г"), 2);
     ui->checkBox_3->setTransparant(QString::fromUtf8("ГРД"), 3);

     ui->checkBox_4->setText("ON"); ui->checkBox_4->setStyleSheet("color:black; background-color:darkGrey;");
     ui->checkBox_4->setTransparant(QString::fromUtf8("Д"), 1);
     ui->checkBox_4->setTransparant(QString::fromUtf8("П"), 2);
     ui->checkBox_4->setTransparant(QString::fromUtf8(""), 3);

//=====================*******=====================

    QStringList BaseButtonsStr = {"0","1","2","3","4","5","6","7","8","9",".","/-/"};
                BaseButtonsStr <<"-"<<"+"<<"<->"<<"ВП"<<"/"<<"*"<<"В|"<<"CX";

     ui->btn_B_7->setText(BaseButtonsStr[7]);   ui->btn_B_7->setStyleSheet("color:black; background-color:lightGrey;"); //"7"
     ui->btn_B_4->setText(BaseButtonsStr[4]);   ui->btn_B_4->setStyleSheet("color:black; background-color:lightGrey;"); //"4"
     ui->btn_B_1->setText(BaseButtonsStr[1]);   ui->btn_B_1->setStyleSheet("color:black; background-color:lightGrey;"); //"1"
     ui->btn_B_10->setText(BaseButtonsStr[0]);  ui->btn_B_10->setStyleSheet("color:black; background-color:lightGrey;"); //"0"

     ui->btn_B_8->setText(BaseButtonsStr[8]);   ui->btn_B_8->setStyleSheet("color:black; background-color:lightGrey;"); //"8"
     ui->btn_B_5->setText(BaseButtonsStr[5]);   ui->btn_B_5->setStyleSheet("color:black; background-color:lightGrey;"); //"5"
     ui->btn_B_2->setText(BaseButtonsStr[2]);   ui->btn_B_2->setStyleSheet("color:black; background-color:lightGrey;"); //"2"
     ui->btn_B_11->setText(BaseButtonsStr[10]); ui->btn_B_11->setStyleSheet("color:black; background-color:lightGrey;"); //"."

     ui->btn_B_9->setText(BaseButtonsStr[9]);   ui->btn_B_9->setStyleSheet("color:black; background-color:lightGrey;"); //"9"
     ui->btn_B_6->setText(BaseButtonsStr[6]);   ui->btn_B_6->setStyleSheet("color:black; background-color:lightGrey;"); //"6"
     ui->btn_B_3->setText(BaseButtonsStr[3]);   ui->btn_B_3->setStyleSheet("color:black; background-color:lightGrey;"); //"3"
     ui->btn_B_12->setText(BaseButtonsStr[11]); ui->btn_B_12->setStyleSheet("color:black; background-color:lightGrey;"); //"/-/"

     ui->btn_B_13->setText(BaseButtonsStr[12]); ui->btn_B_13->setStyleSheet("color:black; background-color:lightGrey;"); //"-"
     ui->btn_B_14->setText(BaseButtonsStr[13]); ui->btn_B_14->setStyleSheet("color:black; background-color:lightGrey;");   //"+"
     ui->btn_B_15->setText(BaseButtonsStr[14]); ui->btn_B_15->setStyleSheet("color:black; background-color:lightGrey;");   //"M"
     ui->btn_B_16->setText(BaseButtonsStr[15]); ui->btn_B_16->setStyleSheet("color:black; background-color:lightGrey;");   //"="

     ui->btn_B_17->setText(BaseButtonsStr[16]); ui->btn_B_17->setStyleSheet("color:black; background-color:lightGrey;");   //"/"
     ui->btn_B_18->setText(BaseButtonsStr[17]); ui->btn_B_18->setStyleSheet("color:black; background-color:lightGrey;");   //"*"
     ui->btn_B_19->setText(BaseButtonsStr[18]); ui->btn_B_19->setStyleSheet("color:black; background-color:lightGrey;");   //"M+"
     ui->btn_B_20->setText(BaseButtonsStr[19]); ui->btn_B_20->setStyleSheet("color:black; background-color:lightGrey;");   //"CX"


    QStringList AddButtonsStr = {QString::fromUtf8("F"),     QString::fromUtf8("ШГ->"),   QString::fromUtf8("П->X") };
                AddButtonsStr << QString::fromUtf8("K")   << QString::fromUtf8("ШГ<-") << QString::fromUtf8("X->П");
                AddButtonsStr << QString::fromUtf8("<->") << QString::fromUtf8("В/О")  << QString::fromUtf8("БП");
                AddButtonsStr << QString::fromUtf8("A|")  << QString::fromUtf8("С/П")  << QString::fromUtf8("ПП");

     ui->btn_A_1->setText(AddButtonsStr[0]);  ui->btn_A_1->setStyleSheet("color:black; background-color:yellow;");
     ui->btn_A_2->setText(AddButtonsStr[1]);  ui->btn_A_2->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_3->setText(AddButtonsStr[2]);  ui->btn_A_3->setStyleSheet("color:white; background-color:black;");

     ui->btn_A_4->setText(AddButtonsStr[3]);  ui->btn_A_4->setStyleSheet("color:white; background-color:blue;");
     ui->btn_A_5->setText(AddButtonsStr[4]);  ui->btn_A_5->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_6->setText(AddButtonsStr[5]);  ui->btn_A_6->setStyleSheet("color:white; background-color:black;");

     ui->btn_A_7->setText(AddButtonsStr[6]);  ui->btn_A_7->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_8->setText(AddButtonsStr[7]);  ui->btn_A_8->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_9->setText(AddButtonsStr[8]);  ui->btn_A_9->setStyleSheet("color:white; background-color:black;");

     ui->btn_A_10->setText(AddButtonsStr[9]);  ui->btn_A_10->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_11->setText(AddButtonsStr[10]);  ui->btn_A_11->setStyleSheet("color:white; background-color:black;");
     ui->btn_A_12->setText(AddButtonsStr[11]);  ui->btn_A_12->setStyleSheet("color:white; background-color:black;");

}
//=====================*******==========================================*******=====================
CyberCalc52::~CyberCalc52()
{
    CEngine->~CalcEngine();

    delete ui;

    qDebug()<<"CyberCalc destroy";
}
//=====================*******==========================================*******=====================

