#include "core_api_functions.h"

CoreApiFunctions::CoreApiFunctions(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onFinished(QNetworkReply *)));
}

void CoreApiFunctions::setNetworkManagerCommand(QNetworkRequest request, QByteArray postData)
{
  if(manager != 0){
      manager->post(request,postData);
  }
}

void CoreApiFunctions::onFinished(QNetworkReply *reply)
{
     QString strReply = (QString)reply->readAll();
     qDebug()<<strReply;

    Q_UNUSED(reply)
}
