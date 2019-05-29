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
    connection->execute("CREATE USER cass_admin WITH\n"
                        "\tLOGIN\n"
                        "\tNOSUPERUSER\n"
                        "\tNOCREATEDB\n"
                        "\tCREATEROLE\n"
                        "\tINHERIT\n"
                        "\tNOREPLICATION\n"
                        "\tCONNECTION LIMIT -1\n"
                        "\tPASSWORD 'xxxxxx';");

    connection->execute("CREATE TABLE public.\"DatabaseInformation\"\n"
                        "(\n"
                        "    \"Version\" integer NOT NULL\n"
                        ")\n"
                        "WITH (\n"
                        "    OIDS = FALSE\n"
                        ");");
    connection->execute("ALTER TABLE public.\"DatabaseInformation\" OWNER to postgres;");
    connection->execute("GRANT ALL ON TABLE public.\"DatabaseInformation\" TO cass_admin WITH GRANT OPTION;");
}

uint32_t InitialPatch::version() const
{
    return 0;
}
