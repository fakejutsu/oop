#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include "visiblesceneobject.h"
#include "ModelAbstraction.h"
#include <string>

class ModelObjectEntityAdapter;

class ModelObject : public VisibleSceneObject
{
public:
    virtual ~ModelObject() = 0;
    virtual void accept(VisitorBase &v) override;
    virtual std::string objectName() override;
    virtual std::shared_ptr<ModelAbstraction> getEntity() = 0;
};

#endif // MODELOBJECT_H
