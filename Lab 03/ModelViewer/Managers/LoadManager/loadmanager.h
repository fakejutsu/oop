#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "basemanager.h"
#include "modelobject.h"
class LoadManager : BaseManager
{
public:
    LoadManager();

    std::shared_ptr<ModelObject> loadModelFromFile();
    std::shared_ptr<ModelObject> loadModelFromString(std::string);
};

#endif // LOADMANAGER_H
