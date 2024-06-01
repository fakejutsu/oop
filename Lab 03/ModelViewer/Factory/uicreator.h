#ifndef UICREATOR_H
#define UICREATOR_H

#include "drawsceneadapter.h"
#include "fileloaderadapter.h"
#include "penadapter.h"
#include <memory>

class UICreator
{
public:
    UICreator();

    virtual std::shared_ptr<PenAdapter> createPen() = 0;
    virtual std::shared_ptr<FileLoaderAdapter> createFileLoader() = 0;
    virtual std::shared_ptr<DrawSceneAdapter> createDrawScene() = 0;
};

#endif // UICREATOR_H
