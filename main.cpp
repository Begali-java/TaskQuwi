#include "containerwindow.h"

#include <QApplication>

/*CORE FUNCTIONS*/
#include "core/core_api_application.h"
#include "core/core_structure_definations.h"

int main(int argc, char *argv[])
{
    core::qt::quwi::Application aApp(argc, argv);
    qRegisterMetaType< structure_definations::core::ProjectsList >();
    ContainerWindow w;
    w.initAllSettings();
    w.setLoginWindow();
    w.show();
    return aApp.exec();
}
