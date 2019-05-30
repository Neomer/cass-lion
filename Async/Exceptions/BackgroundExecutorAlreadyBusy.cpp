//
// Created by kir on 22.05.19.
//

#include "BackgroundExecutorAlreadyBusy.h"

BackgroundExecutorAlreadyBusy::BackgroundExecutorAlreadyBusy() :
        Exception()
{

}

BackgroundExecutorAlreadyBusy::BackgroundExecutorAlreadyBusy(std::string_view message) :
        Exception(message)
{

}

BackgroundExecutorAlreadyBusy::~BackgroundExecutorAlreadyBusy()
{

}
