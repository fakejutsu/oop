//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_SOURCECREATOR_H
#define MODELVIEWER_SOURCECREATOR_H

#include <memory>
#include "AbsCorrectModelSource.h"
#include "FileReader.h"

class SourceCreator {
public:
    SourceCreator() = default;
    virtual ~SourceCreator() = default;
    virtual std::shared_ptr<AbsCarcassModelSource> create(std::shared_ptr<FileReader> reader) = 0;
};

#endif //MODELVIEWER_SOURCECREATOR_H
