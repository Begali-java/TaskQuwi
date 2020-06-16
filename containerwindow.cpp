#include "containerwindow.h"
#include "ui_containerwindow.h"

ContainerWindow::ContainerWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContainerWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Quwi Test App"));
    connect(thisApp(),SIGNAL(loginSuccessSignal()),this,SLOT(setProjectWindow()));
    connect(thisApp(),SIGNAL(loginErorSignal(int,QString)),this,SLOT(setShowErrorMessage(int,QString)));

}

ContainerWindow::~ContainerWindow()
{
    delete ui;
}

void ContainerWindow::initAllSettings()
{
    m_login =  new LoginWindow;
    m_projectList = new ProjectListWindow;
    m_projectEdit = new ProjectEditWindow;

    /*LOGIN*/
    ui->stackedWidget->addWidget(m_login);
    /*PROJECT LIST*/
    ui->stackedWidget->addWidget(m_projectList);
    /*PROJECT EDIT*/
    ui->stackedWidget->addWidget(m_projectEdit);
}

void ContainerWindow::setLoginWindow()
{
    m_login->initAllSettings();
    ui->stackedWidget->setCurrentIndex(statics_definations::core::LOGIN_WINDOW_POSITION);
}

void ContainerWindow::setProjectWindow()
{
    ui->stackedWidget->setCurrentIndex(statics_definations::core::PROJECT_LIST_WINDOW);
}

void ContainerWindow::setProjectEditWindow()
{
    ui->stackedWidget->setCurrentIndex(statics_definations::core::PROJECT_EDIT_WINDOW);
}

void ContainerWindow::setShowErrorMessage(int status, QString msgStr)
{
    Q_UNUSED(status)
    QMessageBox msgBox;
    msgBox.critical(this, tr("ERROR"), msgStr);
}

