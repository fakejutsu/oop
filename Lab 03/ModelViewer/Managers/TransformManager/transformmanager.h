#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include "basemanager.h"
#include "managercreator.h"
#include "scenemanager.h"

class TransformManager : public BaseManager
{
public:

    virtual void scaleObject(int objectId, double sx, double sy, double sz);
    virtual void transformObject(int objectId, double dx, double dy, double dz);
    virtual void rotateObject(int objectId, double ox, double oy, double oz);

    TransformManager(const TransformManager &create) = delete;
    TransformManager & operator=(const TransformManager &) = delete;

protected:
    virtual std::shared_ptr<SceneObject> getObject(int objectId);
    TransformManager();
private:
    void saveObjectToHistory(std::shared_ptr<SceneObject> obj);
};



#endif // TRANSFORMMANAGER_H
