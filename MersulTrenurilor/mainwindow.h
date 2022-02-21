#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connect_tcp.h"
#include <cstring>

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

    void on_pushButton_login_clicked();

    void on_pushButton_loginconnect_clicked();

    void on_pushButton_backmenu_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_backsignup_clicked();

    void on_pushButton_signupconnect_clicked();

    void on_pushButton_astazi_clicked();

    void on_pushButton_sosiri_clicked();

    void on_pushButton_plecari_clicked();

    void on_pushButton_backtomenu_clicked();

    void on_pushButton_backtomenu_2_clicked();

    void on_pushButton_backtomenu_3_clicked();


    void on_pushButton_signal_clicked();

    void on_pushButton_signal_2_clicked();

    void on_pushButton_backtomenu_4_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_exit_2_clicked();

    void on_pushButton_toSignup_clicked();

    void on_pushButton_toLogin_clicked();

    void on_pushButton_backlogin_clicked();

    void on_pushButton_signalAstazi_clicked();

    void on_pushButton_signalPlecari_clicked();

    void on_pushButton_signalSosiri_clicked();

    void on_pushButton_reAstazi_clicked();

    void on_pushButton_reSosiri_clicked();

    void on_pushButton_reSosiri_2_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_selectastazi_clicked();


    void on_pushButton_selectsosiri_clicked();

    void on_pushButton_selectplecari_clicked();

    void on_pushButton_veziastazi_clicked();

    void on_pushButton_vezisosiri_clicked();

    void on_pushButton_veziplecari_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
