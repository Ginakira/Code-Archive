#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initStatisticLabel();
}

void MainWindow::initStatisticLabel() {}

MainWindow::~MainWindow()
{
    delete ui;
}

