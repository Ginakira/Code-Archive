#include "widget.h"
#include "ui_widget.h"
#include "customdialog.h"
#include <QDebug>
#include <QDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnWindow_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setWindowModality(Qt::WindowModal);
    dlg->show();
    qDebug() << "虽然显示模态对话框，但我不需要等用户操作完就会立马执行";
}

void Widget::on_btnApp_clicked()
{
    QDialog *dlg = new QDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setWindowModality(Qt::ApplicationModal);
    dlg->show();
    qDebug() << "虽然显示模态对话框，但我也不需要等用户操作完就会立马执行";
}

void Widget::on_btnCustom_clicked()
{
    CustomDialog* dlg = new CustomDialog(this);
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置对话框关闭后，自动销毁
    int ret = dlg->exec();
    if (ret == QDialog::Accepted)
    {
        ui->lineEdit->setText("你点击了OK按钮");
    }
    else if (ret == QDialog::Rejected)
    {
        ui->lineEdit->setText("你点击了Cancle按钮");
    }
}
