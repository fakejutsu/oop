#ifndef MODELCREATOR_H
#define MODELCREATOR_H

#include "modelobject.h"
class ModelCreator
{
public:
    ModelCreator();

    virtual std::shared_ptr<ModelObject> createModel() = 0;
};

#endif // MODELCREATOR_H
