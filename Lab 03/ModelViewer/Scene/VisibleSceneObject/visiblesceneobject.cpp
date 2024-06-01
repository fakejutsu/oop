#include "visiblesceneobject.h"

VisibleSceneObject::VisibleSceneObject() {}

bool VisibleSceneObject::isComposite() const noexcept {
    return false;
}

bool VisibleSceneObject::isVisible() const noexcept {
    return true;
}
