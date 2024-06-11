//
// Created by Кирилл Воробьев on 04.06.2024.
//

#include "ModelEntityDrawVisitor.h"

#include <utility>

ModelEntityDrawVisitor::ModelEntityDrawVisitor(std::shared_ptr<DrawSceneAdapter> sceneAdapter,
                                               std::shared_ptr<CameraObject> camera, applyTransformForm transformation) : drawSceneAdapter(std::move(sceneAdapter)),
                                                                                                                          viewCamera(std::move(camera)) {

        this->transformation = transformation;

}

void ModelEntityDrawVisitor::visit(CarcassModelEntity &model) {
    auto edges = model.getEdges();
    for (auto & edge : edges)
    {
        Point4dForm f = transformation * edge.first;
        Point4dForm s = transformation * edge.second;

        f = viewCamera->getTransformForm() * f;
        s = viewCamera->getTransformForm() * s;


        auto f1 = viewCamera->transformPointToCameraView(f);
        auto s1 = viewCamera->transformPointToCameraView(s);

        drawSceneAdapter->addLine({f1.x, f1.y}, {s1.x, s1.y});
    }
}
