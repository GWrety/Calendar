#include"schedule.h"
schedule::schedule(QWidget* parent) : QWidget(parent)
{
	//connect
	this->resize(500, 500);
	p1 = new QPushButton;
	p1->setParent(this);
	p1->move(250, 450);
	p1->setText(QString::fromLocal8Bit("х╥хо"));
	connect(p1, &QPushButton::clicked, this, &schedule::p1_cli);
	t1 = new QTextEdit;
	t1->setParent(this);
	t1->resize(300, 300);
	t1->move(100, 100);
}
void schedule::p1_cli()
{

	this->hide();
	emit(sendOK());
};
void schedule::receive_frommain(string s)
{
	t1->setText(QString::fromStdString(s));
}