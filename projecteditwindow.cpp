#include "projecteditwindow.h"
#include "ui_projecteditwindow.h"

ProjectEditWindow::ProjectEditWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectEditWindow)
{
    ui->setupUi(this);
}

ProjectEditWindow::~ProjectEditWindow()
{
    delete ui;
}
