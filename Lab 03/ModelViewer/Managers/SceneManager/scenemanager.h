#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H


#include "basemanager.h"
#include "scene.h"
#include "managercreator.h"
#include "drawmanager.h"
#include <vector>

using cameraCollection = std::vector<int>;

class SceneManager : public BaseManager
{
public:

    virtual int addObject(std::shared_ptr<SceneObject> obj);
    virtual std::shared_ptr<SceneObject> removeObjectById(int objId);
    virtual void compositeFromObjects(std::vector<int> ids);
    virtual void drawScene();
    virtual int createCamera();
    virtual void deleteCamera(int objId);
    virtual void setMainCamera(int objId);
    virtual void clearScene();
    virtual void rotateCameraTrace(double ox, double oy, double oz);
    virtual std::string sceneTextList();

    virtual std::shared_ptr<SceneObject> getObjectById(int id);

    SceneManager(const SceneManager &create) = delete;
    SceneManager & operator=(const SceneManager &) = delete;


protected:
    SceneManager();
    std::shared_ptr<Scene> scene = nullptr;
    std::shared_ptr<cameraCollection> cameras = nullptr;
};

#endif // SCENEMANAGER_H
