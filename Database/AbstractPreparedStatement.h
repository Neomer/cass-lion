//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_ABSTRACTPREPAREDSTATEMENT_H
#define CASS_LION_ABSTRACTPREPAREDSTATEMENT_H

#include <inttypes.h>
#include <string_view>
#include <string>

class AbstractPreparedStatement
{
public:
    explicit AbstractPreparedStatement(std::string_view sql);

    virtual void bind(uint16_t index, std::string_view value) = 0;

    virtual const std::string_view getPreparedStatement() const = 0;

    const std::string_view getSqlTemplate() const;

private:
    std::string _sql;
};


#endif //CASS_LION_ABSTRACTPREPAREDSTATEMENT_H
