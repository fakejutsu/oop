#include "scene.h"

#include <utility>
#include "QDebug"
#include "NotFoundItemScene.h"

Scene::Scene() {
    objects = std::make_shared<ObjectContainer>();
    camera = nullptr;
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
    setNewObjectInternal(newObjId, std::move(obj));

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
    Iterator prevIterator = this->end();
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        if (it != this->begin())
        {
            removeObjectInternal(prevIterator->first);
        }
        prevIterator = it;
    }
    if (prevIterator != this->end())
        removeObjectInternal(prevIterator->first);
}
int Scene::createCamera()
{

}

std::shared_ptr<SceneObject> Scene::getObjectById(int id)
{
    if (!objects->contains(id))
        throw NotFoundItemScene("No objects on scene" + std::to_string(id), __FILE__, __LINE__);
    return this->objects->operator[](id);
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
    if (this->objects->empty())
    {
        return 1;
    }
    int maxId = this->objects->rbegin()->first;
    return maxId + 1;
}

void Scene::setNewObjectInternal(int objId, std::shared_ptr<SceneObject> obj) {
    obj->setId(objId);
    this->objects->insert(std::pair<int, std::shared_ptr<SceneObject>>(objId, obj));
}

std::shared_ptr<CameraObject> Scene::curCamera() {
    return camera;
}

void Scene::setNewMainCamera(int newMainCameraId) {
    auto object = getObjectById(newMainCameraId);
    auto cameraObj = std::dynamic_pointer_cast<CameraObject>(object);
    if (cameraObj == nullptr)
    {
        return;
    }

    camera = cameraObj;
}

std::string Scene::textListObjects() {
    std::string text = "";
    text += "\n----------------------------------\n";
    text += std::format("Основная камера: {} {}", camera->objectName(), camera->getId());
    text += "\n----------------------------------\n";
    for (auto it = this->objects->begin(); it != this->objects->end(); ++it)
    {
        text += "\n----------------------------------\n";

        auto pos = it->second->getPos();
        auto vec4pos = Point4dForm(pos.x, pos.y, pos.z, 1);
        auto transformMatrix = it->second->getTransformForm();
        auto calculatedPos =  transformMatrix * vec4pos;

        text += std::format("{:^10} {:10} ({:5}, {:5}, {:5})", it->first, it->second->objectName(), calculatedPos.x, calculatedPos.y, calculatedPos.z);
    }

    return text;
}
