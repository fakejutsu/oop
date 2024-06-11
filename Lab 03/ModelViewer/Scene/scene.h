#ifndef SCENE_H
#define SCENE_H


#include "sceneobject.h"
#include <map>
#include <memory>
#include "cameraobject.h"

#include "sceneobject.h"

using ObjectContainer = std::map<int, std::shared_ptr<SceneObject>>;
using Iterator = ObjectContainer::iterator;

class Scene
{
public:
    Scene();

    int addObject(std::shared_ptr<SceneObject>);
    virtual std::shared_ptr<SceneObject> removeObjectById(int objId);
    virtual void clearScene();
    virtual int createCamera();

    virtual Iterator begin();
    virtual Iterator end();

    virtual void accept(VisitorBase &v);

    virtual std::shared_ptr<SceneObject> getObjectById(int id);

    std::shared_ptr<CameraObject> curCamera();
    void setNewMainCamera(int newMainCameraId);

    virtual std::string textListObjects();

protected:
    std::shared_ptr<ObjectContainer> objects;
    std::shared_ptr<CameraObject> camera;

    void removeObjectInternal(int objId);
    void setNewObjectInternal(int objId, std::shared_ptr<SceneObject>);
    int getNewIdForObject();
};

#endif // SCENE_H
