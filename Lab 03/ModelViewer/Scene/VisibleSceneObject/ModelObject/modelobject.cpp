#include "modelobject.h"

#include "QDebug"

std::string ModelObject::objectName() {
    return "Модель";
}

ModelObject::~ModelObject() {
}

void ModelObject::accept(VisitorBase &v) {
    ModelObject & ref = *this;
    v.visit(ref);
}

