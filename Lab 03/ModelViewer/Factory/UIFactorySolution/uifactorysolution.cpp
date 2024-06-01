#include "uifactorysolution.h"

 std::shared_ptr<UIFactoryBase> UIFactorySolution::CreateFactory()
{
    if (instance == nullptr)
    {
        createInstance();
    }

    return instance;
}

std::shared_ptr<UIFactoryBase> UIFactorySolution::instance = nullptr;
