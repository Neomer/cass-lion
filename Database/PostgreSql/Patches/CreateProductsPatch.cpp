//
// Created by kir on 30.05.19.
//

#include "CreateProductsPatch.h"

CreateProductsPatch::CreateProductsPatch()
{

}

CreateProductsPatch::~CreateProductsPatch()
{

}

void CreateProductsPatch::execute(std::shared_ptr<AbstractDatabaseConnection> &connection)
{
    createProductTypeTable(connection);
    createProductTable(connection);
}

uint32_t CreateProductsPatch::version() const
{
    return 1;
}

/**
 * Создает таблицу продуктов.
 * @param connection
 */
void CreateProductsPatch::createProductTable(std::shared_ptr<AbstractDatabaseConnection> &connection)
{
    connection->execute(R"(CREATE TABLE public."Product"(
                            "Uid" uuid NOT NULL,
                            "Type" uuid,
                            "Name" character varying(512),
                            "ShortDescription" character varying(512),
                            "Description" TEXT,
                            PRIMARY KEY ("Uid")) WITH (OIDS = FALSE);)");
    connection->execute(R"(ALTER TABLE public."Product" OWNER to cass_admin;)");

}

/**
 * Создает таблицу типов продуктов.
 * @param connection
 */
void CreateProductsPatch::createProductTypeTable(std::shared_ptr<AbstractDatabaseConnection> &connection)
{
    // Create table
    connection->execute(R"(CREATE TABLE public."ProductType" (
                        "Uid" uuid NOT NULL,
                        "Name" character varying(128) NOT NULL,
                        PRIMARY KEY ("Uid")) WITH (OIDS = FALSE);)");
    connection->execute(R"(ALTER TABLE public."ProductType" OWNER to cass_admin;)");

    // Create onDelete trigger
    connection->execute(R"(CREATE FUNCTION public."RemoveProductsOnDeleteProductType"() RETURNS trigger LANGUAGE 'plpgsql' NOT LEAKPROOF
                        AS $BODY$begin
                            update public."Product" set "Type"=NULL where "Type"=OLD."Uid";
                            return OLD;
                        end;$BODY$;)");
    connection->execute(R"(ALTER FUNCTION public."RemoveProductsOnDeleteProductType"() OWNER TO cass_admin;)");
    connection->execute(R"(CREATE TRIGGER "RemoveProductsOnDelete" AFTER DELETE ON public."ProductType" FOR EACH ROW
                        EXECUTE PROCEDURE public."RemoveProductsOnDeleteProductType"();)");

    // Create onUpdate trigger
    connection->execute(R"(CREATE FUNCTION public."UpdateProductsOnUpdateProductTypeUid"() RETURNS trigger LANGUAGE 'plpgsql' NOT LEAKPROOF
                        AS $BODY$begin
                            update public."Product" set "Type"=NEW."Uid" where "Type"=OLD."Uid";
                            return NEW;
                        end;$BODY$;)");
    connection->execute(R"(ALTER FUNCTION public."UpdateProductsOnUpdateProductTypeUid"() OWNER TO cass_admin;)");
    connection->execute(R"(CREATE TRIGGER "UpdateProductsOnUpdateUid" AFTER UPDATE OF "Uid" ON public."ProductType" FOR EACH ROW
                        EXECUTE PROCEDURE public."UpdateProductsOnUpdateProductTypeUid"();)");
}
