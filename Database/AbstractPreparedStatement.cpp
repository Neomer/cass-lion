//
// Created by kir on 16.06.19.
//

#include "AbstractPreparedStatement.h"

AbstractPreparedStatement::AbstractPreparedStatement(std::string_view sql) :
    _sql{ sql }
{

}

const std::string_view AbstractPreparedStatement::getSqlTemplate() const
{
    return _sql;
}
