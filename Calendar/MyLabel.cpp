#include "MyLabel.h"
MyLabel::MyLabel(QWidget* parent):QLabel(parent) 
{
	this->setMouseTracking(true);
	this->setStyleSheet("QLabel{font-size:20px;}");
	this->setAlignment(Qt::AlignCenter);
};
void MyLabel::enterEvent(QEvent*)
{
	this->setStyleSheet("QLabel{color:rgba(255, 0, 0, 255);font-size:30px;}");
}

//����뿪�¼�
void MyLabel::leaveEvent(QEvent*)
{
	this->setStyleSheet("QLabel{color:rgba(0, 0, 0, 255);font-size:20px;}");
}

//�ڶ��ε�����������------
void MyLabel::mousePressEvent(QMouseEvent* event)
{
	emit(clicked(this->year, this->month,this->day));
};
void MyLabel::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
};
