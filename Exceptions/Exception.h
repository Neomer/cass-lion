//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_EXCEPTION_H
#define CASS_LION_EXCEPTION_H

#include <exception>
#include <string_view>
#include <string>

class Exception : public std::exception
{
public:
    explicit Exception();
    explicit Exception(std::string_view message);
    virtual ~Exception() throw ();

    virtual const char* what() const throw ();

protected:
    std::string _message;
};


#endif //CASS_LION_EXCEPTION_H
