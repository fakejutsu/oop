#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "basemanager.h"
#include "modelobject.h"
#include "AbsCorrectModelSource.h"
#include "CarcassCreatorSolution.h"

class LoadManager : BaseManager
{
public:


    std::shared_ptr<ModelObject> loadModelFromFile(std::string &path);

    LoadManager(const LoadManager &create) = delete;
    LoadManager & operator=(const LoadManager &) = delete;
protected:
    LoadManager();

private:
    std::string getFileExtension(std::string &path);
};

#endif // LOADMANAGER_H
