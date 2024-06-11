//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_SOURCEFACTORY_H
#define MODELVIEWER_SOURCEFACTORY_H

#include "SourceCreator.h"
#include "FileReader.h"

template <typename T>
class SourceFactory : public SourceCreator {
public:

    virtual std::shared_ptr<T> createConrecte(std::shared_ptr<FileReader> reader)
    {
        return std::make_shared<T>(reader);
    }

    virtual std::shared_ptr<AbsCarcassModelSource> create(std::shared_ptr<FileReader> reader) override
    {
        return std::make_shared<T>(reader);
    }
};


#endif //MODELVIEWER_SOURCEFACTORY_H
