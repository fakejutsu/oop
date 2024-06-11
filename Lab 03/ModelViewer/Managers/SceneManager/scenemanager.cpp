
#include "scenemanager.h"
#include "TraceCamera.h"
#include "RotateTraceCameraAdapter.h"
#include "CameraCreator.h"
#include "managercreator.h"
#include "transformmanager.h"
#include "CompositeCreator.h"
#include "SimpleCompositeObject.h"
#include "TransformVisitor.h"
#include "TransformVisitor.h"

SceneManager::SceneManager() {
    scene = std::make_shared<Scene>();
    cameras = std::make_shared<cameraCollection>();
    scene->setNewMainCamera(createCamera());

}

int SceneManager::addObject(std::shared_ptr<SceneObject> obj) {
    return scene->addObject(obj);
}

std::shared_ptr<SceneObject> SceneManager::removeObjectById(int objId) {
    return scene->removeObjectById(objId);
}

void SceneManager::drawScene() {
    auto drawManager = ManagerCreator<DrawManager>::CreateManager();
    drawManager->clearScene();
    for (auto it = scene->begin(); it != scene->end(); ++it)
    {

        drawManager->drawObject(it->second, scene->curCamera());
    }
}

void SceneManager::clearScene() {
    scene->clearScene();
}

int SceneManager::createCamera() {
    std::shared_ptr<CameraCreator> cr = std::make_shared<CameraFactory<TraceCamera>>();
    auto newCamera = cr->create();

    int id = addObject(newCamera);
    this->cameras->push_back(id);
    return id;
}

std::shared_ptr<SceneObject> SceneManager::getObjectById(int id) {
    return scene->getObjectById(id);
}

std::string SceneManager::sceneTextList() {
    return this->scene->textListObjects();
}

void SceneManager::rotateCameraTrace(double ox, double oy, double oz) {
    auto camera = this->scene->curCamera();
    auto traceCamera = (dynamic_cast<TraceCamera*>(camera.get()));
    if (traceCamera == nullptr)
    {
        return;
    }

    auto manager = ManagerCreator<TransformManager>::CreateManager();

    TransformVisitor visitor(Rotate(ox, oy, oz));
    traceCamera->accept(visitor);

    drawScene();
}

void SceneManager::deleteCamera(int objId) {
    int target = 0;
    for (int i = 0; i < cameras->size(); ++i)
    {
        if (cameras->at(i) == objId)
        {
            target = i;
            break;
        }
    }

    if (objId == this->scene->curCamera()->getId())
    {
        if (cameras->size() > 1)
        {
            removeObjectById(objId);

            cameras->erase(cameras->begin() + target);

            scene->setNewMainCamera(cameras->at(0));
        }
    }
    else
    {
        removeObjectById(objId);
        cameras->erase(cameras->begin() + target);
    }
}

void SceneManager::setMainCamera(int objId) {
    this->scene->setNewMainCamera(objId);
}

void SceneManager::compositeFromObjects(std::vector<int> ids) {

    std::shared_ptr<CompositeCreator> creator = std::make_shared<CompositeFactory<SimpleCompositeObject>>();

    auto v = std::make_shared<std::vector<std::shared_ptr<SceneObject>>>();

    for (int i = 0; i < ids.size(); ++i)
    {
        auto obj = this->getObjectById(ids[i]);
        v->push_back(obj);

        removeObjectById(ids[i]);
    }

    std::vector<std::shared_ptr<SceneObject>> &v2 = *v;

    auto composite = creator->create(v2);

    this->addObject(composite);
}
