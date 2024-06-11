//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_MODELENTITYDRAWVISITOR_H
#define MODELVIEWER_MODELENTITYDRAWVISITOR_H

#include "ModelEntityVisitorBase.h"
#include "CarcassModelEntity.h"
#include "drawsceneinneradapter.h"
#include "TransformHelper.h"
#include "cameraobject.h"

class ModelEntityDrawVisitor : public ModelEntityVisitorBase {
public:
    ModelEntityDrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter, std::shared_ptr<CameraObject> camera,
                           applyTransformForm transformation);
    virtual ~ModelEntityDrawVisitor() = default;

    virtual void visit(CarcassModelEntity & model) override;

private:
    std::shared_ptr<DrawSceneAdapter> drawSceneAdapter;
    std::shared_ptr<CameraObject> viewCamera;
    applyTransformForm transformation;
};


#endif //MODELVIEWER_MODELENTITYDRAWVISITOR_H
