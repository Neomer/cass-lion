//
// Created by kir on 29.05.19.
//

#ifndef CASS_LION_CONSOLELOGGER_H
#define CASS_LION_CONSOLELOGGER_H

#include "AbstractLogger.h"

class ConsoleLogger : public AbstractLogger
{
public:
    ConsoleLogger();

    virtual ~ConsoleLogger();

    void info(std::string_view message) const override;

    void debug(std::string_view message) const override;

    void warning(std::string_view message) const override;

    void error(std::string_view message) const override;

    void trace(std::string_view message) const override;
};


#endif //CASS_LION_CONSOLELOGGER_H
