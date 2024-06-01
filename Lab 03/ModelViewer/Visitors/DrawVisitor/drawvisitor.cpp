#include "drawvisitor.h"
#include "drawsceneadapter.h"

DrawVisitor::DrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter, std::shared_ptr<CameraObject> camera) {
    this->drawSceneAdapter = sceneAdapter;
    this->viewCamera = camera;
}

void DrawVisitor::visitModel(ModelObject &model) {

}

void DrawVisitor::visitScene(Scene &scene) {

}

void DrawVisitor::visitCamera(CameraObject &camera) {
    return;
}

void DrawVisitor::visitComposite(CompositeSceneObject &composite) {

}
