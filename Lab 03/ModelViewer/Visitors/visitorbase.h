#ifndef VISITORBASE_H
#define VISITORBASE_H

#include <memory>

class ModelObject;
class Scene;
class CameraObject;
class CompositeSceneObject;

class VisitorBase
{
public:
    VisitorBase();
    virtual ~VisitorBase() = default;

    virtual void visitModel(ModelObject & model) = 0;
    virtual void visitScene(Scene & scene) = 0;
    virtual void visitCamera(CameraObject & camera) = 0;
    virtual void visitComposite(CompositeSceneObject & composite) = 0;
};

#endif // VISITORBASE_H
