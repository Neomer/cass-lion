//
// Created by kir on 22.05.19.
//

#include "Exception.h"

Exception::Exception(std::string_view message) :
    _message{ message }
{

}

Exception::Exception() :
    _message{ }
{

}

Exception::~Exception()
{

}

const char *Exception::what() const throw()
{
    return _message.c_str();
}
