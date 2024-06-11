#include "qgraphicsscene.h"
#include "RefDrawSceneCreator.h"
#include "QtSceneAdapter.h"

UIQtFactory::UIQtFactory() {}

std::shared_ptr<DrawSceneAdapter> UIQtFactory::createDrawScene() {
    return std::shared_ptr<QtSceneAdapter>();
}

