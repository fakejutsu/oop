#ifndef VISIBLESCENEOBJECT_H
#define VISIBLESCENEOBJECT_H

#include "sceneobject.h"

class VisibleSceneObject : public SceneObject
{
public:
    VisibleSceneObject();

    virtual bool isComposite() const noexcept override;
    virtual bool isVisible() const noexcept override;
};

#endif // VISIBLESCENEOBJECT_H
