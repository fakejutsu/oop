#ifndef CAMERAOBJECT_H
#define CAMERAOBJECT_H

#include "invisiblesceneobject.h"


class CameraObject : public InvisibleSceneObject
{
public:
    CameraObject();
    virtual ~CameraObject() = default;
};

#endif // CAMERAOBJECT_H
