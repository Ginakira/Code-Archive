#include "mainwindow.h"

#include <QMessageBox>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cmd = new QProcess(this);

    QObject::connect(cmd, &QProcess::readyReadStandardOutput, this,
                     &MainWindow::on_readoutput);
    QObject::connect(cmd, &QProcess::readyReadStandardError, this,
                     &MainWindow::on_readerror);

    QString program = "/bin/zsh";
    QStringList args;
    cmd->start(program, args);
    cmd->waitForStarted();
}

MainWindow::~MainWindow() {
    if (cmd != nullptr) {
        cmd->close();
        cmd->waitForFinished();
        delete cmd;
    }
    delete ui;
}

void MainWindow::on_readoutput() {
    this->ui->textBrowser->append(this->cmd->readAllStandardOutput());
}

void MainWindow::on_readerror() {
    QString msg =
        "<font color='#FF0000'>" + cmd->readAllStandardError() + "</font>";
    this->ui->textBrowser->append(msg);
}

void MainWindow::on_pushButton_clicked() {
    cmd->write(ui->lineEdit->text().toLocal8Bit() + '\n');
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_returnPressed() {
    cmd->write(ui->lineEdit->text().toLocal8Bit() + '\n');
    ui->lineEdit->clear();
}
