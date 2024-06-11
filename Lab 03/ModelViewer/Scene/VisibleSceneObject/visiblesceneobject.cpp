#include "visiblesceneobject.h"

VisibleSceneObject::VisibleSceneObject() {}

bool VisibleSceneObject::isComposite() {
    return false;
}

bool VisibleSceneObject::isVisible() const noexcept {
    return true;
}
