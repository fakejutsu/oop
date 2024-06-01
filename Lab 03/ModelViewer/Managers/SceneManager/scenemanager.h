#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H


#include "basemanager.h"
#include "scene.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();

    virtual int addObject(std::shared_ptr<SceneObject> obj);
    virtual std::shared_ptr<SceneObject> removeObjectById(int objId);
    virtual void drawScene();
    virtual void clearScene();
    virtual int createCamera();

    virtual std::shared_ptr<SceneObject> getObjectById(int id);

protected:
    std::shared_ptr<Scene> scene = nullptr;
};

#endif // SCENEMANAGER_H
