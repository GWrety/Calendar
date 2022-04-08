#include "MyLabel.h"
const QString labelstyle = "border-radius: 13px;color:rgb(19,44,51); font-size:20px; background-color:rgb(208, 230, 220);border: 2px solid rgb(15,149,176) ";
MyLabel::MyLabel(QWidget* parent):QLabel(parent) 
{
	this->setMouseTracking(true);
	this->setStyleSheet(labelstyle);
	int x= this->size().width();
	int y = this->size().height();
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
}

//鼠标离开事件
void MyLabel::leaveEvent(QEvent*)
{
	this->setStyleSheet(labelstyle);
	int x = this->size().width();
	int y = this->size().height();
	int pos_x = this->pos().x();
	int pos_y = this->pos().y();
	this->resize(x/1.4,y/1.4);
	this->move(pos_x + (x/1.4 * 0.2), pos_y + (y/1.4 * 0.2));
}
