//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ASYNCCALLBACK_H
#define CASS_LION_ASYNCCALLBACK_H

#include <optional>

template<typename TResult>
class AsyncCallback
{
public:
    AsyncCallback() :
        _result{ std::nullopt_t }
    {

    }

    AsyncCallback(TResult result) :
        _result{ result }
    {

    }

    virtual ~AsyncCallback()
    {

    }

    std::optional<TResult> result() const
    {
        return _result;
    }

private:
    std::optional<TResult> _result;
};


#endif //CASS_LION_ASYNCCALLBACK_H
