#ifndef PROJECTCUSTOMITEM_H
#define PROJECTCUSTOMITEM_H

#include <QWidget>

namespace Ui {
class ProjectCustomItem;
}

class ProjectCustomItem : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectCustomItem(QWidget *parent = nullptr);
    ~ProjectCustomItem();

private:
    Ui::ProjectCustomItem *ui;
};

#endif // PROJECTCUSTOMITEM_H
