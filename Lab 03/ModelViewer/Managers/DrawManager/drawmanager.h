#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "sceneobject.h"
#include <memory>
#include "cameraobject.h"
#include "drawsceneinneradapter.h"


class DrawManager : public BaseManager
{
public:
    void drawObject(std::shared_ptr<SceneObject> obj, std::shared_ptr<CameraObject> camera);
    void setScene(std::shared_ptr<DrawSceneAdapter> scene);
    void clearScene();

    DrawManager(const DrawManager &create) = delete;
    DrawManager & operator=(const DrawManager &) = delete;

protected:
    DrawManager();
    std::shared_ptr<DrawSceneAdapter> sceneAdapter;
};

#endif // DRAWMANAGER_H
