//
// Created by kir on 29.05.19.
//

#include "InitialPatch.h"

InitialPatch::InitialPatch()
{

}

InitialPatch::~InitialPatch()
{

}

void InitialPatch::execute(std::shared_ptr<AbstractDatabaseConnection> &connection)
{
    createAdminUser(connection);
    createDatabaseInfo(connection);
}

uint32_t InitialPatch::version() const
{
    return 0;
}

void InitialPatch::createAdminUser(std::shared_ptr<AbstractDatabaseConnection> &connection)
{
    connection->execute("CREATE USER cass_admin WITH\n"
                        "\tLOGIN\n"
                        "\tNOSUPERUSER\n"
                        "\tNOCREATEDB\n"
                        "\tCREATEROLE\n"
                        "\tINHERIT\n"
                        "\tNOREPLICATION\n"
                        "\tCONNECTION LIMIT -1\n"
                        "\tPASSWORD 'xxxxxx';");

}

void InitialPatch::createDatabaseInfo(std::shared_ptr<AbstractDatabaseConnection> &connection)
{

    connection->execute("CREATE TABLE public.\"DatabaseInformation\"\n"
                        "(\n"
                        "    \"Version\" integer NOT NULL\n"
                        ")\n"
                        "WITH (\n"
                        "    OIDS = FALSE\n"
                        ");");
    connection->execute(R"(ALTER TABLE public."DatabaseInformation" OWNER to postgres;)");
    connection->execute(R"(GRANT ALL ON TABLE public."DatabaseInformation" TO cass_admin WITH GRANT OPTION;)");
    connection->execute(R"(INSERT INTO public."DatabaseInformation" ("Version") VALUES (0);)");
}
