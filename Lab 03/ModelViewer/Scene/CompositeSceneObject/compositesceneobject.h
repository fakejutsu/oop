#ifndef COMPOSITESCENEOBJECT_H
#define COMPOSITESCENEOBJECT_H

#include "sceneobject.h"
class CompositeSceneObject : public SceneObject
{
public:
    CompositeSceneObject();
    virtual ~CompositeSceneObject() = default;

    virtual bool isComposite() const noexcept override;
    virtual bool isVisible() const noexcept override;

};

#endif // COMPOSITESCENEOBJECT_H
