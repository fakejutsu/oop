#ifndef UIFACTORYSOLUTION_H
#define UIFACTORYSOLUTION_H

#include "RefDrawSceneCreator.h"

enum class UIType
{
    QT
};

template <typename Derived, typename Base>
concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template <typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;


template <typename T>
concept forFactory = std::is_base_of<UIFactoryBase, T>();

template<forFactory T>
class UIFactorySolution
{
public:
    UIFactorySolution();

    static std::shared_ptr<T> CreateFactory()
    {
        if (instance == nullptr)
        {
            createInstance();
        }

        return instance;
    }

protected:
    static std::shared_ptr<T> instance;

private:
    static void createInstance()
    {
        instance = std::make_shared<T>();
    }

};

template<forFactory T>
std::shared_ptr<T> UIFactorySolution<T>::instance = nullptr;

#endif // UIFACTORYSOLUTION_H
