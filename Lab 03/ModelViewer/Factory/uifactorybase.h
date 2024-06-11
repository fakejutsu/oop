#ifndef UIFACTORYBASE_H
#define UIFACTORYBASE_H

#include <concepts>



#include "uicreator.h"
class UIFactoryBase : public DrawSceneCreator
{
public:
    UIFactoryBase() = default;
    virtual std::shared_ptr<DrawSceneAdapter> createScene();
};

#endif // UIFACTORYBASE_H
