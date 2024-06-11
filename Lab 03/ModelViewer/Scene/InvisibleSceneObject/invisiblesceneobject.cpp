#include "invisiblesceneobject.h"

InvisibleSceneObject::InvisibleSceneObject() {}

bool InvisibleSceneObject::isComposite() {
    return false;
}

bool InvisibleSceneObject::isVisible() const noexcept {
    return false;
}
