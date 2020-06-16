#ifndef PROJECTLISTWINDOW_H
#define PROJECTLISTWINDOW_H

#include <QWidget>
#include <QString>
#include <QSettings>

#include <QDebug>

namespace Ui {
class ProjectListWindow;
}

class ProjectListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectListWindow(QWidget *parent = nullptr);
    ~ProjectListWindow();

private slots:
    void on_projectsBtn_clicked();

    void on_logoutButton_clicked();

private:
    Ui::ProjectListWindow *ui;
};

#endif // PROJECTLISTWINDOW_H
