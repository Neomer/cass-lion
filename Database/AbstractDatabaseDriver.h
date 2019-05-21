//
// Created by kir on 21.05.19.
//

#ifndef CASS_LION_ABSTRACTDATABASEDRIVER_H
#define CASS_LION_ABSTRACTDATABASEDRIVER_H

class AbstractDatabaseDriver {
public:
    AbstractDatabaseDriver() = default;
    virtual ~AbstractDatabaseDriver() = default;

    virtual void open() = 0;
    virtual void close() = 0;
};


#endif //CASS_LION_ABSTRACTDATABASEDRIVER_H
