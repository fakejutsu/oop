//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_SCENEOBJECTMEMENTO_H
#define MODELVIEWER_SCENEOBJECTMEMENTO_H

#include <utility>
#include <memory>

#include "TransformationData.h"

struct MementoData
{
    explicit MementoData(std::shared_ptr<TransformationData> data) : data(*data){};
    TransformationData data;
};

class SceneObjectMemento {
public:
    explicit SceneObjectMemento(std::shared_ptr<MementoData> data);
    virtual std::shared_ptr<MementoData> getMemento();
private:
    std::shared_ptr<MementoData> memento;
};

class SceneObjectMementoCreator
{
public:
    virtual ~SceneObjectMementoCreator() = default;
    virtual std::shared_ptr<SceneObjectMemento> create() = 0;
};

template <typename T>
class SceneObjectMementoFactory : public SceneObjectMementoCreator
{
public:
    explicit SceneObjectMementoFactory(std::shared_ptr<MementoData> data)
    {
        this->data = data;
    }

    virtual std::shared_ptr<SceneObjectMemento> create() override
    {
        return std::make_shared<T>(data);
    }

private:
    std::shared_ptr<MementoData> data;
};

#endif //MODELVIEWER_SCENEOBJECTMEMENTO_H
