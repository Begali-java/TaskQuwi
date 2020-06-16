#ifndef COREAPIFUNCTIONS_H
#define COREAPIFUNCTIONS_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>
#include <QByteArray>
#include <QSettings>
#include <QDebug>

/*CORE STATIC VARIABLES*/
#include "core/core_static_variable_definations.h"

class CoreApiFunctions : public QObject
{
    Q_OBJECT
public:
    explicit CoreApiFunctions(QObject *parent = nullptr);
private:
    QNetworkAccessManager * manager = 0;
public slots:
    void setNetworkManagerCommand(QNetworkRequest request,QByteArray postData);
    void onFinished(QNetworkReply *reply);
    void parseRequest(QString url,QString jsonStr);
    QJsonObject getJsonObjectFromString(QString jsonStr);

signals:
    void setErrorStatusWithMsgStr(bool,QString msgStr);

};

#endif // COREAPIFUNCTIONS_H
