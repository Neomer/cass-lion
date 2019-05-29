//
// Created by kir on 29.05.19.
//

#include <iostream>
#include "ConsoleLogger.h"

ConsoleLogger::ConsoleLogger()
{

}

ConsoleLogger::~ConsoleLogger()
{

}

void ConsoleLogger::info(std::string_view message) const
{
    std::cout << "[INFO] " << message << std::endl;
}

void ConsoleLogger::debug(std::string_view message) const
{
    std::cout << "[DEBUG] " << message << std::endl;
}

void ConsoleLogger::warning(std::string_view message) const
{
    std::cout << "[WARNING] " << message << std::endl;
}

void ConsoleLogger::error(std::string_view message) const
{
    std::cout << "[ERROR] " << message << std::endl;
}

void ConsoleLogger::trace(std::string_view message) const
{
    std::cout << "[TRACE] " << message << std::endl;
}
