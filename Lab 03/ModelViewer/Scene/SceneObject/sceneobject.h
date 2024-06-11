#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "TransformationData.h"
#include "point3d.h"
#include <string>
#include "TransformHelper.h"
#include <vector>
#include "SceneObjectMemento.h"
#include "basesceneiterator.h"

class TransformVisitor;
class VisitorBase;



class SceneObject
{


    friend TransformVisitor;

public:
    using ComposiIterator = std::__wrap_iter<std::vector<std::shared_ptr<SceneObject>, std::allocator<std::shared_ptr<SceneObject>>>::pointer>;
    SceneObject();
    virtual ~SceneObject() = 0;

    int getId();
    void setId(int id);

    virtual void addObjectToComposite(std::shared_ptr<SceneObject>) {};
    virtual void removeObjectFromComposite(std::shared_ptr<SceneObject>) {};

    virtual bool isComposite() { return false;};
    virtual bool isVisible() const noexcept = 0;

    virtual void accept(VisitorBase &v) = 0;

    virtual std::string objectName();

    // todo clone()

    virtual void restoreMemento(std::shared_ptr<SceneObjectMemento> memento);
    virtual std::shared_ptr<SceneObjectMemento> createMemento();

    virtual ComposiIterator begin() { return ComposiIterator();};
    virtual ComposiIterator end() { return ComposiIterator();};

    Point3dForm getPos();
    virtual applyTransformForm getTransformForm();

protected:
    int id;
    std::shared_ptr<TransformationData> transformationData;
};

#endif // SCENEOBJECT_H
