#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connect_tcp.h"
#include <QTableWidget>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//se asigura ca aplicatia se deschide pe prima pagina

}

MainWindow::~MainWindow()
{
    delete ui;
}


//LOGIN
void MainWindow::on_pushButton_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_loginconnect_clicked()
{
    QString username_string = ui->lineEdit_username->text();
    QString password_string = ui->lineEdit_password->text();

    QByteArray ba = username_string.toLocal8Bit();
    const char *username = ba.data();

    QByteArray ba2 = password_string.toLocal8Bit();
    const char *password = ba2.data();

    char command[100];
    strcpy(command,"login");
    strcat(command,";");
    strcat(command,username);
    strcat(command,";");
    strcat(command,password);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    if(strcmp(x.response,"true") == 0)//daca serverul gaseste utilizatorul in XML
    {
        ui->label_login->setText("Login successful!");
        ui->stackedWidget->setCurrentIndex(3);
    }
    else{
        ui->label_login->setText("Incorrect username or password!");
    }

}

void MainWindow::on_pushButton_backmenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_logout_clicked()
{
    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
}

//SIGNUP
void MainWindow::on_pushButton_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_backsignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_signupconnect_clicked()
{
    QString username_string = ui->lineEdit_username_2->text();
    QString password_string = ui->lineEdit_password_2->text();

    QByteArray ba = username_string.toLocal8Bit();
    const char *username = ba.data();

    QByteArray ba2 = password_string.toLocal8Bit();
    const char *password = ba2.data();

    char command[100];
    strcpy(command,"signup");
    strcat(command,";");
    strcat(command,username);
    strcat(command,";");
    strcat(command,password);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();
    if(strcmp(x.response,"true") == 0){
        ui->label_signup->setText("Signup successful!");
    }
    else if(strcmp(x.response,"false") == 0){
        ui->label_signup->setText("Username already taken!");
    }

}

void MainWindow::on_pushButton_toLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//MERSUL TRENURILOR ASTAZI
void MainWindow::on_pushButton_astazi_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    char command[1000];
    strcpy(command,"mersulastazi");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[100];
    cout<<x.response<<'\n';
    char* train = strtok(x.response, ";");

    while(train)
    {
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }

    if(nr == 0) ui->label_astazi->setText("No trains available!");


    ui->tableAstazi->setRowCount(nr);
    ui->tableAstazi->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tableAstazi->setHorizontalHeaderLabels(hLabels);

    for(int i=0; i<ui->tableAstazi->rowCount(); i++)
    {
        QTableWidgetItem *item;
        for(int j=0; j<ui->tableAstazi->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setText(tr[i].info[j]);
            ui->tableAstazi->setItem(i,j,item);
        }
    }
}

void MainWindow::on_pushButton_backtomenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->label_astazi->clear();
}

void MainWindow::on_pushButton_toSignup_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_signalAstazi_clicked()
{
    QString id_string = ui->lineEdit_idastazi->text();
    QString minutes_string = ui->lineEdit_minutesastazi->text();

    QByteArray ba = id_string.toLocal8Bit();
    const char *id = ba.data();

    QByteArray ba2 = minutes_string.toLocal8Bit();
    const char *minutes = ba2.data();

    char command[100];
    strcpy(command,"signaldelay");
    strcat(command,";");
    strcat(command, id);
    strcat(command,";");
    strcat(command, minutes);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    ui->lineEdit_idastazi->clear();
    ui->lineEdit_minutesastazi->clear();
    on_pushButton_astazi_clicked();
}

//SOSIRI IN URMATOAREA ORA
void MainWindow::on_pushButton_sosiri_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    char command[100];
    strcpy(command,"sosiri");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();
    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[10];
    char* train = strtok(x.response, ";");
    while(train)
    {
        cout<<train<<'\n';
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }

    if(nr == 0) ui->label_sosiri->setText("No trains available!");


    ui->tableSosiri->setRowCount(nr);
    ui->tableSosiri->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tableSosiri->setHorizontalHeaderLabels(hLabels);

    for(int i=0; i<ui->tableSosiri->rowCount(); i++)
    {
        QTableWidgetItem *item;
        for(int j=0; j<ui->tableSosiri->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setText(tr[i].info[j]);
            ui->tableSosiri->setItem(i,j,item);
        }
    }
}

void MainWindow::on_pushButton_backtomenu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->label_sosiri->clear();

}

void MainWindow::on_pushButton_signalSosiri_clicked()
{
    QString id_string = ui->lineEdit_idsosiri->text();
    QString minutes_string = ui->lineEdit_minutessosiri->text();

    QByteArray ba = id_string.toLocal8Bit();
    const char *id = ba.data();

    QByteArray ba2 = minutes_string.toLocal8Bit();
    const char *minutes = ba2.data();

    char command[100];
    strcpy(command,"signaldelay");
    strcat(command,";");
    strcat(command, id);
    strcat(command,";");
    strcat(command, minutes);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    ui->lineEdit_idsosiri->clear();
    ui->lineEdit_minutessosiri->clear();
    on_pushButton_sosiri_clicked();
}

//PLECARI IN URMATOAREA ORA
void MainWindow::on_pushButton_plecari_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    char command[100];
    strcpy(command,"plecari");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();
    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[10];
    char* train = strtok(x.response, ";");
    while(train)
    {
        cout<<train<<'\n';
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }

    if(nr == 0) ui->label_plecari->setText("No trains available!");


    ui->tablePlecari->setRowCount(nr);
    ui->tablePlecari->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tablePlecari->setHorizontalHeaderLabels(hLabels);

    for(int i=0; i<ui->tablePlecari->rowCount(); i++)
    {
        QTableWidgetItem *item;
        for(int j=0; j<ui->tablePlecari->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setText(tr[i].info[j]);
            ui->tablePlecari->setItem(i,j,item);
        }
    }
}

void MainWindow::on_pushButton_backtomenu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->label_plecari->clear();
}

void MainWindow::on_pushButton_signalPlecari_clicked()
{
    QString id_string = ui->lineEdit_idplecari->text();
    QString minutes_string = ui->lineEdit_minutesplecari->text();

    QByteArray ba = id_string.toLocal8Bit();
    const char *id = ba.data();

    QByteArray ba2 = minutes_string.toLocal8Bit();
    const char *minutes = ba2.data();

    char command[100];
    strcpy(command,"signaldelay");
    strcat(command,";");
    strcat(command, id);
    strcat(command,";");
    strcat(command, minutes);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    ui->lineEdit_idplecari->clear();
    ui->lineEdit_minutesplecari->clear();
    on_pushButton_plecari_clicked();
}


//SEMNALEAZA INTARZIERE
void MainWindow::on_pushButton_signal_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_pushButton_signal_2_clicked()
{
    QString id_string = ui->lineEdit_id->text();
    QString minutes_string = ui->lineEdit_minutes->text();

    QByteArray ba = id_string.toLocal8Bit();
    const char *id = ba.data();

    QByteArray ba2 = minutes_string.toLocal8Bit();
    const char *minutes = ba2.data();

    char command[100];
    strcpy(command,"signaldelay");
    strcat(command,";");
    strcat(command, id);
    strcat(command,";");
    strcat(command, minutes);

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    ui->lineEdit_id->clear();
    ui->lineEdit_minutes->clear();
}

void MainWindow::on_pushButton_backtomenu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//BUTOANE EXIT
void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_exit_2_clicked()
{
     this->close();
}

void MainWindow::on_pushButton_backlogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_reAstazi_clicked()
{
    on_pushButton_astazi_clicked();
}

void MainWindow::on_pushButton_reSosiri_clicked()
{
    on_pushButton_sosiri_clicked();
}

void MainWindow::on_pushButton_reSosiri_2_clicked()
{
    on_pushButton_plecari_clicked();
}



void MainWindow::on_pushButton_selectastazi_clicked()
{
    QString oras_string = ui->lineEdit_oras->text();
    QByteArray ba = oras_string.toLocal8Bit();
    const char *oras = ba.data();
     ui->lineEdit_oras->clear();
    ui->stackedWidget->setCurrentIndex(4);
    char command[1000];
    strcpy(command,"mersulastazi");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[100];
    cout<<x.response<<'\n';
    char* train = strtok(x.response, ";");

    while(train)
    {
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }
    for(int i=0; i<nr; i++)
        if(strcmp(tr[i].info[1], oras) != 0 || strcmp(tr[i].info[2], oras) == 0)
    if(nr == 0) ui->label_astazi->setText("No trains available!");

    ui->tableAstazi->clear();

    ui->tableAstazi->setRowCount(nr);
    ui->tableAstazi->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tableAstazi->setHorizontalHeaderLabels(hLabels);
    int i = 0, k=0;
    while(nr!=0){
        QTableWidgetItem *item;
        cout<<tr[i].info[1]<<' '<<tr[i].info[2]<<'\n';
        if(strcmp(tr[i].info[1], oras) == 0 || strcmp(tr[i].info[2], oras) == 0){
           cout<<"da"<<'\n';
        for(int j=0; j<ui->tableAstazi->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setText(tr[i].info[j]);
            ui->tableAstazi->setItem(k,j,item);

        }
        k++;
        }
        nr--;
        i++;
    }
}

void MainWindow::on_pushButton_selectsosiri_clicked()
{
    QString oras_string = ui->lineEdit_oras_2->text();
    QByteArray ba = oras_string.toLocal8Bit();
    const char *oras = ba.data();
    ui->lineEdit_oras_2->clear();
    ui->stackedWidget->setCurrentIndex(4);
    char command[1000];
    strcpy(command,"mersulastazi");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[100];
    char* train = strtok(x.response, ";");

    while(train)
    {
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }
    for(int i=0; i<nr; i++)
        if(strcmp(tr[i].info[1], oras) != 0 || strcmp(tr[i].info[2], oras) == 0)
    if(nr == 0) ui->label_sosiri->setText("No trains available!");

    ui->tableSosiri->clear();

    ui->tableSosiri->setRowCount(nr);
    ui->tableSosiri->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tableSosiri->setHorizontalHeaderLabels(hLabels);
    int i = 0, k=0;
    while(nr!=0){
        QTableWidgetItem *item;
        cout<<tr[i].info[1]<<' '<<tr[i].info[2]<<'\n';
        if(strcmp(tr[i].info[1], oras) == 0 || strcmp(tr[i].info[2], oras) == 0){
            for(int j=0; j<ui->tableSosiri->columnCount(); j++)
            {
                item = new QTableWidgetItem;
                item->setText(tr[i].info[j]);
                ui->tableSosiri->setItem(k,j,item);

            }
            k++;
        }
        nr--;
        i++;
    }
}

void MainWindow::on_pushButton_selectplecari_clicked()
{
    QString oras_string = ui->lineEdit_oras_3->text();
    QByteArray ba = oras_string.toLocal8Bit();
    const char *oras = ba.data();
    ui->lineEdit_oras_3->clear();

    ui->stackedWidget->setCurrentIndex(4);
    char command[1000];
    strcpy(command,"mersulastazi");

    connect_tcp x;
    strcpy(x.msg, command);
    x.connect_to_server();

    struct trenuri{
        char info[7][20];
    };
    int nr = 0;
    trenuri tr[100];
    char* train = strtok(x.response, ";");

    while(train)
    {
        int i = 0, j = 0, index = 0;
        while(i<strlen(train))
        {
            if(train[i] == ',')
            {
                tr[nr].info[index][j] = '\0';
                index++;
                j=0;
            }
            else{
                tr[nr].info[index][j] = train[i];
                j++;
            }
            i++;
        }
        tr[nr].info[index][j] = '\0';
        nr++;
        train =  strtok(NULL, ";");
    }
    for(int i=0; i<nr; i++)
        if(strcmp(tr[i].info[1], oras) != 0 || strcmp(tr[i].info[2], oras) == 0)
    if(nr == 0) ui->label_plecari->setText("No trains available!");

    ui->tablePlecari->clear();

    ui->tablePlecari->setRowCount(nr);
    ui->tablePlecari->setColumnCount(7);

    QStringList hLabels;
    hLabels<<"ID"<<"Plecare"<<"Sosire"<<"Ora plecare"<<"Ora sosire"<<"Intarziere(min)"<<"Estimare";
    ui->tableSosiri->setHorizontalHeaderLabels(hLabels);
    int i = 0, k=0;
    while(nr!=0){
        QTableWidgetItem *item;
        cout<<tr[i].info[1]<<' '<<tr[i].info[2]<<'\n';
        if(strcmp(tr[i].info[1], oras) == 0 || strcmp(tr[i].info[2], oras) == 0){
            for(int j=0; j<ui->tablePlecari->columnCount(); j++)
            {
                item = new QTableWidgetItem;
                item->setText(tr[i].info[j]);
                ui->tablePlecari->setItem(k,j,item);

            }
            k++;
        }
        nr--;
        i++;
    }
}

void MainWindow::on_pushButton_veziastazi_clicked()
{
    on_pushButton_astazi_clicked();
}

void MainWindow::on_pushButton_vezisosiri_clicked()
{
    on_pushButton_sosiri_clicked();
}

void MainWindow::on_pushButton_veziplecari_clicked()
{
    on_pushButton_plecari_clicked();
}
