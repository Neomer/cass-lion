//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_QUERYRESULTCALLBACK_H
#define CASS_LION_QUERYRESULTCALLBACK_H

#include <memory>
#include "../Async/AsyncCallback.h"
#include "AbstractDatabaseQuery.h"

class QueryResultCallback : public AsyncCallback<std::shared_ptr<AbstractDatabaseQuery>>
{
public:
    QueryResultCallback();

    QueryResultCallback(std::shared_ptr<AbstractDatabaseQuery> result);

    ~QueryResultCallback() override;
};


#endif //CASS_LION_QUERYRESULTCALLBACK_H
