#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Daily.h"
#include<iostream>
#include<fstream>
#include<istream>
#include<string>
#include<map>
using namespace std;
class Daily : public QMainWindow
{
    Q_OBJECT

public:
	ofstream b;
    Daily(QWidget *parent = Q_NULLPTR);
public slots:
	void UpDateDaile();

private:
    Ui::DailyClass ui;
};
