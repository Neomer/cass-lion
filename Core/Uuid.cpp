//
// Created by kir on 30.05.19.
//

#include <string.h>
#include <sstream>
#include <iomanip>
#include <regex>
#include "Uuid.h"
#include "../ApplicationContext.h"

Uuid::Uuid()
{

}

Uuid Uuid::Empty()
{
    Uuid result;
    memset(result._bytes, 0, Uuid::Size());
}

Uuid Uuid::FromString(std::string_view data)
{
    std::regex re(R"(^\s*\{?[a-fA-F0-9]{8}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{12}\}?\s*$)");
    std::cmatch m;
    if (!std::regex_match(data.data(), m, re))
    {
        throw std::invalid_argument("Неверный формат строки! Невозможно преобразовать в UUID.");
    }

    Uuid uuid;
    const char *ptr = data.data();
    while (*ptr == ' ')
    {
        ++ptr;
    }
    if (*ptr == '{')
    {
        ++ptr;
    }
    size_t end;
    uuid._bytes[0] = std::stoul(ptr, &end, 16);
    uuid._bytes[1] = std::stoul(ptr + 9, &end, 16) << 16u;
    uuid._bytes[1] |= std::stoul(ptr + 14, &end, 16);
    uuid._bytes[2] = std::stoul(ptr + 19, &end, 16) << 16u;
    char tmp[5];
    memcpy(tmp, ptr + 24, 4);
    tmp[4] = 0;
    uuid._bytes[2] |= std::stoul(tmp, &end, 16);
    uuid._bytes[3] = std::stoul(ptr + 28, &end, 16);

    return uuid;
}

constexpr int Uuid::Size()
{
    return 16;
}

Uuid Uuid::Random(const AbstractRandomGenerator *randomGenerator)
{
    if (randomGenerator == nullptr)
    {
        randomGenerator = ApplicationContext::getInstance().getDefaultRandomGenerator();
    }

    Uuid result;
    for (int i = 0; i < 4; ++i)
    {
        result._bytes[i] = static_cast<uint32_t >(randomGenerator->nextInt());
    }
    return result;
}

Uuid::Uuid(const Uuid &other)
{
    memcpy(_bytes, other._bytes, Uuid::Size());
}

Uuid::Uuid(Uuid &&other)
{
    //TODO: вероятно, можно просто присвоить адрес массива в переданном классе
    memcpy(_bytes, other._bytes, Uuid::Size());
}

Uuid &Uuid::operator=(const Uuid &other)
{
    memcpy(_bytes, other._bytes, Uuid::Size());
    return *this;
}

Uuid &Uuid::operator=(Uuid &&other)
{
    //TODO: вероятно, можно просто присвоить адрес массива в переданном классе
    memcpy(_bytes, other._bytes, Uuid::Size());
    return *this;
}

bool Uuid::equals(const Uuid &other) const
{
    return !memcmp(_bytes, other._bytes, Uuid::Size());
}

std::string Uuid::toString() const
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(8) << std::hex << _bytes[0] << '-'
           << std::setfill('0') << std::setw(4) << std::hex << (static_cast<uint32_t >(_bytes[1] & 0xffff0000u) >> 16u) << '-'
           << std::setfill('0') << std::setw(4) << std::hex << ((_bytes[1] & 0x0000ffffu)) << '-'
           << std::setfill('0') << std::setw(4) << std::hex << (static_cast<uint32_t >(_bytes[2] & 0xffff0000u) >> 16u) << '-'
           << std::setfill('0') << std::setw(4) << std::hex << ((_bytes[2] & 0x0000ffffu))
           << std::setfill('0') << std::setw(8) << std::hex << _bytes[3];
    return stream.str();
}

void Uuid::toString(std::string &buffer) const
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(8) << std::hex << _bytes[0];
    buffer = stream.str();
}

std::ostream &operator<<(std::ostream &os, const Uuid &uuid)
{
    os << uuid._bytes[0]
        << uuid._bytes[1]
        << uuid._bytes[2]
        << uuid._bytes[3];

    return os;
}

bool Uuid::isEmpty() const
{
    return _bytes[0] == 0 && _bytes[1] == 0 && _bytes[2] == 0 && _bytes[3] == 0;
}

