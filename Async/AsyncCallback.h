//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ASYNCCALLBACK_H
#define CASS_LION_ASYNCCALLBACK_H

#include "../Exceptions/Exception.h"

template<typename TResult, typename TException = Exception>
class AsyncCallback
{
public:
    AsyncCallback()
    {

    }

    virtual ~AsyncCallback()
    {

    }

    virtual void onComplete(const TResult &result) = 0;

    virtual void onError(const TException &exception) = 0;

};


#endif //CASS_LION_ASYNCCALLBACK_H
