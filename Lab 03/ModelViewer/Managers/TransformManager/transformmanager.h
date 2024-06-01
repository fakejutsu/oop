#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "basemanager.h"
#include "point3d.h"

class TransformManager : BaseManager
{
public:
    TransformManager();
    virtual void scaleObject(int objectId, double sx, double sy, double sz);
    virtual void transformObject(int objectId, double dx, double dy, double dz);
    virtual void rotateObject(int objectId, double ox, double oy, double oz);
};



#endif // TRANSFORMMANAGER_H
