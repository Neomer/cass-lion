//
// Created by kir on 22.05.19.
//

#include "PostgreSqlConnection.h"

PostgreSqlConnection::PostgreSqlConnection(PGconn *conn) :
        AbstractDatabaseConnection()
{

}

PostgreSqlConnection::~PostgreSqlConnection()
{

}
