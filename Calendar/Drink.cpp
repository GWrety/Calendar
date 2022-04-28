#include "Drink.h"
bool ismore = false;
Drink::Drink(QWidget *parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);
    ifstream  b("drink.txt");
    int ti;
    if (b)
    {
        b >> allneed ;
        b >> once ;
        b >> havedrunk ;
        b >> time ;
        b >> weight;
        b >> ti;
    }
    int pretime = time;
    if (ti != QDate::currentDate().day())
    {
        havedrunk = 0;
    }
    else
    {
        ofstream b1("drink.txt");
        b1 << allneed << endl;
        b1 << once << endl;
        b1 << havedrunk << endl;
        b1 << time << endl;
        b1 << weight<<endl;
        b1 << QDate::currentDate().day();
    }
  
    connect(ui.pushButton_drink, &QPushButton::clicked, this, &Drink::drink_cli);
    connect(ui.pushButton_more, &QPushButton::clicked, this, &Drink::more_cli);
    connect(ui.pushButton_make, &QPushButton::clicked, this, &Drink::make_cli);
    connect(ui.comboBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(time_change(int)));
    ui.comboBox_1->addItems(QStringList() << "男" << "女");
    ui.comboBox_1->setStyleSheet("QComboBox{border:1px solid gray;  border - radius:3px;  padding: 5px; min - width:4em;}QComboBox::drop - down{ subcontrol - origin:padding; subcontrol - position:top right; width:20px; border - left - width:1px; border - left - color:darkgray; border - left - style:solid; border - top - right - radius:3px; border - bottom - right - radius:3px;}");
    ui.comboBox_2->setStyleSheet("QComboBox{border:1px solid gray;  border - radius:3px;  padding: 5px; min - width:4em;}QComboBox::drop - down{ subcontrol - origin:padding; subcontrol - position:top right; width:20px; border - left - width:1px; border - left - color:darkgray; border - left - style:solid; border - top - right - radius:3px; border - bottom - right - radius:3px;}");
    ui.comboBox_3->setStyleSheet("QComboBox{border:1px solid gray;  border - radius:3px;  padding: 5px; min - width:4em;}QComboBox::drop - down{ subcontrol - origin:padding; subcontrol - position:top right; width:20px; border - left - width:1px; border - left - color:darkgray; border - left - style:solid; border - top - right - radius:3px; border - bottom - right - radius:3px;}");
    ui.comboBox_4->setStyleSheet("QComboBox{border:1px solid gray;  border - radius:3px;  padding: 5px; min - width:4em;}QComboBox::drop - down{ subcontrol - origin:padding; subcontrol - position:top right; width:20px; border - left - width:1px; border - left - color:darkgray; border - left - style:solid; border - top - right - radius:3px; border - bottom - right - radius:3px;}");
    for (int i = 0; i < 61; i++)
    {
        ui.comboBox_2->addItem(QString::number(i + 40) + "KG");
    }
 
    for (int i = 0; i < 61; i++)
    {
        if ((i + 40) == weight)
        {
            ui.comboBox_2->setCurrentIndex(i);
        }
    }
    for (int i = 0; i < 20; i++)
    {
        ui.comboBox_3->addItem(QString::number(i*100 + 100) + "ML");
    }
    for (int i = 0; i < 20; i++)
    {
        if ((i * 100 + 100) == once)
        {
            ui.comboBox_3->setCurrentIndex(i);
            break;
        }
    }
;
    for (int i = 0; i < 18; i++)
    {
        ui.comboBox_4->addItem(QString::number(5+i *5) + " min");
    }
    for (int i = 0; i < 18; i++)
    {
        if ((i * 5 + 5) == pretime)
        {
            ui.comboBox_4->setCurrentIndex(i);
            break;
        }
    }
    ui.comboBox_1->hide();
    ui.comboBox_2->hide();
    ui.comboBox_3->hide();
    ui.comboBox_4->hide();
    ui.pushButton_make->hide();
    ui.label->hide();
    ui.label_1->hide();
    ui.label_2->hide();
    ui.label_3->hide();
    ui.label_4->hide();
    ui.label->setAlignment(Qt::AlignCenter);
    ui.label_1->setAlignment(Qt::AlignCenter);
    ui.label_2->setAlignment(Qt::AlignCenter);
    ui.label_3->setAlignment(Qt::AlignCenter);
    ui.label_4->setAlignment(Qt::AlignCenter);
    ui.label->setStyleSheet ( "QLabel{font-size:20px;font-family:YouYuan;}");
    ui.label_1->setStyleSheet("QLabel{font-size:20px;font-family:YouYuan;}");
    ui.label_2->setStyleSheet("QLabel{font-size:20px;font-family:YouYuan;}");
    ui.label_3->setStyleSheet("QLabel{font-size:20px;font-family:YouYuan;}");
    ui.label_4->setStyleSheet("QLabel{font-size:20px;font-family:YouYuan;}");
    ui.label->setText("今日目标:" + QString::number(allneed) + "ML");
    ui.pushButton_drink->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");
    ui.pushButton_make->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");
    ui.pushButton_more->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");
    double temp = double(havedrunk) / double(allneed);
    temp *= 100;
    m_persent = temp;
    time = pretime;
    update();
}
Drink::~Drink()
{

    ofstream b("drink.txt");
    b << allneed << endl;
    b << once << endl;
    b << havedrunk << endl;
    b << time << endl;
    b << weight << endl;
    b << QDate::currentDate().day();
}
void Drink::drink_cli()
{
    havedrunk+= once;  
    double temp =  double(havedrunk) / double(allneed);
    temp *= 100;
    m_persent = temp;

    update();
};
void Drink::more_cli()
{
    ismore = !ismore;
    update();

};
void Drink::make_cli()
{

    int a = ui.comboBox_3->currentIndex();
    once = a * 100 + 100;
    weight = ui.comboBox_2->currentIndex() + 40;
    //体重*40是一天的喝水量
    allneed= (ui.comboBox_2->currentIndex()+40)*40;
    ui.label->setText("今日目标："+ QString::number(allneed) + "ML");
};
void Drink::time_change(int index)
{
    time = 5 + index * 5;
    emit(sendTime(time));
};
void Drink::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QColor q(173, 216, 230);
    p.setBrush(q);
    p.drawRect(0, 0, this->width(), this->height());
    if (ismore)
    {
        ui.comboBox_1->show();
        ui.comboBox_2->show();
        ui.comboBox_3->show();
        ui.comboBox_4->show();
        ui.pushButton_make->show();
        ui.pushButton_drink->hide();
        ui.label_1->show();
        ui.label_2->show();
        ui.label_3->show();
        ui.label_4->show();
        ui.label->show();
        p.setBrush(Qt::white);
        QRectF rect(this->width()/6, this->height()/12+20, this->width()*2 / 3, this->height()*2 / 3+20);
        p.drawRoundedRect(rect, 20, 20);
    }
    else
    {
        ui.label->hide();
        ui.label_1->hide();
        ui.label_2->hide();
        ui.label_3->hide();
        ui.label_4->hide();
        ui.comboBox_1->hide();
        ui.comboBox_2->hide();
        ui.comboBox_3->hide();
        ui.comboBox_4->hide();
        ui.pushButton_make->hide();
        ui.pushButton_drink->show();
        int m_rotateAngle = 360 * m_persent / 100;
        int side = qMin(width() * 2 / 3, height() * 2 / 3);
        QRectF outRect(70, 100, side, side);//矩形长宽为窗口的长宽
        QRectF inRect(90, 120, side - 40, side - 40);
        QString valueStr = QString("%1%").arg(QString::number(m_persent));
        //画外圆
        p.setPen(Qt::NoPen);
        QColor qq(0, 0, 128);
        p.setBrush(Qt::gray);
        p.drawEllipse(outRect);
        //画内圆
        p.setBrush(Qt::blue);
        p.drawPie(outRect, (90 - m_rotateAngle) * 16, m_rotateAngle * 16);
        //画遮罩，遮罩颜色为窗口颜色
        p.setBrush(Qt::white);
        p.drawEllipse(inRect);
        //画文字
        QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
        p.setFont(f);
        p.setFont(f);
        p.setPen(QColor("#555555"));
        p.drawText(inRect, Qt::AlignCenter, valueStr);
    }
    
}
