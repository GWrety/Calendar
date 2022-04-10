#pragma once
#include <QWidget>
#include<QTextedit>
#include<QPushbutton>
#include<QLabel>
using namespace std;
class schedule : public QWidget
{
	Q_OBJECT
public:
	schedule(QWidget* parent = 0);
	void p1_cli();
	void p2_cli();
	void p3_cli();
	void receive_frommain(string s);
	string y;
	string m;
	string d;
	string ymd;
	string cont;
	string op;
	bool change = false;
	QPushButton* p1;
	QPushButton* p2;
	QPushButton* p3;
	QTextEdit* t1;
	QLabel *l1;
	QLabel* l2;
signals:
	void sendOK(string oc);
};