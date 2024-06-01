#include "uiqtfactory.h"

UIQtFactory::UIQtFactory() {}

std::shared_ptr<PenAdapter> UIQtFactory::createPen() {
    return std::shared_ptr<PenAdapter>();
}

std::shared_ptr<DrawSceneAdapter> UIQtFactory::createDrawScene() {
    return std::shared_ptr<DrawSceneAdapter>();
}

std::shared_ptr<FileLoaderAdapter> UIQtFactory::createFileLoader() {
    return std::shared_ptr<FileLoaderAdapter>();
}
