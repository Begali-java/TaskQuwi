#include "core_api_application.h"
using namespace core::qt::quwi;


Application::Application(int& a_argc, char** a_argv)
    :
      ::QApplication (a_argc,a_argv)
{


}

Application::~Application()
{
    ::QCoreApplication::processEvents();
}

void Application::loginGuiThreadOnly(QString login, QString password)
{
    if(login.trimmed().length() >0 && password.trimmed().length() && password.trimmed().length() >0){
        /*CHECK LOGIN FROM API*/
        QNetworkRequest request(QUrl(statics_definations::core::BASE_URL+"auth/login"));
        request.setRawHeader("Content-Type", "application/json");
        request.setRawHeader("Client-Timezone-Offset", "60");
        request.setRawHeader("Client-Language", "ru-RU");
        request.setRawHeader("Client-Company", "udimi");
        request.setRawHeader("Client-Device", "desktop");
        QJsonObject obj;
        obj["email"] = "vitaliibondtest@gmail.com";
        obj["password"] = "vitaliibondtest";

       m_apifunctions.setNetworkManagerCommand(request,QJsonDocument(obj).toJson());


        emit loginSuccessSignal();
    }else{
        emit loginErorSignal(statics_definations::core::ERROR_LOGIN_LOGIN_AND_PASSWORD_NOT_BE_EMPITY,tr("Empity login or password"));
    }

}

QString Application::getLastEmail()
{
    return m_settingsClass.getLastEmail();
}

void Application::showMessageGuiThreadOnly(int msgStatus, QString msgStr)
{
    emit showMessageSiganl(msgStatus,msgStr);
}

QString Application::getToken()
{
    return m_settingsClass.getToken();
}


