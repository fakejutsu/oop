#ifndef UIFACTORYSOLUTION_H
#define UIFACTORYSOLUTION_H

#include "uiqtfactory.h"
class UIFactorySolution
{
public:
    UIFactorySolution();


    static std::shared_ptr<UIFactoryBase> CreateFactory();

protected:
    static std::shared_ptr<UIFactoryBase> instance;

private:
    static void createInstance()
    {
        instance = std::make_shared<UIQtFactory>();
    }

};

#endif // UIFACTORYSOLUTION_H
