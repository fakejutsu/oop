#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "sceneobject.h"


class DrawManager : public BaseManager
{
public:
    DrawManager();

    void drawObject(std::shared_ptr<SceneObject> obj);
};

#endif // DRAWMANAGER_H
