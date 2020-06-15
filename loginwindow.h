#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

/*CORE FUNCTIONS*/
#include "core/core_api_application.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
public slots:
    void initAllSettings();
private slots:
    void on_loginPushbutton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
