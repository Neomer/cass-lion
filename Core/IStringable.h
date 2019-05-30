//
// Created by kir on 30.05.19.
//

#ifndef CASS_LION_ISTRINGABLE_H
#define CASS_LION_ISTRINGABLE_H

#include <string_view>

class IStringable
{
public:

    virtual std::string toString() const = 0;

    virtual void toString(std::string &buffer) const = 0;

};

#endif //CASS_LION_ISTRINGABLE_H
