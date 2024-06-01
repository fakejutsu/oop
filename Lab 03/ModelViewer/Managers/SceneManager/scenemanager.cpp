
#include "scenemanager.h"

SceneManager::SceneManager() {}

int SceneManager::addObject(std::shared_ptr<SceneObject> obj) {
    return 0;
}

std::shared_ptr<SceneObject> SceneManager::removeObjectById(int objId) {
    return scene->removeObjectById(objId);
}

void SceneManager::drawScene() {

}

void SceneManager::clearScene() {

}

int SceneManager::createCamera() {
    return 0;
}

std::shared_ptr<SceneObject> SceneManager::getObjectById(int id) {
    return std::shared_ptr<SceneObject>();
}
