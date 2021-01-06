#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private:
    void openFile();
    void saveFile();

    QAction *openAction;
    QAction *saveAction;

    QTextEdit *textEdit;

   protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif  // MAINWINDOW_H
