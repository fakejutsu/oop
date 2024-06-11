#include "transformmanager.h"
#include "TransformVisitor.h"
#include "HistoryManager.h"

TransformManager::TransformManager() {}

void TransformManager::scaleObject(int objectId, double sx, double sy, double sz) {
    auto object = getObject(objectId);

    if (sx != 1 || sy != 1 || sz != 1) {
        saveObjectToHistory(object);
    }

    auto transform = TransformationData();

    auto scale = Scale(sx, sy, sz);
    transform += scale;

    auto visitor = std::make_shared<TransformVisitor>(transform);
    object->accept(*visitor);

    auto scene = ManagerCreator<SceneManager>::CreateManager();
    scene->drawScene();
}

void TransformManager::transformObject(int objectId, double dx, double dy, double dz) {
    auto object = getObject(objectId);

    if (dx != 0 || dy != 0 || dz != 0)
    {
        saveObjectToHistory(object);
    }

    auto transform = TransformationData();

    auto tran = Transform(dx, dy, dz);
    transform += tran;

    auto visitor = std::make_shared<TransformVisitor>(transform);
    object->accept(*visitor);
    auto scene = ManagerCreator<SceneManager>::CreateManager();
    scene->drawScene();
}

void TransformManager::rotateObject(int objectId, double ox, double oy, double oz) {
    auto object = getObject(objectId);

    if (ox != 0 || oy != 0 || oz != 0) {
        saveObjectToHistory(object);
    }

    auto transform = TransformationData();

    auto rot = Rotate(ox, oy, oz);
    transform += rot;

    auto visitor = std::make_shared<TransformVisitor>(transform);
    object->accept(*visitor);
    auto scene = ManagerCreator<SceneManager>::CreateManager();
    scene->drawScene();
}

std::shared_ptr<SceneObject> TransformManager::getObject(int objectId) {
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    return sceneManager->getObjectById(objectId);
}

void TransformManager::saveObjectToHistory(std::shared_ptr<SceneObject> obj) {
    auto historyManager = ManagerCreator<HistoryManager>::CreateManager();

    auto objMemento = obj->createMemento();
    historyManager->pushMemento(obj, objMemento);
}
