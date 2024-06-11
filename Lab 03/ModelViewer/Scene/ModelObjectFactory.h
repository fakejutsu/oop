//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_MODELOBJECTFACTORY_H
#define MODELVIEWER_MODELOBJECTFACTORY_H

#include "ModelObjectCreator.h"

template <typename T>
class ModelObjectFactory : public ModelObjectCreator {
public:

    virtual std::shared_ptr<ModelObject> createModelObject(std::shared_ptr<ModelAbstraction> abs) override {
        return std::make_shared<T>(abs);
    }

    virtual ~ModelObjectFactory() override = default;
};


#endif //MODELVIEWER_MODELOBJECTFACTORY_H
