//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_CARCASSMODELCREATOR_H
#define MODELVIEWER_CARCASSMODELCREATOR_H

#include "CarcassModelEntity.h"
#include <memory>

class CarcassModelCreator {
public:
    virtual ~CarcassModelCreator() = default;
    virtual std::shared_ptr<CarcassModelEntity> create() = 0;
};


#endif //MODELVIEWER_CARCASSMODELCREATOR_H
