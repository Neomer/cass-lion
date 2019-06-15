//
// Created by kir on 13.06.19.
//

#include "FlagGuard.h"

FlagGuard::FlagGuard(std::atomic_bool &flag) :
    _flag{ flag }
{
    _flag = true;
}

FlagGuard::~FlagGuard()
{
    _flag = false;
}
