//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEQUERY_H
#define CASS_LION_ABSTRACTDATABASEQUERY_H


class AbstractDatabaseQuery
{
public:
    AbstractDatabaseQuery();

    virtual ~AbstractDatabaseQuery();

    virtual bool first() = 0;

    virtual bool eof() const = 0;

    virtual bool valid() const noexcept = 0;

    virtual void close() noexcept = 0;

};


#endif //CASS_LION_ABSTRACTDATABASEQUERY_H
