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
