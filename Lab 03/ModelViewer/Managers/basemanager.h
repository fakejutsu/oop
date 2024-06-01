#ifndef BASEMANAGER_H
#define BASEMANAGER_H

#include "uifactorybase.h"
class BaseManager
{
public:
    BaseManager();

protected:
    std::shared_ptr<UIFactoryBase> uiFactory = nullptr;

};

#endif // BASEMANAGER_H
