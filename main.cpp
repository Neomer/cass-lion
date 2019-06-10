#include <iostream>
#include <gtkmm/application.h>
#include "Windows/MainWindow.h"
#include "ApplicationContext.h"
#include "Database/PostgreSql/PostgreSqlDriver.h"
#include "Database/PostgreSql/PostgreSqlDatabasePatcher.h"
#include "Database/PostgreSql/PostgreSqlDatabaseConfiguration.h"
#include "Database/Exceptions/DatabaseConnectionRefusedException.h"
#include "Core/Uuid.h"

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);

    const char *cfgFilename = "config/context.xml";
    ApplicationContext::getInstance().load(cfgFilename);

    PostgreSqlDatabaseConfiguration rootCfg;
    rootCfg.setHost("localhost");
    rootCfg.setPort("5432");
    rootCfg.setUsername("postgres");
    rootCfg.setPassword("123456");
    rootCfg.setDbname("Cass");

    PostgreSqlDriver drv(&rootCfg);
    try
    {
        auto connection = drv.open();

        PostgreSqlDatabasePatcher patcher(connection);
        patcher.patch();
    }
    catch (DatabaseConnectionRefusedException &e)
    {
        ApplicationContext::getInstance().logger()->error(std::string("Не удалось подключться к базе! ") + e.what());
        return -1;
    }

    MainWindow mainWindow;

    auto result = app->run(mainWindow);

    ApplicationContext::getInstance().unload(cfgFilename);

    return result;
}