#include"schedule.h"
schedule::schedule(QWidget* parent) : QWidget(parent)
{
	this->resize(500, 500);
	this->setWindowTitle("日程");
	this->setWindowIcon(QIcon(":/Calendar/aim.png"));
	op = "N";
	p1 = new QPushButton;
	p1->setParent(this);
	p1->setText("返回");
	connect(p1, &QPushButton::clicked, this, &schedule::p1_cli);
	p2 = new QPushButton;
	p2->setParent(this);
	p2->setText("修改");
	connect(p2, &QPushButton::clicked, this, &schedule::p2_cli);
	p3 = new QPushButton;
	p3->setParent(this);
	p3->setText("删除");
	connect(p3, &QPushButton::clicked, this, &schedule::p3_cli);
	l2 = new QLabel;
	l2->setParent(this);
	l2->setStyleSheet("QLabel{font-family:YouYuan;font-weight: bold; color:black;font-size:50px;}");
	l2->setAlignment(Qt::AlignCenter);
	t1 = new QTextEdit;
	t1->setParent(this);
	t1->setStyleSheet("font-family: YouYuan;color:black;font-size:30px;");
	t1->setReadOnly(true);
	t1->setFrameShape(QFrame::NoFrame);
}
void schedule::p1_cli()
{
	this->hide();
	emit(sendOK(op + ymd + cont));
};
void schedule::p2_cli()
{
	if (!change)
	{
		p3->hide();
		p1->hide();
		
		t1->setReadOnly(false);
		p2->setText("确认");
		change = true;
	}
	else
	{

		p3->show();
		p1->show();
		QString s = t1->toPlainText();
		cont = s.toStdString();

		t1->setReadOnly(true);

		p2->setText("修改");
		change = false;
		op = "C";
	}
};
void schedule::p3_cli()
{
	op = "D";
	cont = "";

	t1->setText(QString::fromStdString(cont));
}
void schedule::receive_frommain(string s)
{
	ymd = s.substr(0, 8);
	y = ymd.substr(0, 4);
	m = ymd.substr(4, 2);
	d = ymd.substr(6, -1);
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
	cont = s.substr(8, -1);

	l2->setText(QString::fromStdString(y + m + d));
	t1->setText(QString::fromStdString(cont));
}
void schedule::receivewh_frommain(int w, int h)
{
	int ww = w / 2;
	int hh = h / 2;
	this->resize(ww, hh);
	t1->resize(2 * ww / 3, 3 * hh / 5);
	t1->move(ww / 6, hh / 5);
	l2->resize(ww, hh / 5);
	l2->move(0, 0);
	p2->resize(ww / 6, hh / 7);
	p2->move(ww / 3 + ww / 12, hh * 5 / 6);
	p3->resize(ww / 6, hh / 7);
	p3->move(ww / 6, hh * 5 / 6);
	p1->resize(ww / 6, hh / 7);
	p1->move(ww * 2 / 3, hh * 5 / 6);
	p3->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");
	p2->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");
	p1->setStyleSheet(" QPushButton{background-color:rgb(252,183,10);border-radius:10px;border:2px groove gray;border-style: outset;font-family: Microsoft YaHei;color:black;font-size:20px;}" "QPushButton:hover{background-color:yellow;color:black;}");

};
		

void schedule::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QColor q(192, 142, 175);
	QBrush s(q);
	painter.setBrush(s);
	painter.drawRect(0, 0, this->width(), this->height());
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(Qt::white);
	QRectF rect((this->width() / 6)-10, (this->height() / 5)-10, (2 * this->width() / 3)+20, (3 * this->height() / 5)+20);
	painter.drawRoundedRect(rect, 20, 20);
};





