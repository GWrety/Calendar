#pragma once
#include <QLabel>
#include <QMouseEvent>
#include<QEvent>
class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget* parent = 0);
	//�������¼�
	void enterEvent(QEnterEvent*);
	//����뿪��
	void leaveEvent(QEvent*);
};

