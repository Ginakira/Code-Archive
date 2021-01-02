/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnWindow;
    QPushButton *btnApp;
    QLineEdit *lineEdit;
    QPushButton *btnCustom;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        btnWindow = new QPushButton(Widget);
        btnWindow->setObjectName(QString::fromUtf8("btnWindow"));
        btnWindow->setGeometry(QRect(40, 60, 151, 32));
        btnWindow->setStyleSheet(QString::fromUtf8("#btnWindow {\n"
"    background: rgb(0, 172, 255);\n"
"    color: #fff;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"#btnWindow:hover {\n"
"	background: rgb(0, 2, 3);\n"
"}"));
        btnApp = new QPushButton(Widget);
        btnApp->setObjectName(QString::fromUtf8("btnApp"));
        btnApp->setGeometry(QRect(40, 100, 151, 32));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 160, 131, 21));
        btnCustom = new QPushButton(Widget);
        btnCustom->setObjectName(QString::fromUtf8("btnCustom"));
        btnCustom->setGeometry(QRect(40, 200, 151, 32));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btnWindow->setText(QApplication::translate("Widget", "\345\274\271\345\207\272\347\252\227\345\217\243\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        btnApp->setText(QApplication::translate("Widget", "\345\274\271\345\207\272\345\272\224\347\224\250\346\250\241\346\200\201\345\257\271\350\257\235\346\241\206", nullptr));
        btnCustom->setText(QApplication::translate("Widget", "\345\274\271\345\207\272\350\207\252\345\256\232\344\271\211\345\257\271\350\257\235\346\241\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
