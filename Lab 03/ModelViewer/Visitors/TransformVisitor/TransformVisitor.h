//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_TRANSFORMVISITOR_H
#define MODELVIEWER_TRANSFORMVISITOR_H


#include "visitorbase.h"
#include "TransformationData.h"
#include "modelobject.h"
#include "scene.h"
#include "cameraobject.h"
#include "compositesceneobject.h"

class TransformVisitor : public VisitorBase {
public:
    explicit TransformVisitor(const TransformationData & data);
    explicit TransformVisitor(const Transform & data);
    explicit TransformVisitor(const Rotate & data);
    explicit TransformVisitor(const Scale & data);

    virtual void visit(ModelObject & model) override;
    virtual void visit(CarcassObject & model) override;
    virtual void visit(Scene & scene) override;
    virtual void visit(CameraObject & camera) override;
    virtual void visit(CompositeSceneObject & composite) override;

private:
    TransformationData data;
};


#endif //MODELVIEWER_TRANSFORMVISITOR_H
