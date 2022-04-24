#include "widget.h"

zhangWidget::zhangWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::zhangWidget)
{
    ui->setupUi(this);
    QDate current_date = QDate::currentDate();
    QString currentDate = current_date.toString("yyyy/MM/dd");
    ui->label_2->setText(currentDate);
    QStringList list ={};
    int x = 1;
    list<<"姓名"<<"时间"<<"花费"<<"备注";
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setRowCount(15);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        name.append(ui->lineEdit->text());
        time.append(ui->label_2->text());
        QString p=ui->lineEdit_2->text();
        if(p[0] !='+')p = " - " + p;
        sum.append(p);

        about.append(ui->lineEdit_3->text());
        ui->lineEdit->clear();
         ui->lineEdit_2->clear();
          ui->lineEdit_3->clear();
        int len=name.length();
        for(int i=0;i<len;i++){
            int col=0;
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(name[i]));
            /*ui->tableWidget->setItem(i,col++,new QTableWidgetItem(time[i]));
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sum[i]));
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(about[i]));*/}

        int len2=time.length();
        for(int i=0;i<len2;i++){
            int col=1;
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(time[i]));}

        int len3=sum.length();
        for(int i=0;i<len3;i++){
            int col=2;
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sum[i]));}

        int len4=about.length();
        for(int i=0;i<len4;i++){
            int col=3;
            ui->tableWidget->setItem(i,col++,new QTableWidgetItem(about[i]));}


        writetofile();
        allpay();

    });
  readtofile();
  allpay();
  int len=name.length();
  for(int i=0;i<len;i++){
      int col=0;
      ui->tableWidget->setItem(i,col++,new QTableWidgetItem(name[i]));
  }
  int len2=time.length();
  for(int i=0;i<len2;i++){
      int col=1;
      ui->tableWidget->setItem(i,col++,new QTableWidgetItem(time[i]));}

  int len3=sum.length();
  for(int i=0;i<len3;i++){
      int col=2;
      ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sum[i]));}

  int len4=about.length();
  for(int i=0;i<len4;i++){
      int col=3;
      ui->tableWidget->setItem(i,col++,new QTableWidgetItem(about[i]));}


  connect(ui->pushButton_2,&QPushButton::clicked,[=](){

      deletedate();
      ui->lineEdit_4->clear();

//      int len=name.length();
//      for(int i=0;i<len;i++){
//          int col=0;
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(name[i]));
//          /*ui->tableWidget->setItem(i,col++,new QTableWidgetItem(time[i]));
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sum[i]));
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(about[i]));*/}

//      int len2=time.length();
//      for(int i=0;i<len2;i++){
//          int col=1;
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(time[i]));}

//      int len3=sum.length();
//      for(int i=0;i<len3;i++){
//          int col=2;
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sum[i]));}

//      int len4=about.length();
//      for(int i=0;i<len4;i++){
//          int col=3;
//          ui->tableWidget->setItem(i,col++,new QTableWidgetItem(about[i]));}
  });
}

zhangWidget::~zhangWidget()
{
    delete ui;
}
void zhangWidget::readtofile()
{
    QFile myname("name.txt");
    myname.open(QIODevice::ReadOnly);
    QTextStream in(&myname);
    //in.setCodec("utf-8");
    QString line=in.readLine();
    while (!line.isNull())
    {  name.append(line);
       line = in.readLine();

    }

    myname.close();

    QFile mytime("time.txt");
    mytime.open(QIODevice::ReadOnly);
    QTextStream in2(&mytime);
    //in2.setCodec("utf-8");
    QString line2 = in2.readLine();
    while (!line2.isNull())
    {  time.append(line2);
       line2 = in2.readLine();

    }
    mytime.close();


    QFile mysum("sum.txt");
    mysum.open(QIODevice::ReadOnly);
    QTextStream in3(&mysum);
    //in3.setCodec("utf-8");
    QString line3 = in3.readLine();
    while (!line3.isNull())
    {   sum.append(line3);
       line3 = in3.readLine();

    }
    mysum.close();


    QFile myabout("about.txt");
    myabout.open(QIODevice::ReadOnly);
    QTextStream in4(&myabout);
    //in4.setCodec("utf-8");
    QString line4 = in4.readLine();
    while (!line4.isNull())
    {  about.append(line4);
       line4 = in4.readLine();

    }
    myabout.close();
}
void zhangWidget::writetofile()
{
    QFile myname("name.txt");
    myname.open(QIODevice::WriteOnly);
    int len=name.length();
    for(int i=0;i<len;i++){
        QString str=name[i];
        QByteArray bytes = str.toUtf8();
        myname.write(bytes);
        myname.write("\n");
    }
    myname.close();



    QFile mytime("time.txt");
    mytime.open(QIODevice::WriteOnly);
    int len2=time.length();
    for(int i=0;i<len2;i++){
        QString str2=time[i];
        QByteArray bytes2 = str2.toUtf8();
        mytime.write(bytes2);
        mytime.write("\n");
    }
    mytime.close();



    QFile mysum("sum.txt");
    mysum.open(QIODevice::WriteOnly);
    int len3=sum.length();
    for(int i=0;i<len3;i++){
        QString str3=sum[i];
        QByteArray bytes3 = str3.toUtf8();
        mysum.write(bytes3);
        mysum.write("\n");
    }
    mysum.close();



    QFile myabout("about.txt");
    myabout.open(QIODevice::WriteOnly);
    int len4=about.length();
    for(int i=0;i<len4;i++){
        QString str4=about[i];
        QByteArray bytes4 = str4.toUtf8();
        myabout.write(bytes4);
        myabout.write("\n");
    }
    myabout.close();
}



void zhangWidget::allpay()
{
    int len=sum.length();
    int pay=0;
    int x = sum[0].toInt();
    for (int i = 0; i < len; i++) {
        if (sum[i][1] =='-') {
            QString temp = sum[i].mid(3, -1);
            pay += 0-temp.toInt();
        }
        else {
            pay += sum[i].toInt();
        }        
    }

    ui->label_7->setText(QString::number(pay));
}
void zhangWidget::deletedate(){
    QString str=ui->lineEdit_4->text();
    int num=str.toInt();
    time.removeAt(num-1);
    sum.removeAt(num-1);
    about.removeAt(num-1);
    name.removeAt(num-1);
    ui->tableWidget->removeRow(num-1);
    QFile myname("name.txt");
    myname.open(QFile::WriteOnly|QFile::Truncate);
    int len=name.length();
    for(int i=0;i<len;i++){
        QString str=name[i];
        QByteArray bytes = str.toUtf8();
        myname.write(bytes);
        myname.write("\n");
    }
    myname.close();



    QFile mytime("time.txt");
    mytime.open(QFile::WriteOnly|QFile::Truncate);
    int len2=time.length();
    for(int i=0;i<len2;i++){
        QString str2=time[i];
        QByteArray bytes2 = str2.toUtf8();
        mytime.write(bytes2);
        mytime.write("\n");
    }
    mytime.close();



    QFile mysum("sum.txt");
    mysum.open(QFile::WriteOnly|QFile::Truncate);
    int len3=sum.length();
    for(int i=0;i<len3;i++){
        QString str3=sum[i];
        QByteArray bytes3 = str3.toUtf8();
        mysum.write(bytes3);
        mysum.write("\n");
    }
    mysum.close();



    QFile myabout("about.txt");
    myabout.open(QFile::WriteOnly|QFile::Truncate);
    int len4=about.length();
    for(int i=0;i<len4;i++){
        QString str4=about[i];
        QByteArray bytes4 = str4.toUtf8();
        myabout.write(bytes4);
        myabout.write("\n");
    }
    myabout.close();
    allpay();
}
