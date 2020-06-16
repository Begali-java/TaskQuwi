#include "projectlistwindow.h"
#include "ui_projectlistwindow.h"

ProjectListWindow::ProjectListWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectListWindow)
{
    ui->setupUi(this);
}

ProjectListWindow::~ProjectListWindow()
{
    delete ui;
}

void ProjectListWindow::on_projectsBtn_clicked()
{

}

void ProjectListWindow::on_logoutButton_clicked()
{

}
