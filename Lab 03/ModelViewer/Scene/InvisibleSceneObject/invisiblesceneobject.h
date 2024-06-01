#ifndef INVISIBLESCENEOBJECT_H
#define INVISIBLESCENEOBJECT_H

#include "sceneobject.h"


class InvisibleSceneObject : public SceneObject
{
public:
    InvisibleSceneObject();
    virtual ~InvisibleSceneObject() = default;
    virtual bool isComposite() const noexcept override;
    virtual bool isVisible() const noexcept override;
};

#endif // INVISIBLESCENEOBJECT_H
