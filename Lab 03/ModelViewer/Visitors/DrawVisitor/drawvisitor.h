#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "cameraobject.h"
#include "compositesceneobject.h"
#include "modelobject.h"
#include "scene.h"
#include "visitorbase.h"
#include "drawsceneinneradapter.h"
#include "CarcassObject.h"


class DrawVisitor : public VisitorBase
{
public:
    DrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter, std::shared_ptr<CameraObject> camera);

    virtual void visit(ModelObject & model) override;
    virtual void visit(CarcassObject & model) override;
    virtual void visit(Scene & scene) override;
    virtual void visit(CameraObject & camera) override;
    virtual void visit(CompositeSceneObject &composite) override;

private:

    std::shared_ptr<DrawSceneAdapter> drawSceneAdapter;
    std::shared_ptr<CameraObject> viewCamera;
};

#endif // DRAWVISITOR_H
