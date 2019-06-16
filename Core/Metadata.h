//
// Created by kir on 15.06.19.
//

#ifndef CASS_LION_METADATA_H
#define CASS_LION_METADATA_H

#include "Uuid.h"

class Metadata
{
public:
    Metadata();

    explicit Metadata(const Uuid &typeUid);

    virtual ~Metadata();

    const Uuid &getTypeUid() const;

private:
    Uuid _typeUid;
};


#endif //CASS_LION_METADATA_H
