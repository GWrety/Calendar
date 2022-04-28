#pragma once
#include<QWidget>
#include<QPushButton>
#include<QFile>
#include<QLabel>
#include<QPropertyAnimation>
#include<QPainter>
class AnswerWidget : public QWidget
{
public:
    AnswerWidget(QWidget* parent = nullptr) {
        this->resize(400, 600);
        this->setWindowTitle("认识你自己");
        this->setWindowIcon(QIcon(":/Calendar/anser.png"));
       
        button = new QPushButton(this);
        button->resize(400, 100);
        button->move(0, 500);
        button->setStyleSheet("QPushButton{font-family:'幼圆';font:bold 25px;font-color:rgb(255,255,255);background-color: rgb(105,105,105)}QPushButton:hover{font-family:'幼圆';font:bold 25px;font-color:rgb(255,255,255);background-color: rgb(169,169,169)}QPushButton:pressed{border:none;background:transparent;}");
        button->setText("答案之书");
        label = new QLabel(this);
        //label->resize();
        connect(button, &QPushButton::clicked, [=] {
            this->getans();
            });
        QFile file("ans.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        char* temp = new char[200];
        while (!file.atEnd()) {
            file.readLine(temp, 200);
            ans.push_back(QString(temp));
        }
        delete[]temp;
    };
    void Show() {

        QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
        animation->setDuration(1000);
        animation->setStartValue(0);
        animation->setEndValue(1);
        animation->start();
        this->show();
    }
    void getans() {
        int n = ans.size();
        srand(time(0));
         x = rand() % n;
        update();
    }
    void paintEvent(QPaintEvent*event) {
        QPainter painter(this);
        int w = this->width();
        int h = this->height();
        QPen pen;
        painter.drawPixmap(0, 0, w, h, QPixmap(":/Calendar/answer.jpg"));
        pen.setColor(Qt::white);
        QFont font;
        font.setPointSizeF(25);
        font.setFamily("幼圆");
        painter.setFont(font);
        painter.setPen(pen);
        if (x != -1) {
            int n = ans[x].size()/2;
            painter.drawText(QRect(w/2-(n*w/12), h / 4, w , h / 2), ans[x]);
        }
        
    }
    void closeEvent(QCloseEvent* e) {
        x = -1;
    }
private:
    int x = -1;
    QLabel* label;
    QVector<QString> ans;
    QPushButton* button;
};