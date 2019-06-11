//
// Created by kir on 10.06.19.
//

#ifndef CASS_LION_DATETIME_H
#define CASS_LION_DATETIME_H

#include "IStringable.h"
#include "TimeSpan.h"

class DateTime : public IStringable
{
public:
    DateTime();

    DateTime(int64_t timestamp);

    ~DateTime();

    DateTime &add(const TimeSpan &timeSpan);

    DateTime &addDays(int32_t days);

    DateTime &addHours(int32_t hours);

    DateTime &addMinutes(int32_t minutes);

    DateTime &addSeconds(int64_t seconds);

    std::string toString() const override;

    void toString(std::string &buffer) const override;

private:
    int64_t _timestamp;
};


#endif //CASS_LION_DATETIME_H
