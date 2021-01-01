#include "widget.h"

#include <QApplication>
#include <QDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QDialog modelLessDlg;
    modelLessDlg.setWindowTitle("非模态对话框");
    modelLessDlg.show();
    modelLessDlg.resize(200,100);
    qDebug() << "显示完非模态对话框后，不需要等用户操作就会立马执行本条语句";

    return a.exec();
}
