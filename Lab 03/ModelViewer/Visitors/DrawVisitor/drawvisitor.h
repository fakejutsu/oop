#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "cameraobject.h"
#include "compositesceneobject.h"
#include "modelobject.h"
#include "scene.h"
#include "visitorbase.h"
#include "drawsceneadapter.h"


class DrawVisitor : public VisitorBase
{
public:
    DrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter, std::shared_ptr<CameraObject> camera);

    virtual void visitModel(ModelObject & model) override;
    virtual void visitScene(Scene & scene) override;
    virtual void visitCamera(CameraObject & camera) override;

    virtual void visitComposite(CompositeSceneObject &composite) override;

private:
    std::shared_ptr<DrawSceneAdapter> drawSceneAdapter;
    std::shared_ptr<CameraObject> viewCamera;
};

#endif // DRAWVISITOR_H
