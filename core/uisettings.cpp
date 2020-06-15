#include "uisettings.h"

UISettings::UISettings(QObject *parent) : QObject(parent)
{

}

QString UISettings::getLastEmail(){
    QString m_LastSuccessMail = m_settings.value("email","").toString();
    return m_LastSuccessMail;
}

QString UISettings::getToken()
{
    QString m_token = m_settings.value("token","").toString();
    return m_token;
}
