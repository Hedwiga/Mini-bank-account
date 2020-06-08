/*
 * Filename: mainwindow.cpp
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "account.h"
#include "register.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logIn_clicked()
{
    Login *loginDialog = new Login;
    loginDialog->setModal(true);
    loginDialog->exec();
}

void MainWindow::on_reg_clicked()
{
    Register *registerDialog = new Register;
    registerDialog->setModal(true);
    registerDialog->exec();
}
