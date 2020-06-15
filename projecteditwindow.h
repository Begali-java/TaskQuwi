#ifndef PROJECTEDITWINDOW_H
#define PROJECTEDITWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectEditWindow;
}

class ProjectEditWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectEditWindow(QWidget *parent = nullptr);
    ~ProjectEditWindow();

private:
    Ui::ProjectEditWindow *ui;
};

#endif // PROJECTEDITWINDOW_H
