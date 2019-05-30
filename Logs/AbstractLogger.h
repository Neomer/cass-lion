//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_ABSTRACTLOGGER_H
#define CASS_LION_ABSTRACTLOGGER_H

#include <string_view>

class AbstractLogger
{
public:

    virtual void info(std::string_view message) const = 0;

    virtual void debug(std::string_view message) const = 0;

    virtual void warning(std::string_view message) const = 0;

    virtual void error(std::string_view message) const = 0;

    virtual void trace(std::string_view message) const = 0;

};


#endif //CASS_LION_ABSTRACTLOGGER_H
