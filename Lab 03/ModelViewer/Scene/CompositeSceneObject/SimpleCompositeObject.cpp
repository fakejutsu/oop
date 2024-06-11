//
// Created by Кирилл Воробьев on 10.06.2024.
//

#include "SimpleCompositeObject.h"

SimpleCompositeObject::SimpleCompositeObject(SimpleCompositeObject::SimpleObjectCollection &objects) {
    collection = std::make_shared<SimpleObjectCollection>();
    for (int i = 0; i < objects.size(); ++i)
    {
        collection->push_back(objects.at(i));
    }
}

void SimpleCompositeObject::accept(VisitorBase &v)
{
    v.visit(*this);
}

void SimpleCompositeObject::addObjectToComposite(std::shared_ptr<SceneObject> obj) {
    collection->push_back(obj);
}

void SimpleCompositeObject::removeObjectFromComposite(std::shared_ptr<SceneObject> obj) {
}

std::__wrap_iter<std::vector<std::shared_ptr<SceneObject>, std::allocator<std::shared_ptr<SceneObject>>>::pointer>
SimpleCompositeObject::begin() {
    return collection->begin();
}

std::__wrap_iter<std::vector<std::shared_ptr<SceneObject>, std::allocator<std::shared_ptr<SceneObject>>>::pointer> SimpleCompositeObject::end() {
    return collection->end();
}

std::string SimpleCompositeObject::objectName() {
    return "Простая группа";
}
