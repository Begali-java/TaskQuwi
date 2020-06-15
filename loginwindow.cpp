#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::initAllSettings(){

    ui->passwordLineEdit->setText("");
    ui->emailLineEdit->setText(thisApp()->getLastEmail());

}

void LoginWindow::on_loginPushbutton_clicked()
{

}
