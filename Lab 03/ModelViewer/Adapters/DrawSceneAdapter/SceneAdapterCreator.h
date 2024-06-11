//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_SCENEADAPTERCREATOR_H
#define MODELVIEWER_SCENEADAPTERCREATOR_H

#include <memory>
#include "drawsceneadapter.h"

class SceneAdapterCreator {
public:
    virtual std::shared_ptr<DrawSceneAdapter> createDrawScene() = 0;
    virtual ~SceneAdapterCreator() = default;
};


#endif //MODELVIEWER_SCENEADAPTERCREATOR_H
