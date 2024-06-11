#ifndef UIQTFACTORY_H
#define UIQTFACTORY_H

#include "uicreator.h"
#include "drawsceneinneradapter.h"
#include "qgraphicsscene.h"

template <typename Derived, typename Base>
concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

template <typename Type>
concept NotAbstract = !std::is_abstract_v<Type>;


template<Derivative<DrawSceneAdapter> T>
requires NotAbstract<T>
class RefDrawSceneCreator : public DrawSceneCreator
{
public:

    RefDrawSceneCreator() {

    }


    virtual  std::shared_ptr<DrawSceneAdapter> createDrawScene() const override {
        return std::shared_ptr<DrawSceneAdapter>();
    }
};

#endif // UIQTFACTORY_H
