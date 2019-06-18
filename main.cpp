#include <iostream>
#include <utility>
#include <gtkmm/application.h>
#include "Windows/MainWindow.h"
#include "ApplicationContext.h"
#include "Database/PostgreSql/PostgreSqlDriver.h"
#include "Database/PostgreSql/PostgreSqlDatabasePatcher.h"
#include "Database/PostgreSql/PostgreSqlDatabaseConfiguration.h"
#include "Database/Exceptions/DatabaseConnectionRefusedException.h"
#include "Core/Uuid.h"

#include "Model/EntityMetadata.h"
#include "Model/AbstractEntityManager.h"
#include "Model/ProductType.h"

using namespace std::string_literals;

int main(int argc, char **argv) {
    auto app = Gtk::Application::create(argc, argv);

    const char *cfgFilename = "config/context.xml";
    ApplicationContext::getInstance().load(cfgFilename);

    std::unique_ptr<AbstractDatabaseConfiguration> rootCfg(new PostgreSqlDatabaseConfiguration());
    ((PostgreSqlDatabaseConfiguration *)rootCfg.get())->setHost("localhost");
    ((PostgreSqlDatabaseConfiguration *)rootCfg.get())->setPort("5432");
    ((PostgreSqlDatabaseConfiguration *)rootCfg.get())->setUsername("postgres");
    ((PostgreSqlDatabaseConfiguration *)rootCfg.get())->setPassword("123456");
    ((PostgreSqlDatabaseConfiguration *)rootCfg.get())->setDbname("Cass");

    PostgreSqlDriver drv(std::move(rootCfg));
    try
    {
        auto connection = drv.open();

        PostgreSqlDatabasePatcher patcher(connection);
        patcher.patch();
    }
    catch (DatabaseConnectionRefusedException &e)
    {
        ApplicationContext::getInstance().logger()->error(std::string("Не удалось подключиться к базе! ") + e.what());
        return -1;
    }

    auto metadata = dynamic_cast<const EntityMetadata *>(ApplicationContext::getInstance().getMetadataService()->findMetadata(ProductType::TypeUid()));
    auto entityList = metadata->getManager()->findAll();
    if (!entityList.empty()) {
        for (auto &entity : entityList) {
            auto productType = dynamic_cast<ProductType *>(entity.get());
            ApplicationContext::getInstance().logger()->error("Тип продукта: ["s + productType->getUid().toString() + "] " + productType->getName());
        }
    } else {
        ApplicationContext::getInstance().logger()->error("Записей не найдено!");
    }


    MainWindow mainWindow;

    auto result = app->run(mainWindow);

    ApplicationContext::getInstance().unload(cfgFilename);

    return result;
}