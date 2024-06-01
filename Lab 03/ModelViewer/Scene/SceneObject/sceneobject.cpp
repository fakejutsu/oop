#include "sceneobject.h"

SceneObject::~SceneObject() {}

void SceneObject::setTransformMatrix(std::shared_ptr<TransformMatrix> transformMatrix) {
    transformationMatrix = transformMatrix;
}

std::shared_ptr<TransformMatrix> SceneObject::getTransformMatrix() {
    return transformationMatrix;
}

int SceneObject::getId() {
    return id;
}
