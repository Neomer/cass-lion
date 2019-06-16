//
// Created by kir on 16.06.19.
//

#ifndef CASS_LION_CLASSMETADATA_H
#define CASS_LION_CLASSMETADATA_H

#include "Metadata.h"

class ClassMetadata : public Metadata
{
public:
    ClassMetadata();

    explicit ClassMetadata(const Uuid &typeUid);

    virtual ~ClassMetadata();

    virtual const char *getClassName() const = 0;
};


#endif //CASS_LION_CLASSMETADATA_H
