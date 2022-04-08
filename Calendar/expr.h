#ifndef EXPR_H
#define EXPR_H

#include <QDialog>
#include <QString>
#include "model.h"
namespace Ui {
class expr;
}

class expr : public QDialog
{
    Q_OBJECT

public:
    explicit expr(QWidget *parent = 0);
    ~expr();

private slots:
    void on_btn_0_clicked();

    void on_btn_c_clicked();

    void on_btn_equal_clicked();

    void on_btn_div_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_mul_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_sub_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_plus_clicked();

    //void on_lcdNumber_overflow();

    void on_lcd_display_overflow();

    void on_expr_accepted();

    void on_lcd_display_destroyed();

private:
    //屏幕内容
    QString tmp;
    //界面对象和核心功能对象
    Ui::expr *ui;
    model * mode;
};

#endif // EXPR_H
