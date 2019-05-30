//
// Created by kir on 22.05.19.
//

#include "QueryResultCallback.h"

QueryResultCallback::QueryResultCallback() :
        AsyncCallback()
{

}

QueryResultCallback::~QueryResultCallback()
{

}

void QueryResultCallback::onComplete(const std::shared_ptr<AbstractDatabaseQuery> &result)
{

}

void QueryResultCallback::onError(const Exception &exception)
{

}
