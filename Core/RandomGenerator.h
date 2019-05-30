//
// Created by kir on 30.05.19.
//

#ifndef CASS_LION_RANDOMGENERATOR_H
#define CASS_LION_RANDOMGENERATOR_H

#include "AbstractRandomGenerator.h"

class RandomGenerator : public AbstractRandomGenerator
{
public:
    RandomGenerator();

    virtual ~RandomGenerator();

    int nextInt() const override;

    int nextInt(int min, int max) const override;

    double nextDouble() const override;

};


#endif //CASS_LION_RANDOMGENERATOR_H
