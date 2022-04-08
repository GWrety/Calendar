#include "expr.h"
#include "ui_expr.h"

expr::expr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expr)
{
    ui->setupUi(this);
    // 新建model，设置显示屏的默认值为0
        this->mode = new model;
        this->tmp = "";
}
expr::~expr()
{
    delete ui;
}

void expr::on_btn_0_clicked()
{
    // 第一个数是0时不会叠加0
       if(this->tmp != ""){
           // 拼接字符串
           this->tmp += this->ui->btn_0->text();
           // 把它显示出来
           this->ui->lcd_display->display(this->tmp);
       }
}

void expr::on_btn_c_clicked()
{
    // 清除第一个计算数
        this->tmp = "";
        // 显示屏清0
        this->ui->lcd_display->display(0);

}

void expr::on_btn_equal_clicked()
{
    // 1. 获取num2
        bool ok;
        int num = this->tmp.toInt(&ok);
        this->mode->setNum2(num);
        // 2. 计算num1和num2的运算结果
        QString res = this->mode->doExpr();
        // 3. 显示计算结果
        this->ui->lcd_display->display(res);
        // 4. 清除tmp内容，避免影响后续计算
        this->tmp = "";
}

void expr::on_btn_div_clicked()
{
    // 用于检测是否转化成功
       bool ok;
       // 1. 把当前屏幕上显示的string转为int存在num中
       int num = this->tmp.toInt(&ok);
       // 2. 当点击"/"号时，把num1的值设置为num
       this->mode->setNum1(num);
       // 3. 清除当前屏幕
       this->tmp = "";
       // 4. 记录点击的运算符
       QString ex = this->ui->btn_div->text();
       this->mode->setFlag(ex);
}

void expr::on_btn_1_clicked()
{
    this->tmp += this->ui->btn_1->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_2_clicked()
{
    this->tmp += this->ui->btn_2->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_3_clicked()
{
    this->tmp += this->ui->btn_3->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_mul_clicked()
{
    // 用于检测是否转化成功
       bool ok;
       // 1. 把当前屏幕上显示的string转为int存在num中
       int num = this->tmp.toInt(&ok);
       // 2. 当点击"*"号时，把num1的值设置为num
       this->mode->setNum1(num);
       // 3. 清除当前屏幕
       this->tmp = "";
       // 4. 记录点击的运算符
       QString ex = this->ui->btn_mul->text();
       this->mode->setFlag(ex);
}

void expr::on_btn_4_clicked()
{
    this->tmp += this->ui->btn_4->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_5_clicked()
{
    this->tmp += this->ui->btn_5->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_6_clicked()
{
    this->tmp += this->ui->btn_6->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_sub_clicked()
{
    // 用于检测是否转化成功
       bool ok;
       // 1. 把当前屏幕上显示的string转为int存在num中
       int num = this->tmp.toInt(&ok);
       // 2. 当点击"-"号时，把num1的值设置为num
       this->mode->setNum1(num);
       // 3. 清除当前屏幕
       this->tmp = "";
       // 4. 记录点击的运算符
       QString ex = this->ui->btn_sub->text();
       this->mode->setFlag(ex);

}

void expr::on_btn_7_clicked()
{
    this->tmp += this->ui->btn_7->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_8_clicked()
{
    this->tmp += this->ui->btn_8->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_9_clicked()
{
    this->tmp += this->ui->btn_9->text();
        this->ui->lcd_display->display(this->tmp);
}

void expr::on_btn_plus_clicked()
{
    // 用于检测是否转化成功
       bool ok;
       // 1. 把当前屏幕上显示的string转为int存在num中
       int num = this->tmp.toInt(&ok);
       // 2. 当点击"+"号时，把num1的值设置为num
       this->mode->setNum1(num);
       // 3. 清除当前屏幕
       this->tmp = "";
       // 4. 记录点击的运算符
       QString ex = this->ui->btn_plus->text();
       this->mode->setFlag(ex);

}





void expr::on_lcd_display_overflow()
{

}

void expr::on_expr_accepted()
{

}


void expr::on_lcd_display_destroyed()
{

}
