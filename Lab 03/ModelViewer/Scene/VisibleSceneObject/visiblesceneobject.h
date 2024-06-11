#ifndef VISIBLESCENEOBJECT_H
#define VISIBLESCENEOBJECT_H

#include "sceneobject.h"
#include "visitorbase.h"

class VisibleSceneObject : public SceneObject
{
public:
    VisibleSceneObject();

    bool isComposite() override;
    bool isVisible() const noexcept override;

};

#endif // VISIBLESCENEOBJECT_H
