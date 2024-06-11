//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "CarcassObject.h"

std::string CarcassObject::objectName() {
    return ModelObject::objectName();
}

void CarcassObject::accept(VisitorBase &v) {
    ModelObject::accept(v);
}

CarcassObject::~CarcassObject() {

}

CarcassObject::CarcassObject(std::shared_ptr<ModelAbstraction> modelEntity) {
    this->entity = modelEntity;
}

std::shared_ptr<ModelAbstraction> CarcassObject::getEntity() {
    return entity;
}
