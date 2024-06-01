#include "compositesceneobject.h"

CompositeSceneObject::CompositeSceneObject() {}

bool CompositeSceneObject::isVisible() const noexcept {
    return true;
}

bool CompositeSceneObject::isComposite() const noexcept {
    return true;
}

