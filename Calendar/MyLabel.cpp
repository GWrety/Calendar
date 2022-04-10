#include "MyLabel.h"
const QString labelstyle = "border-radius: 10px;color:rgb(19,44,51); font-size:20px; background-color:rgb(196,215,214);border: 1px solid rgb(102,169,201) ";
MyLabel::MyLabel(QWidget* parent):QLabel(parent) 
{
	this->setMouseTracking(true);
	this->setStyleSheet(labelstyle);
	this->setAlignment(Qt::AlignCenter);
};
void MyLabel::enterEvent(QEnterEvent*)
{
	this->setStyleSheet("border-radius: 13px;color:White;font-size:25px;background-color:rgb(102,169,201);");
	int x = this->size().width();
	int y = this->size().height();
	int pos_x = this->pos().x();
	int pos_y = this->pos().y();
	this->resize(x*1.4,y*1.4);
	this->move(pos_x-(x*0.2),pos_y-(y*0.2) );
	this->raise();
	lag = 1;
}
//鼠标离开事件
void MyLabel::leaveEvent(QEvent*)
{
	if (lag) {
		this->setStyleSheet(labelstyle);
		int x = this->size().width();
		int y = this->size().height();
		int pos_x = this->pos().x();
		int pos_y = this->pos().y();
		this->resize(x / 1.4, y / 1.4);
		this->move(pos_x + (x / 1.4 * 0.2), pos_y + (y / 1.4 * 0.2));
		lag = 0;
	}
	
}
void MyLabel::mousePressEvent(QMouseEvent* event)
{
	emit(clicked(this->year, this->month, this->day));
};
void MyLabel::setDate(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
};