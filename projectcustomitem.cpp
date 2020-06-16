#include "projectcustomitem.h"
#include "ui_projectcustomitem.h"

ProjectCustomItem::ProjectCustomItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectCustomItem)
{
    ui->setupUi(this);
}

ProjectCustomItem::~ProjectCustomItem()
{
    delete ui;
}
