//
// Created by kir on 15.06.19.
//

#include <algorithm>
#include "MetadataService.h"
#include "../ApplicationContext.h"
#include "../Core/ClassMetadata.h"


MetadataService::MetadataService()
{

}

MetadataService::~MetadataService()
{

}

const Metadata *MetadataService::findMetadata(const Uuid &typeUid) const
{
    const auto it = std::find_if(_metadataList.begin(), _metadataList.end(), [&](const std::unique_ptr<Metadata> &item) {
        return item->getTypeUid().equals(typeUid);
    });
    return it == _metadataList.end() ? nullptr : (*it).get();
}

const Metadata *MetadataService::findMetadata(std::string_view className) const
{
    const auto it = std::find_if(_metadataList.begin(), _metadataList.end(), [&](const std::unique_ptr<Metadata> &item) {
        auto classMetadata = dynamic_cast<ClassMetadata *>(item.get());
        if (classMetadata == nullptr) {
            return false;
        }
        return className == classMetadata->getClassName();
    });
    return it == _metadataList.end() ? nullptr : (*it).get();
}

#include "../Model/ProductType.h"

void MetadataService::initialize()
{
    ApplicationContext::getInstance().logger()->debug("Инициализация сервиса метаданных");
    _metadataList.push_back(std::move(std::unique_ptr<Metadata>(new ProductTypeMetadata())));
    ApplicationContext::getInstance().logger()->debug("Сервис метаданных успешно инициализирован. Всего метаданных: " + std::to_string(_metadataList.size()));
}

