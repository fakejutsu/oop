#ifndef COMPOSITESCENEOBJECT_H
#define COMPOSITESCENEOBJECT_H

#include "sceneobject.h"
#include "visitorbase.h"

class CompositeSceneObject : public SceneObject
{
public:
    CompositeSceneObject();
    virtual ~CompositeSceneObject() = default;

    virtual bool isComposite() override;
    virtual bool isVisible() const noexcept override;
};

#endif // COMPOSITESCENEOBJECT_H
