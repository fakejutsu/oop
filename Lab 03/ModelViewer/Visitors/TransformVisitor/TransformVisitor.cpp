//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "TransformVisitor.h"
#include "sceneobject.h"


void TransformVisitor::visit(ModelObject &model) {
    (*model.transformationData) += this->data;
}

void TransformVisitor::visit(Scene &scene) {
    for (auto it = scene.begin(); it != scene.end(); ++it)
    {
        it->second->accept(*this);
    }
}

void TransformVisitor::visit(CameraObject &camera) {
    auto pos = camera.getPos();

    auto trans = Transform(-pos.x, -pos.y, -pos.z);


    camera.transformationData->operator+=(this->data);
}

void TransformVisitor::visit(CompositeSceneObject &composite) {
    for (auto it = composite.begin(); it != composite.end(); ++it)
    {
        auto &obj = *it;
        obj->accept(*this);
    }
}

TransformVisitor::TransformVisitor(const TransformationData &data) {
    this->data = data;
}

TransformVisitor::TransformVisitor(const Scale &data) {
    this->data = TransformationData();
    this->data += data;
}

TransformVisitor::TransformVisitor(const Rotate &data) {
    this->data = TransformationData();
    this->data += data;
    }

TransformVisitor::TransformVisitor(const Transform &data) {
    this->data = TransformationData();
    this->data += data;
}

void TransformVisitor::visit(CarcassObject &model) {
    visit((ModelObject&)(model));
}
