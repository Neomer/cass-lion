//
// Created by kir on 30.05.19.
//

#include <cstdlib>
#include <ctime>
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator()
{
    srand(std::time(nullptr));
}

RandomGenerator::~RandomGenerator()
{

}

int RandomGenerator::nextInt() const
{
    return rand();
}

int RandomGenerator::nextInt(int min, int max) const
{
    return (rand() + min) % max;
}

double RandomGenerator::nextDouble() const
{
    return rand() / RAND_MAX;
}

