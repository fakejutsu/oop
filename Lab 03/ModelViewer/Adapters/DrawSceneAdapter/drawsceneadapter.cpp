#include "drawsceneadapter.h"

DrawSceneAdapter::DrawSceneAdapter() {}

void DrawSceneAdapter::setPen(std::shared_ptr<PenAdapter> pen) {
    this->pen = pen;
}
