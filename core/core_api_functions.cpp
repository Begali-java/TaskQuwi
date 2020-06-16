#include "core_api_functions.h"

CoreApiFunctions::CoreApiFunctions(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onFinished(QNetworkReply *)));
}

void CoreApiFunctions::setNetworkManagerCommand(QNetworkRequest request, QByteArray postData)
{
    if(manager != 0){
        QNetworkReply *replySending = manager->post(request,postData);
        if(replySending->error() != QNetworkReply::NoError){
            /*ERROR*/
            qDebug()<<"ERROR";
            emit setErrorStatusWithMsgStr(false,tr("SERVER ERROR"));
        }
    }
}

void CoreApiFunctions::onFinished(QNetworkReply *reply)
{
    QString strReply = (QString)reply->readAll();
    parseRequest(reply->url().toString(),strReply);
    Q_UNUSED(reply)
}

void CoreApiFunctions::parseRequest(QString url, QString jsonStr)
{
    if(url.trimmed().length() > 0){
        url = url.remove(statics_definations::core::BASE_URL,Qt::CaseInsensitive);
        url = url.toLower();
        if(QString::compare(url,"auth/login",Qt::CaseInsensitive) == 0){
            QJsonObject jsonObj = getJsonObjectFromString(jsonStr);
            if(!jsonObj.isEmpty()){
                if(jsonObj.contains("token")){
                    QString m_token = jsonObj["token"].toString();
                    QSettings m_settings("config.ini",QSettings::IniFormat);
                    m_settings.beginGroup("SETTINGS");
                    m_settings.setValue("token",m_token);
                    m_settings.endGroup();
                    qDebug()<<"LOGIN SUCCESS";
                    emit setErrorStatusWithMsgStr(true,tr("SUCCESS"));
                }else if(jsonObj.contains("first_errors")){
                    QJsonObject subJsonObj = jsonObj["first_errors"].toObject();
                    if(subJsonObj.isEmpty()){
                        emit setErrorStatusWithMsgStr(false,tr("ERROR"));
                        return;
                    }

                    QStringList m_keys =subJsonObj.keys();
                    QString errorMsg = "";
                    for(int i = 0; i < m_keys.length(); i++){
                        errorMsg.append(subJsonObj[m_keys.at(i)].toString());
                    }
                    emit setErrorStatusWithMsgStr(false,errorMsg);
                }
            }
        }
    }
}

QJsonObject CoreApiFunctions::getJsonObjectFromString(QString jsonStr)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(!doc.isNull()){
        if(doc.isObject()){
            obj = doc.object();
        }
        else{
            qDebug() << "NOT OBJECT FOUND ERROR" << endl;
        }
    }
    else{
        qDebug() <<"INVALID JSON ERROR";
    }
    return obj;
}
