//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "CarcassModelEntity.h"

#include <utility>
#include "QDebug"

void CarcassModelEntity::accept(ModelEntityVisitorBase &visitor) {
    visitor.visit(*this);
}

std::vector<EdgeData> CarcassModelEntity::getEdges() {
    return this->implementator->getEdges();
}

CarcassModelEntity::CarcassModelEntity(std::shared_ptr<CarcassModelImplementor> implementor) {
    this->implementator = std::move(implementor);
}

CarcassModelEntity::~CarcassModelEntity() {
    qDebug() << "Ломаю представление";
}
