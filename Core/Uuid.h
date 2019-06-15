//
// Created by kir on 30.05.19.
//

#ifndef CASS_LION_UUID_H
#define CASS_LION_UUID_H

#include <inttypes.h>
#include <ostream>
#include "AbstractRandomGenerator.h"
#include "IStringable.h"

class Uuid : public IStringable
{
public:
    static Uuid Empty();

    static Uuid Random(const AbstractRandomGenerator *randomGenerator = nullptr);

    ///
    /// \param data
    /// \return
    /// \throws std::invalid_argument
    static Uuid FromString(std::string_view data);

    static constexpr int Size() ;

    Uuid(const Uuid &other);

    Uuid(Uuid &&other);

    Uuid &operator =(const Uuid &other);

    Uuid &operator =(Uuid &&other);

    bool equals(const Uuid &other) const;

    bool isEmpty() const;

    std::string toString() const override;

    void toString(std::string &buffer) const override;

    friend std::ostream &operator<<(std::ostream &os, const Uuid &uuid);

private:
    Uuid();

private:
    uint32_t _bytes[4];
};


#endif //CASS_LION_UUID_H
