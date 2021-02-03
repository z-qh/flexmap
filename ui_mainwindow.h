/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWebEngineView *map;
    QPushButton *pushButton_reset;
    QLineEdit *lineEdit_lon;
    QLineEdit *lineEdit_lat;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_record_node;
    QTextEdit *textEdit_info;
    QPushButton *pushButton_clear_node;
    QPushButton *pushButton;
    QPushButton *pushButton_node_line;
    QPushButton *pushButton_read_file_and_line;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1113, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        map = new QWebEngineView(centralwidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(330, 80, 781, 471));
        pushButton_reset = new QPushButton(centralwidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(40, 20, 81, 31));
        lineEdit_lon = new QLineEdit(centralwidget);
        lineEdit_lon->setObjectName(QString::fromUtf8("lineEdit_lon"));
        lineEdit_lon->setGeometry(QRect(80, 90, 171, 31));
        lineEdit_lat = new QLineEdit(centralwidget);
        lineEdit_lat->setObjectName(QString::fromUtf8("lineEdit_lat"));
        lineEdit_lat->setGeometry(QRect(80, 130, 171, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 100, 31, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 140, 31, 16));
        pushButton_record_node = new QPushButton(centralwidget);
        pushButton_record_node->setObjectName(QString::fromUtf8("pushButton_record_node"));
        pushButton_record_node->setGeometry(QRect(40, 170, 81, 31));
        textEdit_info = new QTextEdit(centralwidget);
        textEdit_info->setObjectName(QString::fromUtf8("textEdit_info"));
        textEdit_info->setGeometry(QRect(40, 220, 211, 221));
        pushButton_clear_node = new QPushButton(centralwidget);
        pushButton_clear_node->setObjectName(QString::fromUtf8("pushButton_clear_node"));
        pushButton_clear_node->setGeometry(QRect(130, 170, 81, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 20, 75, 31));
        pushButton_node_line = new QPushButton(centralwidget);
        pushButton_node_line->setObjectName(QString::fromUtf8("pushButton_node_line"));
        pushButton_node_line->setGeometry(QRect(220, 170, 81, 31));
        pushButton_read_file_and_line = new QPushButton(centralwidget);
        pushButton_read_file_and_line->setObjectName(QString::fromUtf8("pushButton_read_file_and_line"));
        pushButton_read_file_and_line->setGeometry(QRect(240, 20, 81, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1113, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("MainWindow", "\345\233\236\345\210\260\345\216\237\347\202\271", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        pushButton_record_node->setText(QCoreApplication::translate("MainWindow", "\350\256\260\345\275\225\350\267\257\345\276\204\347\202\271", nullptr));
        pushButton_clear_node->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_node_line->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276", nullptr));
        pushButton_read_file_and_line->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
