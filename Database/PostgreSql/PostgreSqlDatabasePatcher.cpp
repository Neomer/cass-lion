//
// Created by kir on 29.05.19.
//

#include <algorithm>
#include "PostgreSqlDatabasePatcher.h"
#include "../Exceptions/QueryExecuteException.h"
#include "../../ApplicationContext.h"

#include "Patches/InitialPatch.h"
#include "Patches/CreateProductsPatch.h"

PostgreSqlDatabasePatcher::PostgreSqlDatabasePatcher(AbstractDatabaseConnectionPool &abstractDatabaseConnectionPool) :
        AbstractDatabasePatcher(abstractDatabaseConnectionPool)
{

}


PostgreSqlDatabasePatcher::PostgreSqlDatabasePatcher(std::shared_ptr<AbstractDatabaseConnection> &connection) :
        AbstractDatabasePatcher(connection)
{

}

PostgreSqlDatabasePatcher::~PostgreSqlDatabasePatcher() = default;

void PostgreSqlDatabasePatcher::patch()
{
    ApplicationContext::getInstance().logger()->trace("PostgreSqlDatabasePatcher::patch()");
    ApplicationContext::getInstance().logger()->debug("Проверка необходимости преобразования базы данных");

    // Проверяем, что создана таблица DatabaseInformation, иначе база только что создана
    auto query = getConnection()->execute("SELECT EXISTS (\n"
                             "   SELECT 1\n"
                             "   FROM   information_schema.tables \n"
                             "   WHERE  table_schema = 'public'\n"
                             "   AND    table_name = 'DatabaseInformation');");

    int startPatch;
    if (!query->valid() || !query->value(0)->toBool())
    {
        ApplicationContext::getInstance().logger()->debug("Таблица DatabaseInformation не найдена. База данных чистая.");
        startPatch = -1;
    }
    else
    {
        query->close();
        query = getConnection()->execute(R"(SELECT "Version" FROM public."DatabaseInformation";)");

        if (!query->valid() && !query->first())
        {
            ApplicationContext::getInstance().logger()->debug("Не удалось узнать установленную версию базы данных.");
            startPatch = -1;
        }
        else
        {
            startPatch = query->value(0)->toInt32();
        }
    }
    query->close();

    auto patches = patchList();
    auto currentVersion = patches.rbegin()->get()->version();
    ApplicationContext::getInstance().logger()->debug("Текущая версия базы данных: " + std::to_string(startPatch) + " Актуальная версия базы данных: " + std::to_string(currentVersion));

    if (startPatch == -1 || static_cast<uint32_t >(startPatch) < currentVersion)
    {
        auto connection = getConnection();
        for (auto patch : patches)
        {
            if (startPatch == -1 || static_cast<uint32_t >(startPatch) < patch->version())
            {
                ApplicationContext::getInstance().logger()->debug(std::string("Применяется патч: ") + std::to_string(patch->version()));
                connection->beginTransaction();
                try
                {
                    patch->execute(getConnection());
                    connection->execute(std::string(R"(UPDATE public."DatabaseInformation" SET "Version"=)") + std::to_string(patch->version()) + ";");
                    connection->commitTransaction();
                }
                catch (QueryExecuteException &e)
                {
                    ApplicationContext::getInstance().logger()->error("Не удалось применть патч #" + std::to_string(patch->version()) + "! Сообщение: " + e.what());
                    return;
                }
            }
        }
    }
    else
    {
        ApplicationContext::getInstance().logger()->debug("База данных находится в актуальном состоянии, обновление не требуется.");
    }
}

const std::vector<std::shared_ptr<AbstractDatabasePatch>> PostgreSqlDatabasePatcher::patchList() const noexcept
{
    // Сюда все патчи
    auto vector = std::vector<std::shared_ptr<AbstractDatabasePatch>> {
        std::shared_ptr<AbstractDatabasePatch>(new InitialPatch()),
        std::shared_ptr<AbstractDatabasePatch>(new CreateProductsPatch()),
    };

    std::sort(vector.begin(), vector.end(),
            [](const std::shared_ptr<AbstractDatabasePatch> &item1, const std::shared_ptr<AbstractDatabasePatch> &item2)
            {
                return item1->version() < item2->version();
            });
    return vector;
}
