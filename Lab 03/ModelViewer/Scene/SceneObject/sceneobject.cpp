#include "sceneobject.h"
#include "QDebug"
#include <memory>
#include "SceneObjectMemento.h"


SceneObject::~SceneObject() {
    qDebug() << "Создаю объект" << '\n';
    qDebug() << this << '\n';
}

int SceneObject::getId() {
    return id;
}

std::string SceneObject::objectName() {
    return "Объект";
}

Point3dForm SceneObject::getPos() {
    Point4dForm zero = {0, 0, 0, 1};
    zero = getTransformForm() * zero;
    Point3dForm pos = {zero.x, zero.y, zero.z};

    return pos;
}

applyTransformForm SceneObject::getTransformForm() {
        return transformationData->GetMatrix();
}

SceneObject::SceneObject() {
    this->transformationData = std::make_shared<TransformationData>();
}

void SceneObject::setId(int id) {
    this->id = id;
}

void SceneObject::restoreMemento(std::shared_ptr<SceneObjectMemento> memento) {
    auto mementoData = memento->getMemento();
    *(this->transformationData) = mementoData->data;
}

std::shared_ptr<SceneObjectMemento> SceneObject::createMemento() {
    auto mementoData = std::make_shared<MementoData>(transformationData);

    std::shared_ptr<SceneObjectMementoCreator> cr = std::make_shared<SceneObjectMementoFactory<SceneObjectMemento>>(mementoData);
    std::shared_ptr<SceneObjectMemento> memento = cr->create();

    return memento;
}
