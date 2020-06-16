#ifndef CORE_STRUCTURE_DEFINATIONS_H
#define CORE_STRUCTURE_DEFINATIONS_H
#include <QString>
#include <QByteArray>
#include <QMetaType>
namespace structure_definations { namespace core {
typedef struct
{
    QString projectName;
    int activeStatus;
    QString logoUrl;
    QByteArray imageArray;
    qint64 id;
    qint64 spent_time_week;
    qint64 spent_time_month;
    qint64 spent_time_all;

} ProjectsList;
}}
Q_DECLARE_METATYPE(structure_definations::core::ProjectsList);
#endif // CORE_STRUCTURE_DEFINATIONS_H
