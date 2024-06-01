#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "transformmatrix.h"
#include "visitorbase.h"

class SceneObject
{
public:
    virtual ~SceneObject() = 0;

    int getId();
    virtual bool isComposite() const noexcept = 0;
    virtual bool isVisible() const noexcept = 0;

    virtual void accept(VisitorBase &v) = 0;

    // todo clone()

    // void restoreMemento();
    // Type createMemento();

    // begin()
    // end()



    void setTransformMatrix(std::shared_ptr<TransformMatrix> transformMatrix);
    std::shared_ptr<TransformMatrix> getTransformMatrix();

protected:
    int id;
    Point3d pos;
    std::shared_ptr<TransformMatrix> transformationMatrix;
};

#endif // SCENEOBJECT_H
