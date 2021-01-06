#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    saveAction = new QAction(QIcon(":/images/save"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    connect(textEdit, &QTextEdit::textChanged, this,
            [=]() { this->setWindowModified(true); });

    setWindowTitle("TextPad [*]");

    statusBar();
}

MainWindow::~MainWindow() {}

void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile() {
    QString path = QFileDialog::getSaveFileName(this, tr("Open File"), ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty()) {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, tr("Write File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (isWindowModified()) {
        bool exit =
            QMessageBox::question(this, tr("Quit"),
                                  tr("Are you sure to quit this application?"),
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No) == QMessageBox::Yes;
        if (exit) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}
