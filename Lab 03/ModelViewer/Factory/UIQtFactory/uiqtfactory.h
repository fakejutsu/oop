#ifndef UIQTFACTORY_H
#define UIQTFACTORY_H

#include "uifactorybase.h"

class UIQtFactory : public UIFactoryBase
{
public:
    UIQtFactory();

    virtual  std::shared_ptr<PenAdapter> createPen() override;
    virtual  std::shared_ptr<DrawSceneAdapter> createDrawScene() override;
    virtual  std::shared_ptr<FileLoaderAdapter> createFileLoader() override;
};

#endif // UIQTFACTORY_H
