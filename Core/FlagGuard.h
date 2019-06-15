//
// Created by kir on 13.06.19.
//

#ifndef CASS_LION_FLAGGUARD_H
#define CASS_LION_FLAGGUARD_H

#include <atomic>

/**
 * Класс для потокобезопасной установки флага.
 * При инициализации устанавливает флаг в TRUE, при уничтожении устанавливает в FALSE.
 */
class FlagGuard
{
public:
    explicit FlagGuard(std::atomic_bool &flag);

    ~FlagGuard();

private:
    std::atomic_bool &_flag;
};


#endif //CASS_LION_FLAGGUARD_H
