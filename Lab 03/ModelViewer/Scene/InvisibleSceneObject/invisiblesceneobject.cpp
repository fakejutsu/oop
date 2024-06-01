#include "invisiblesceneobject.h"

InvisibleSceneObject::InvisibleSceneObject() {}

bool InvisibleSceneObject::isComposite() const noexcept {
    return false;
}

bool InvisibleSceneObject::isVisible() const noexcept {
    return false;
}