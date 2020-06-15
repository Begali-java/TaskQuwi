#ifndef PROJECTLISTWINDOW_H
#define PROJECTLISTWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectListWindow;
}

class ProjectListWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectListWindow(QWidget *parent = nullptr);
    ~ProjectListWindow();

private:
    Ui::ProjectListWindow *ui;
};

#endif // PROJECTLISTWINDOW_H
