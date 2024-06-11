//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "CarcassDotEdgesModelDirector.h"
#include "CarcassDotEdgesModelBuilder.h"

std::shared_ptr<CarcassModelEntity> CarcassDotEdgesModelDirector::create() {
    builder->buildVertex();
    builder->buildEdges();

    return builder->getModel();
}

CarcassDotEdgesModelDirector::CarcassDotEdgesModelDirector(std::shared_ptr<FileReader> src) {
    builder = std::make_shared<CarcassDotEdgesModelBuilder>(src);
}