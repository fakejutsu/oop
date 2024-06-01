#include "scene.h"

Scene::Scene() {
    objects = std::make_shared<ObjectContainer>();
}



Iterator Scene::begin()
{
    return objects->begin();
}

Iterator Scene::end()
{
    return objects->end();

}

int Scene::addObject(std::shared_ptr<SceneObject> obj) {
    int newObjId = getNewIdForObject();
    setNewObjectInternal(newObjId, obj);

    return newObjId;
}

std::shared_ptr<SceneObject> Scene::removeObjectById(int objId)
{
    auto object = getObjectById(objId);
    removeObjectInternal(objId);

    return object;
}

void Scene::clearScene()
{
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        removeObjectInternal(it->first);
    }
}
int Scene::createCamera()
{

}

std::shared_ptr<SceneObject> Scene::getObjectById(int id)
{
    return this->objects->at(id);
}

void Scene::accept(VisitorBase &v) {
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        it->second->accept(v);
    }
}

void Scene::removeObjectInternal(int objId) {
    this->objects->erase(objId);
}

int Scene::getNewIdForObject() {
    int maxId = this->objects->rbegin()->first;
    return maxId + 1;
}

void Scene::setNewObjectInternal(int objId, std::shared_ptr<SceneObject> obj) {
    this->objects->insert(std::pair<int, std::shared_ptr<SceneObject>>(objId, obj));
}

std::shared_ptr<CameraObject> Scene::curCamera() {
    return std::shared_ptr<CameraObject>();
}

void Scene::setNewMainCamera(int newMainCameraId) {

}
