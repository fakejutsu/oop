//
// Created by Кирилл Воробьев on 10.06.2024.
//

#ifndef MODELVIEWER_COMPOSITECREATOR_H
#define MODELVIEWER_COMPOSITECREATOR_H

#include <memory>
#include "CompositeSceneObject.h"

class CompositeCreator {
public:
    virtual ~CompositeCreator() = default;
    virtual std::shared_ptr<CompositeSceneObject> create(std::vector<std::shared_ptr<SceneObject>> & objects) = 0;
};

template <typename T>
class CompositeFactory : public CompositeCreator
{
public:
    virtual ~CompositeFactory() override = default;
    virtual std::shared_ptr<CompositeSceneObject> create(std::vector<std::shared_ptr<SceneObject>> & objects) override
    {
        return std::make_shared<T>(objects);
    }
};



#endif //MODELVIEWER_COMPOSITECREATOR_H
