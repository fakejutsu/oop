//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_MODELOBJECTCREATOR_H
#define MODELVIEWER_MODELOBJECTCREATOR_H

#include "modelobject.h"

class ModelObjectCreator {
public:
    virtual std::shared_ptr<ModelObject> createModelObject(std::shared_ptr<ModelAbstraction>) = 0;
    virtual ~ModelObjectCreator() = default;
};


#endif //MODELVIEWER_MODELOBJECTCREATOR_H
