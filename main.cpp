#include "containerwindow.h"

#include <QApplication>

/*CORE FUNCTIONS*/
#include "core/core_api_application.h"

int main(int argc, char *argv[])
{
    core::qt::quwi::Application aApp(argc, argv);
    ContainerWindow w;
    w.initAllSettings();
    w.setLoginWindow();
    w.show();
    return aApp.exec();
}
