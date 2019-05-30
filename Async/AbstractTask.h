//
// Created by kir on 22.05.19.
//

#ifndef CASS_LION_ABSTRACTTASK_H
#define CASS_LION_ABSTRACTTASK_H


class AbstractTask
{
public:
    AbstractTask();

    virtual ~AbstractTask();

    virtual void execute() = 0;
};


#endif //CASS_LION_ABSTRACTTASK_H
