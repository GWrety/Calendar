#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include<string>
#include<QTimer>
#include<fstream>
#include<istream>
#include<QMessageBox>
#include<QString>
#include "ui_todolist.h"
using namespace std;
class QtWidgetsClass : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent = Q_NULLPTR);
	~QtWidgetsClass();
	const int NumOfTaskSum = 8;//���������
	QString Tast[8];//�����ַ�
	int NumOfTaskTemp=1;//�ܹ�����������
	void UpDate();//����״̬
	void UpDateLabelToTask();//��label���µ�����
	ifstream TastFileIn;
	ofstream TastFileOut;
public slots:
	void add();//�������
	void check();//����Ƿ���Ҫɾ��,������
	
private:
	Ui::QtWidgetsClass ui;
};
