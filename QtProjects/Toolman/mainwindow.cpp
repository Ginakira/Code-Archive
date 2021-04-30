#include "mainwindow.h"

#include <QDate>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->targetVideoNameLineEdit->setText(
        QString("ytb%1.mp4").arg(QDate::currentDate().toString("MMdd")));
}

void MainWindow::on_urlLineEdit_textChanged(const QString &text) {
    ui->targetPathLineEdit->setText(text);
    ui->targetCoverNameLineEdit->setText(text);
}

MainWindow::~MainWindow() { delete ui; }
