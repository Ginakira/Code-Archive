/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *statisticsLayout;
    QLabel *fundStatLabel;
    QVBoxLayout *listLayout;
    QTableView *tableView;
    QHBoxLayout *controlLayout;
    QPushButton *moveUpButton;
    QPushButton *pushButton_6;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *refreshButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        statisticsLayout = new QHBoxLayout();
        statisticsLayout->setObjectName(QString::fromUtf8("statisticsLayout"));
        fundStatLabel = new QLabel(centralwidget);
        fundStatLabel->setObjectName(QString::fromUtf8("fundStatLabel"));

        statisticsLayout->addWidget(fundStatLabel);


        verticalLayout_2->addLayout(statisticsLayout);

        listLayout = new QVBoxLayout();
        listLayout->setObjectName(QString::fromUtf8("listLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        listLayout->addWidget(tableView);


        verticalLayout_2->addLayout(listLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName(QString::fromUtf8("controlLayout"));
        moveUpButton = new QPushButton(centralwidget);
        moveUpButton->setObjectName(QString::fromUtf8("moveUpButton"));

        controlLayout->addWidget(moveUpButton);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        controlLayout->addWidget(pushButton_6);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        controlLayout->addWidget(addButton);

        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        controlLayout->addWidget(editButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        controlLayout->addWidget(deleteButton);

        refreshButton = new QPushButton(centralwidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        controlLayout->addWidget(refreshButton);


        verticalLayout_2->addLayout(controlLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        fundStatLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        moveUpButton->setText(QApplication::translate("MainWindow", "\344\270\212\347\247\273", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\344\270\213\347\247\273", nullptr));
        addButton->setText(QApplication::translate("MainWindow", "\346\226\260\345\242\236", nullptr));
        editButton->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        refreshButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
