//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_SCENEADAPTERFACTORY_H
#define MODELVIEWER_SCENEADAPTERFACTORY_H

#include <memory>
#include "drawsceneinneradapter.h"
#include "QGraphicsScene"
#include "QtSceneAdapter.h"
#include "SceneAdapterCreator.h"

template <typename T>
class SceneAdapterFactory : public SceneAdapterCreator {
public:

    std::shared_ptr<DrawSceneAdapter> createDrawScene() override
    {
        return std::make_shared<T>();
    }
};


#endif //MODELVIEWER_SCENEADAPTERFACTORY_H
