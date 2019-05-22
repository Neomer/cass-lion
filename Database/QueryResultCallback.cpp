//
// Created by kir on 22.05.19.
//

#include "QueryResultCallback.h"

QueryResultCallback::QueryResultCallback() :
        AsyncCallback()
{

}

QueryResultCallback::QueryResultCallback(std::shared_ptr<AbstractDatabaseQuery> result) :
        AsyncCallback(result)
{

}

QueryResultCallback::~QueryResultCallback()
{

}
