/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *LoginMenu;
    QGroupBox *groupBox_menu;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_signup;
    QPushButton *pushButton_exit;
    QLabel *label_14;
    QWidget *Login;
    QGroupBox *groupBox_login;
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_loginconnect;
    QLabel *label_login;
    QLabel *label_3;
    QPushButton *pushButton_toSignup;
    QPushButton *pushButton_backlogin;
    QPushButton *pushButton_logout;
    QWidget *Signup;
    QGroupBox *groupBox_signup;
    QLabel *label_username_2;
    QLabel *label_password_2;
    QLineEdit *lineEdit_username_2;
    QLineEdit *lineEdit_password_2;
    QPushButton *pushButton_signupconnect;
    QLabel *label_signup;
    QPushButton *pushButton_backsignup;
    QLabel *label_4;
    QPushButton *pushButton_toLogin;
    QWidget *MainMenu;
    QPushButton *pushButton_backmenu;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_astazi;
    QPushButton *pushButton_sosiri;
    QPushButton *pushButton_plecari;
    QPushButton *pushButton_signal;
    QPushButton *pushButton_exit_2;
    QWidget *MersulTrenurilor;
    QPushButton *pushButton_backtomenu;
    QLabel *label_titlu;
    QTableWidget *tableAstazi;
    QLabel *label_5;
    QLabel *label_astazi;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_idastazi;
    QLabel *label_7;
    QLineEdit *lineEdit_minutesastazi;
    QPushButton *pushButton_signalAstazi;
    QPushButton *pushButton_reAstazi;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_veziastazi;
    QPushButton *pushButton_selectastazi;
    QLineEdit *lineEdit_oras;
    QWidget *Sosiri;
    QPushButton *pushButton_backtomenu_2;
    QTableWidget *tableSosiri;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit_idsosiri;
    QLabel *label_10;
    QLineEdit *lineEdit_minutessosiri;
    QPushButton *pushButton_signalSosiri;
    QLabel *label_sosiri;
    QPushButton *pushButton_reSosiri;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_vezisosiri;
    QPushButton *pushButton_selectsosiri;
    QLineEdit *lineEdit_oras_2;
    QWidget *Plecari;
    QPushButton *pushButton_backtomenu_3;
    QTableWidget *tablePlecari;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLineEdit *lineEdit_idplecari;
    QLabel *label_12;
    QLineEdit *lineEdit_minutesplecari;
    QPushButton *pushButton_signalPlecari;
    QLabel *label_plecari;
    QLabel *label_13;
    QPushButton *pushButton_reSosiri_2;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_veziplecari;
    QPushButton *pushButton_selectplecari;
    QLineEdit *lineEdit_oras_3;
    QWidget *Signal;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_id;
    QLabel *label;
    QLineEdit *lineEdit_minutes;
    QPushButton *pushButton_signal_2;
    QPushButton *pushButton_backtomenu_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("#LoginMenu,#Login,#Signup{\n"
" background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #4A646C, stop: 1 #64E986);\n"
"}\n"
"\n"
"#MersulTrenurilor,#Sosiri,#Plecari,#Signal{\n"
"    background-color:  #475C7A;\n"
"}\n"
"\n"
"QGroupBox{\n"
"    background-color:  #317873;\n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; \n"
"}\n"
"\n"
"#MainMenu{\n"
" background-color:  #685D79;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        LoginMenu = new QWidget();
        LoginMenu->setObjectName(QString::fromUtf8("LoginMenu"));
        groupBox_menu = new QGroupBox(LoginMenu);
        groupBox_menu->setObjectName(QString::fromUtf8("groupBox_menu"));
        groupBox_menu->setGeometry(QRect(230, 150, 291, 321));
        verticalLayout = new QVBoxLayout(groupBox_menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_login = new QPushButton(groupBox_menu);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        verticalLayout->addWidget(pushButton_login);

        pushButton_signup = new QPushButton(groupBox_menu);
        pushButton_signup->setObjectName(QString::fromUtf8("pushButton_signup"));

        verticalLayout->addWidget(pushButton_signup);

        pushButton_exit = new QPushButton(groupBox_menu);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);

        label_14 = new QLabel(LoginMenu);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(100, 30, 611, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Century Schoolbook L"));
        font.setPointSize(48);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_14->setFont(font);
        stackedWidget->addWidget(LoginMenu);
        Login = new QWidget();
        Login->setObjectName(QString::fromUtf8("Login"));
        groupBox_login = new QGroupBox(Login);
        groupBox_login->setObjectName(QString::fromUtf8("groupBox_login"));
        groupBox_login->setGeometry(QRect(220, 40, 321, 371));
        label_username = new QLabel(groupBox_login);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(40, 90, 91, 21));
        label_password = new QLabel(groupBox_login);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(40, 140, 101, 31));
        lineEdit_username = new QLineEdit(groupBox_login);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(140, 77, 131, 31));
        lineEdit_password = new QLineEdit(groupBox_login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(140, 137, 131, 31));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        pushButton_loginconnect = new QPushButton(groupBox_login);
        pushButton_loginconnect->setObjectName(QString::fromUtf8("pushButton_loginconnect"));
        pushButton_loginconnect->setGeometry(QRect(110, 240, 90, 28));
        pushButton_loginconnect->setStyleSheet(QString::fromUtf8("#pushButton_loginconnect{ \n"
"background-color: red;\n"
"}"));
        label_login = new QLabel(groupBox_login);
        label_login->setObjectName(QString::fromUtf8("label_login"));
        label_login->setGeometry(QRect(10, 280, 301, 21));
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 440, 181, 31));
        pushButton_toSignup = new QPushButton(Login);
        pushButton_toSignup->setObjectName(QString::fromUtf8("pushButton_toSignup"));
        pushButton_toSignup->setGeometry(QRect(420, 440, 90, 28));
        pushButton_backlogin = new QPushButton(Login);
        pushButton_backlogin->setObjectName(QString::fromUtf8("pushButton_backlogin"));
        pushButton_backlogin->setGeometry(QRect(10, 10, 90, 28));
        pushButton_logout = new QPushButton(Login);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(320, 480, 90, 28));
        stackedWidget->addWidget(Login);
        Signup = new QWidget();
        Signup->setObjectName(QString::fromUtf8("Signup"));
        groupBox_signup = new QGroupBox(Signup);
        groupBox_signup->setObjectName(QString::fromUtf8("groupBox_signup"));
        groupBox_signup->setGeometry(QRect(220, 40, 321, 371));
        label_username_2 = new QLabel(groupBox_signup);
        label_username_2->setObjectName(QString::fromUtf8("label_username_2"));
        label_username_2->setGeometry(QRect(30, 90, 58, 16));
        label_password_2 = new QLabel(groupBox_signup);
        label_password_2->setObjectName(QString::fromUtf8("label_password_2"));
        label_password_2->setGeometry(QRect(30, 140, 58, 16));
        lineEdit_username_2 = new QLineEdit(groupBox_signup);
        lineEdit_username_2->setObjectName(QString::fromUtf8("lineEdit_username_2"));
        lineEdit_username_2->setGeometry(QRect(100, 80, 113, 28));
        lineEdit_password_2 = new QLineEdit(groupBox_signup);
        lineEdit_password_2->setObjectName(QString::fromUtf8("lineEdit_password_2"));
        lineEdit_password_2->setGeometry(QRect(100, 130, 113, 28));
        pushButton_signupconnect = new QPushButton(groupBox_signup);
        pushButton_signupconnect->setObjectName(QString::fromUtf8("pushButton_signupconnect"));
        pushButton_signupconnect->setGeometry(QRect(110, 210, 90, 28));
        label_signup = new QLabel(groupBox_signup);
        label_signup->setObjectName(QString::fromUtf8("label_signup"));
        label_signup->setGeometry(QRect(97, 270, 181, 20));
        pushButton_backsignup = new QPushButton(Signup);
        pushButton_backsignup->setObjectName(QString::fromUtf8("pushButton_backsignup"));
        pushButton_backsignup->setGeometry(QRect(10, 10, 90, 28));
        label_4 = new QLabel(Signup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 440, 161, 16));
        pushButton_toLogin = new QPushButton(Signup);
        pushButton_toLogin->setObjectName(QString::fromUtf8("pushButton_toLogin"));
        pushButton_toLogin->setGeometry(QRect(430, 430, 90, 28));
        stackedWidget->addWidget(Signup);
        MainMenu = new QWidget();
        MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        pushButton_backmenu = new QPushButton(MainMenu);
        pushButton_backmenu->setObjectName(QString::fromUtf8("pushButton_backmenu"));
        pushButton_backmenu->setGeometry(QRect(10, 10, 90, 28));
        groupBox = new QGroupBox(MainMenu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(210, 40, 351, 431));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_astazi = new QPushButton(groupBox);
        pushButton_astazi->setObjectName(QString::fromUtf8("pushButton_astazi"));

        verticalLayout_2->addWidget(pushButton_astazi);

        pushButton_sosiri = new QPushButton(groupBox);
        pushButton_sosiri->setObjectName(QString::fromUtf8("pushButton_sosiri"));

        verticalLayout_2->addWidget(pushButton_sosiri);

        pushButton_plecari = new QPushButton(groupBox);
        pushButton_plecari->setObjectName(QString::fromUtf8("pushButton_plecari"));

        verticalLayout_2->addWidget(pushButton_plecari);

        pushButton_signal = new QPushButton(groupBox);
        pushButton_signal->setObjectName(QString::fromUtf8("pushButton_signal"));

        verticalLayout_2->addWidget(pushButton_signal);

        pushButton_exit_2 = new QPushButton(groupBox);
        pushButton_exit_2->setObjectName(QString::fromUtf8("pushButton_exit_2"));

        verticalLayout_2->addWidget(pushButton_exit_2);

        stackedWidget->addWidget(MainMenu);
        MersulTrenurilor = new QWidget();
        MersulTrenurilor->setObjectName(QString::fromUtf8("MersulTrenurilor"));
        pushButton_backtomenu = new QPushButton(MersulTrenurilor);
        pushButton_backtomenu->setObjectName(QString::fromUtf8("pushButton_backtomenu"));
        pushButton_backtomenu->setGeometry(QRect(10, 10, 90, 28));
        label_titlu = new QLabel(MersulTrenurilor);
        label_titlu->setObjectName(QString::fromUtf8("label_titlu"));
        label_titlu->setGeometry(QRect(240, 30, 58, 16));
        tableAstazi = new QTableWidget(MersulTrenurilor);
        tableAstazi->setObjectName(QString::fromUtf8("tableAstazi"));
        tableAstazi->setGeometry(QRect(10, 70, 761, 291));
        tableAstazi->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label_5 = new QLabel(MersulTrenurilor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 10, 231, 16));
        label_astazi = new QLabel(MersulTrenurilor);
        label_astazi->setObjectName(QString::fromUtf8("label_astazi"));
        label_astazi->setGeometry(QRect(260, 40, 211, 16));
        groupBox_3 = new QGroupBox(MersulTrenurilor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 440, 761, 91));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_idastazi = new QLineEdit(groupBox_3);
        lineEdit_idastazi->setObjectName(QString::fromUtf8("lineEdit_idastazi"));

        horizontalLayout_2->addWidget(lineEdit_idastazi);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lineEdit_minutesastazi = new QLineEdit(groupBox_3);
        lineEdit_minutesastazi->setObjectName(QString::fromUtf8("lineEdit_minutesastazi"));

        horizontalLayout_2->addWidget(lineEdit_minutesastazi);

        pushButton_signalAstazi = new QPushButton(groupBox_3);
        pushButton_signalAstazi->setObjectName(QString::fromUtf8("pushButton_signalAstazi"));

        horizontalLayout_2->addWidget(pushButton_signalAstazi);

        pushButton_reAstazi = new QPushButton(MersulTrenurilor);
        pushButton_reAstazi->setObjectName(QString::fromUtf8("pushButton_reAstazi"));
        pushButton_reAstazi->setGeometry(QRect(680, 10, 90, 28));
        groupBox_6 = new QGroupBox(MersulTrenurilor);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 366, 331, 71));
        horizontalLayout_6 = new QHBoxLayout(groupBox_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_veziastazi = new QPushButton(groupBox_6);
        pushButton_veziastazi->setObjectName(QString::fromUtf8("pushButton_veziastazi"));

        horizontalLayout_6->addWidget(pushButton_veziastazi);

        pushButton_selectastazi = new QPushButton(groupBox_6);
        pushButton_selectastazi->setObjectName(QString::fromUtf8("pushButton_selectastazi"));

        horizontalLayout_6->addWidget(pushButton_selectastazi);

        lineEdit_oras = new QLineEdit(groupBox_6);
        lineEdit_oras->setObjectName(QString::fromUtf8("lineEdit_oras"));

        horizontalLayout_6->addWidget(lineEdit_oras);

        stackedWidget->addWidget(MersulTrenurilor);
        Sosiri = new QWidget();
        Sosiri->setObjectName(QString::fromUtf8("Sosiri"));
        pushButton_backtomenu_2 = new QPushButton(Sosiri);
        pushButton_backtomenu_2->setObjectName(QString::fromUtf8("pushButton_backtomenu_2"));
        pushButton_backtomenu_2->setGeometry(QRect(10, 10, 90, 28));
        tableSosiri = new QTableWidget(Sosiri);
        tableSosiri->setObjectName(QString::fromUtf8("tableSosiri"));
        tableSosiri->setGeometry(QRect(10, 70, 761, 291));
        tableSosiri->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label_8 = new QLabel(Sosiri);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 10, 231, 16));
        groupBox_4 = new QGroupBox(Sosiri);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 440, 761, 91));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        lineEdit_idsosiri = new QLineEdit(groupBox_4);
        lineEdit_idsosiri->setObjectName(QString::fromUtf8("lineEdit_idsosiri"));

        horizontalLayout_3->addWidget(lineEdit_idsosiri);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        lineEdit_minutessosiri = new QLineEdit(groupBox_4);
        lineEdit_minutessosiri->setObjectName(QString::fromUtf8("lineEdit_minutessosiri"));

        horizontalLayout_3->addWidget(lineEdit_minutessosiri);

        pushButton_signalSosiri = new QPushButton(groupBox_4);
        pushButton_signalSosiri->setObjectName(QString::fromUtf8("pushButton_signalSosiri"));

        horizontalLayout_3->addWidget(pushButton_signalSosiri);

        label_sosiri = new QLabel(Sosiri);
        label_sosiri->setObjectName(QString::fromUtf8("label_sosiri"));
        label_sosiri->setGeometry(QRect(290, 40, 211, 16));
        pushButton_reSosiri = new QPushButton(Sosiri);
        pushButton_reSosiri->setObjectName(QString::fromUtf8("pushButton_reSosiri"));
        pushButton_reSosiri->setGeometry(QRect(680, 10, 90, 28));
        groupBox_7 = new QGroupBox(Sosiri);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 370, 331, 71));
        horizontalLayout_7 = new QHBoxLayout(groupBox_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_vezisosiri = new QPushButton(groupBox_7);
        pushButton_vezisosiri->setObjectName(QString::fromUtf8("pushButton_vezisosiri"));

        horizontalLayout_7->addWidget(pushButton_vezisosiri);

        pushButton_selectsosiri = new QPushButton(groupBox_7);
        pushButton_selectsosiri->setObjectName(QString::fromUtf8("pushButton_selectsosiri"));

        horizontalLayout_7->addWidget(pushButton_selectsosiri);

        lineEdit_oras_2 = new QLineEdit(groupBox_7);
        lineEdit_oras_2->setObjectName(QString::fromUtf8("lineEdit_oras_2"));

        horizontalLayout_7->addWidget(lineEdit_oras_2);

        stackedWidget->addWidget(Sosiri);
        Plecari = new QWidget();
        Plecari->setObjectName(QString::fromUtf8("Plecari"));
        pushButton_backtomenu_3 = new QPushButton(Plecari);
        pushButton_backtomenu_3->setObjectName(QString::fromUtf8("pushButton_backtomenu_3"));
        pushButton_backtomenu_3->setGeometry(QRect(10, 10, 90, 28));
        tablePlecari = new QTableWidget(Plecari);
        tablePlecari->setObjectName(QString::fromUtf8("tablePlecari"));
        tablePlecari->setGeometry(QRect(10, 60, 761, 301));
        tablePlecari->setEditTriggers(QAbstractItemView::NoEditTriggers);
        groupBox_5 = new QGroupBox(Plecari);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 440, 761, 91));
        horizontalLayout_4 = new QHBoxLayout(groupBox_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_4->addWidget(label_11);

        lineEdit_idplecari = new QLineEdit(groupBox_5);
        lineEdit_idplecari->setObjectName(QString::fromUtf8("lineEdit_idplecari"));

        horizontalLayout_4->addWidget(lineEdit_idplecari);

        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        lineEdit_minutesplecari = new QLineEdit(groupBox_5);
        lineEdit_minutesplecari->setObjectName(QString::fromUtf8("lineEdit_minutesplecari"));

        horizontalLayout_4->addWidget(lineEdit_minutesplecari);

        pushButton_signalPlecari = new QPushButton(groupBox_5);
        pushButton_signalPlecari->setObjectName(QString::fromUtf8("pushButton_signalPlecari"));

        horizontalLayout_4->addWidget(pushButton_signalPlecari);

        label_plecari = new QLabel(Plecari);
        label_plecari->setObjectName(QString::fromUtf8("label_plecari"));
        label_plecari->setGeometry(QRect(290, 30, 211, 16));
        label_13 = new QLabel(Plecari);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(290, 10, 291, 16));
        pushButton_reSosiri_2 = new QPushButton(Plecari);
        pushButton_reSosiri_2->setObjectName(QString::fromUtf8("pushButton_reSosiri_2"));
        pushButton_reSosiri_2->setGeometry(QRect(680, 10, 90, 28));
        groupBox_8 = new QGroupBox(Plecari);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 370, 331, 71));
        horizontalLayout_8 = new QHBoxLayout(groupBox_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_veziplecari = new QPushButton(groupBox_8);
        pushButton_veziplecari->setObjectName(QString::fromUtf8("pushButton_veziplecari"));

        horizontalLayout_8->addWidget(pushButton_veziplecari);

        pushButton_selectplecari = new QPushButton(groupBox_8);
        pushButton_selectplecari->setObjectName(QString::fromUtf8("pushButton_selectplecari"));

        horizontalLayout_8->addWidget(pushButton_selectplecari);

        lineEdit_oras_3 = new QLineEdit(groupBox_8);
        lineEdit_oras_3->setObjectName(QString::fromUtf8("lineEdit_oras_3"));

        horizontalLayout_8->addWidget(lineEdit_oras_3);

        stackedWidget->addWidget(Plecari);
        Signal = new QWidget();
        Signal->setObjectName(QString::fromUtf8("Signal"));
        groupBox_2 = new QGroupBox(Signal);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(90, 160, 581, 201));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_id = new QLineEdit(groupBox_2);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lineEdit_id);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_minutes = new QLineEdit(groupBox_2);
        lineEdit_minutes->setObjectName(QString::fromUtf8("lineEdit_minutes"));

        horizontalLayout->addWidget(lineEdit_minutes);

        pushButton_signal_2 = new QPushButton(groupBox_2);
        pushButton_signal_2->setObjectName(QString::fromUtf8("pushButton_signal_2"));
        pushButton_signal_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton_signal_2);

        pushButton_backtomenu_4 = new QPushButton(Signal);
        pushButton_backtomenu_4->setObjectName(QString::fromUtf8("pushButton_backtomenu_4"));
        pushButton_backtomenu_4->setGeometry(QRect(10, 10, 90, 28));
        stackedWidget->addWidget(Signal);

        horizontalLayout_5->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_loginconnect->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_menu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
        pushButton_login->setText(QApplication::translate("MainWindow", "Log in", nullptr));
        pushButton_signup->setText(QApplication::translate("MainWindow", "Sign up", nullptr));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Mersul trenurilor", nullptr));
        groupBox_login->setTitle(QString());
        label_username->setText(QApplication::translate("MainWindow", "username", nullptr));
        label_password->setText(QApplication::translate("MainWindow", "password", nullptr));
        pushButton_loginconnect->setText(QApplication::translate("MainWindow", "Log in", nullptr));
        label_login->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Don't have an account?", nullptr));
        pushButton_toSignup->setText(QApplication::translate("MainWindow", "Sign up", nullptr));
        pushButton_backlogin->setText(QApplication::translate("MainWindow", "Back", nullptr));
        pushButton_logout->setText(QApplication::translate("MainWindow", "Log out", nullptr));
        groupBox_signup->setTitle(QString());
        label_username_2->setText(QApplication::translate("MainWindow", "username", nullptr));
        label_password_2->setText(QApplication::translate("MainWindow", "password", nullptr));
        pushButton_signupconnect->setText(QApplication::translate("MainWindow", "Sign up", nullptr));
        label_signup->setText(QString());
        pushButton_backsignup->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Already have an account?", nullptr));
        pushButton_toLogin->setText(QApplication::translate("MainWindow", "Log in", nullptr));
        pushButton_backmenu->setText(QApplication::translate("MainWindow", "Back", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
        pushButton_astazi->setText(QApplication::translate("MainWindow", "Mersul trenurilor", nullptr));
        pushButton_sosiri->setText(QApplication::translate("MainWindow", "Sosiri", nullptr));
        pushButton_plecari->setText(QApplication::translate("MainWindow", "Plecari", nullptr));
        pushButton_signal->setText(QApplication::translate("MainWindow", "Signal delay", nullptr));
        pushButton_exit_2->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        pushButton_backtomenu->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_titlu->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "MERSUL TRENURILOR ASTAZI", nullptr));
        label_astazi->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Signal delay", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Train ID:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Minutes:", nullptr));
        pushButton_signalAstazi->setText(QApplication::translate("MainWindow", "signal", nullptr));
        pushButton_reAstazi->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        groupBox_6->setTitle(QString());
        pushButton_veziastazi->setText(QApplication::translate("MainWindow", "Vezi toate", nullptr));
        pushButton_selectastazi->setText(QApplication::translate("MainWindow", "Selecteaza oras", nullptr));
        pushButton_backtomenu_2->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "SOSIRI IN URMATOAREA ORA", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "signal delay", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Train ID:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Minutes:", nullptr));
        pushButton_signalSosiri->setText(QApplication::translate("MainWindow", "signal", nullptr));
        label_sosiri->setText(QString());
        pushButton_reSosiri->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        groupBox_7->setTitle(QString());
        pushButton_vezisosiri->setText(QApplication::translate("MainWindow", "Vezi toate", nullptr));
        pushButton_selectsosiri->setText(QApplication::translate("MainWindow", "Selecteaza oras", nullptr));
        pushButton_backtomenu_3->setText(QApplication::translate("MainWindow", "Back", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "signal delay", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Train ID:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Minutes:", nullptr));
        pushButton_signalPlecari->setText(QApplication::translate("MainWindow", "signal", nullptr));
        label_plecari->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "PLECARI IN URMATOAREA ORA", nullptr));
        pushButton_reSosiri_2->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        groupBox_8->setTitle(QString());
        pushButton_veziplecari->setText(QApplication::translate("MainWindow", "Vezi toate", nullptr));
        pushButton_selectplecari->setText(QApplication::translate("MainWindow", "Selecteaza oras", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "signal delay", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Train ID:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Minutes:", nullptr));
        pushButton_signal_2->setText(QApplication::translate("MainWindow", "signal", nullptr));
        pushButton_backtomenu_4->setText(QApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
