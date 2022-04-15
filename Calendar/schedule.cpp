#include"schedule.h"
schedule::schedule(QWidget* parent) : QWidget(parent)
{

	this->resize(500, 500);
	op = "N";
	p1 = new QPushButton;
	p1->setParent(this);
	p1->resize(150, 70);
	p1->move(330, 420);
	p1->setText("返回");
	connect(p1, &QPushButton::clicked, this, &schedule::p1_cli);

	p2 = new QPushButton;
	p2->setParent(this);
	p2->resize(150, 70);
	p2->move(10, 420);
	p2->setText("修改");
	connect(p2, &QPushButton::clicked, this, &schedule::p2_cli);

	p3 = new QPushButton;
	p3->setParent(this);
	p3->resize(150, 70);
	p3->move(170, 420);
	p3->setText("修改");
	connect(p3, &QPushButton::clicked, this, &schedule::p3_cli);

	l1 = new QLabel;
	l1->setParent(this);
	l1->resize(500, 300);
	l1->move(0, 0);
	l1->setStyleSheet("QLabel{font-family: Microsoft YaHei;color:black;font-size:40px;background-color: rgb(140,199,181);border-width: 3px;border-style: solid;border-color: rgb(230,228,192);}");
	l1->setWordWrap(true);
	l1->setAlignment(Qt::AlignTop);

	l2 = new QLabel;
	l2->setParent(this);
	l2->resize(500, 100);
	l2->move(0, 300);
	l2->setStyleSheet("QLabel{font-family: Microsoft YaHei;color:black;font-size:30px;background-color: rgb(140,199,181);border-width: 3px;border-style: solid;border-color: rgb(230,228,192);}");
	l2->setAlignment(Qt::AlignVCenter);
	l2->setAlignment(Qt::AlignHCenter);

	t1 = new QTextEdit;
	t1->setParent(this);
	t1->resize(300, 300);
	t1->move(100, 100);
	t1->hide();
}
void schedule::p1_cli()
{
	this->hide();
	emit(sendOK(op+ymd+cont));
};
void schedule::p2_cli()
{
	if (!change)
	{
		l1->hide();
		l2->hide();
		p3->hide();
		p1->hide();
		t1->show();
		p2->setText("确认修改");
		change = true;
	}
	else
	{
		l1->show();
		l2->show(); 
		p3->show();
		p1->show();
		QString s=t1->toPlainText();
		cont= s.toStdString();
		l1->setText(s);
		t1->hide();
		p2->setText("修改");
		change = false;
		op = "C";
	}
};
void schedule::p3_cli()
{
	op = "D";
	cont = "";
	l1->setText(QString::fromStdString(cont));
	t1->setText(QString::fromStdString(cont));
}
void schedule::receive_frommain(string s)
{
	ymd=s.substr(0, 8);
	y= ymd.substr(0, 4);
	m= ymd.substr(4, 2);
	d=ymd.substr(6, -1);
	if (m[0] == '0')
	{
		m[0] = '-';
	}
	else
	{
		m = '-' + m;
	}
	if (d[0] == '0')
	{
		d[0] = '-';
	}
	else
	{
		d = '-' + d;
	}
	cont= s.substr(8, -1);
	l1->setText(QString::fromStdString(cont));
	l2->setText(QString::fromStdString(y+m+d));
	t1->setText(QString::fromStdString(cont));
}
void schedule::receivewh_frommain(int w, int h)
{
	int ww = w / 2;
	int hh = h / 2;
	this->resize(ww, hh);


	l1->resize(ww, 3 * hh / 5);
	l1->move(0, 0);
	l2->resize(ww, hh / 5);
	l2->move(0, 3 * hh / 5);
	p1->resize(ww / 3, hh / 5);
	p1->move(ww * 2 / 3, hh * 4 / 5);
	p2->resize(ww / 3, hh / 5);
	p2->move(0, hh * 4 / 5);
	p3->resize(ww / 3, hh / 5);
	p3->move(ww / 3, hh * 4 / 5);
};





