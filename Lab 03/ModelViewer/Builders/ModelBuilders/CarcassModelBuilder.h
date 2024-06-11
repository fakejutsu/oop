//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSMODELBUILDER_H
#define MODELVIEWER_CARCASSMODELBUILDER_H

#include "CarcassModelEntity.h"
#include "AbsCorrectModelSource.h"

#include <memory>

class CarcassModelBuilder {
public:
    virtual ~CarcassModelBuilder();
    virtual void buildEdges() = 0;
    virtual void buildVertex() = 0;
    virtual std::shared_ptr<CarcassModelEntity> getModel() = 0;
};


#endif //MODELVIEWER_CARCASSMODELBUILDER_H
