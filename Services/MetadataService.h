//
// Created by kir on 15.06.19.
//

#ifndef CASS_LION_METADATASERVICE_H
#define CASS_LION_METADATASERVICE_H

#include <vector>
#include <memory>
#include "AbstractBackgroundService.h"
#include "../Core/Metadata.h"

class MetadataService : public AbstractBackgroundService
{
public:
    MetadataService();

    ~MetadataService() override;

    const Metadata *findMetadata(const Uuid &typeUid) const;

    const Metadata *findMetadata(std::string_view className) const;

protected:
    void initialize() override;

private:
    std::vector<std::unique_ptr<Metadata>> _metadataList;
};


#endif //CASS_LION_METADATASERVICE_H
