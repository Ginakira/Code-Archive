#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private slots:
    void on_readoutput();

    void on_readerror();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

   private:
    Ui::MainWindow *ui;
    QProcess *cmd;
};
#endif // MAINWINDOW_H
