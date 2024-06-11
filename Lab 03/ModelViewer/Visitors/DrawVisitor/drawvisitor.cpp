#include "drawvisitor.h"

#include <utility>
#include "drawsceneinneradapter.h"
#include "ModelObjectEntityAdapter.h"
#include "ModelEntityDrawVisitor.h"
#include "CarcassModelEntity.h"
#include "QDebug"

DrawVisitor::DrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter, std::shared_ptr<CameraObject> camera) {
    this->drawSceneAdapter = std::move(sceneAdapter);
    this->viewCamera = std::move(camera);
}

void DrawVisitor::visit(CarcassObject &model) {
    visit((ModelObject&)(model));
}

void DrawVisitor::visit(ModelObject &model) {
    auto entity = model.getEntity();

    auto entityVisitor = std::make_shared<ModelEntityDrawVisitor>(drawSceneAdapter, viewCamera, model.getTransformForm());
    entity->accept(*entityVisitor);

    qDebug() << "внутренний конец посещения";
}

void DrawVisitor::visit(Scene &scene) {

}

void DrawVisitor::visit(CameraObject &camera) {
}

void DrawVisitor::visit(CompositeSceneObject &composite) {
    for (auto it = composite.begin(); it != composite.end(); ++it)
    {
        auto &obj = *it;
        obj->accept(*this);
    }
}
