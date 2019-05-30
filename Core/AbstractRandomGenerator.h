//
// Created by kir on 30.05.19.
//

#ifndef CASS_LION_ABSTRACTRANDOMGENERATOR_H
#define CASS_LION_ABSTRACTRANDOMGENERATOR_H


class AbstractRandomGenerator
{
public:
    virtual int nextInt() const = 0;

    virtual int nextInt(int min, int max) const = 0;

    virtual double nextDouble() const = 0;
};


#endif //CASS_LION_ABSTRACTRANDOMGENERATOR_H
