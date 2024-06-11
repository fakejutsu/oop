#include "compositesceneobject.h"

CompositeSceneObject::CompositeSceneObject(){
    //collection = std::make_shared<>
}

bool CompositeSceneObject::isVisible() const noexcept {
    return true;
}

bool CompositeSceneObject::isComposite()  {
    return true;
}
