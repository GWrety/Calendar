#include "eatthing.h"
#include "ui_eatthing.h"
#include<QTime>
#include<QFont>
eatthing::eatthing(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::eatthing)
{
    ui->setupUi(this);
    readmenu();
    this->setWindowIcon(QIcon(":/Calendar/eat.png"));
   QFont font("Arial",30,QFont::Bold);
   ui->label->setStyleSheet("QLabel{background-color:rgb(255,255,128);}");
   ui->label->setFont(font);
     srand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    timer=new QTimer(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        if(isStart) {
            timer->start(70);
            isStart=false;
        }
        else{
            timer->stop();
            isStart=true;
        }
    });

    connect(timer,&QTimer::timeout,[=](){

        int n=rand()%30;

        ui->label->setText(mymenu[n]);

    });





}

eatthing::~eatthing()
{
    delete ui;
}

void eatthing:: readmenu(){

    QFile m_menu("menu.txt");
    m_menu.open(QIODevice::ReadOnly);
    QTextStream in(&m_menu);
    QString line=in.readLine();
    while (!line.isNull())
    {  mymenu.append(line);
       line = in.readLine();
    }

    m_menu.close();


}
