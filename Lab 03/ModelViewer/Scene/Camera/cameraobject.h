#ifndef CAMERAOBJECT_H
#define CAMERAOBJECT_H

#include "invisiblesceneobject.h"


class CameraObject : public InvisibleSceneObject
{
public:
    CameraObject();
    virtual ~CameraObject() = default;
    virtual std::string objectName() override;
    virtual Point3dForm transformPointToCameraView(Point4dForm point) = 0;

};

#endif // CAMERAOBJECT_H
