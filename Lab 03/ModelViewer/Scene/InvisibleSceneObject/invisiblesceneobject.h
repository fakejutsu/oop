#ifndef INVISIBLESCENEOBJECT_H
#define INVISIBLESCENEOBJECT_H

#include "sceneobject.h"
#include "visitorbase.h"

class InvisibleSceneObject : public SceneObject
{
public:
    InvisibleSceneObject();
    virtual ~InvisibleSceneObject() = default;
    bool isComposite() override;
    bool isVisible() const noexcept override;
};

#endif // INVISIBLESCENEOBJECT_H
