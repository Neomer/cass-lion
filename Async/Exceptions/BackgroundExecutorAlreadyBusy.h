//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_BACKGROUNDEXECUTORALREADYBUSY_H
#define CASS_LION_BACKGROUNDEXECUTORALREADYBUSY_H

#include "../../Exceptions/Exception.h"

class BackgroundExecutorAlreadyBusy : public Exception
{
public:
    explicit BackgroundExecutorAlreadyBusy();

    explicit BackgroundExecutorAlreadyBusy(std::string_view message);

    ~BackgroundExecutorAlreadyBusy() override;
};


#endif //CASS_LION_BACKGROUNDEXECUTORALREADYBUSY_H
