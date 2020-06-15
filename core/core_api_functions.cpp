#include "core_api_functions.h"

CoreApiFunctions::CoreApiFunctions(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onFinished(QNetworkReply *)));
}

void CoreApiFunctions::setNetworkManagerCommand(QNetworkRequest request, QUrlQuery params)
{
  if(manager != 0){
      qDebug()<<params.query().toUtf8();
     QString json =  "{\"email\": \"vitaliibondtest@gmail.com\",\"password\": \"vitaliibondtest\"}";
      manager->post(request,json.toUtf8());
  }
}

void CoreApiFunctions::onFinished(QNetworkReply *reply)
{
    qDebug()<<"RESULTAT KELDI"<<reply->url().toString();
     QString strReply = (QString)reply->readAll();
     qDebug()<<strReply;

    Q_UNUSED(reply)
}
