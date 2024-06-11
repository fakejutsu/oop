#include "drawmanager.h"
#include "drawvisitor.h"

#include "managercreator.h"
#include "scenemanager.h"

DrawManager::DrawManager() {
    sceneAdapter = nullptr;
}

void DrawManager::drawObject(std::shared_ptr<SceneObject> obj, std::shared_ptr<CameraObject> camera) {
    std::shared_ptr<DrawVisitor> visitor = std::make_shared<DrawVisitor>(this->sceneAdapter, camera);
    obj->accept(*visitor);
}

void DrawManager::setScene(std::shared_ptr<DrawSceneAdapter> scene) {
    sceneAdapter = scene;
}

void DrawManager::clearScene() {
    sceneAdapter->clear();
}
