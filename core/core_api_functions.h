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
#include <QDebug>

class CoreApiFunctions : public QObject
{
    Q_OBJECT
public:
    explicit CoreApiFunctions(QObject *parent = nullptr);
private:
    QNetworkAccessManager * manager = 0;
public slots:
    void setNetworkManagerCommand(QNetworkRequest request,QUrlQuery params);
    void onFinished(QNetworkReply *reply);

signals:

};

#endif // COREAPIFUNCTIONS_H
