#ifndef VISITORBASE_H
#define VISITORBASE_H

#include <memory>

class ModelObject;
class Scene;
class CameraObject;
class CompositeSceneObject;
class CarcassObject;

class VisitorBase
{
public:
    VisitorBase();
    virtual ~VisitorBase() = default;

    virtual void visit(ModelObject & model) = 0;
    virtual void visit(CarcassObject & model) = 0;
    virtual void visit(Scene & scene) = 0;
    virtual void visit(CameraObject & camera) = 0;
    virtual void visit(CompositeSceneObject & composite) = 0;
};

#endif // VISITORBASE_H
