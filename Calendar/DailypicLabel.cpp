#include"DailypicLabel.h"

DailyLabel::DailyLabel(QWidget* parent) :QLabel(parent)
{
	this->setMouseTracking(true);
	this->setStyleSheet("color:rgb(252,210, 23); font-size:20px; background-color:rgb(192, 72,81); border: 2px solid rgb(227, 180, 184)");
	this->setAlignment(Qt::AlignBottom);
	this->setAlignment(Qt::AlignHCenter);
};
void DailyLabel::mousePressEvent(QMouseEvent*)
{
	emit(enter());
}

//鼠标离开事件
void DailyLabel::leaveEvent(QEvent*)
{
	emit(leave());
}