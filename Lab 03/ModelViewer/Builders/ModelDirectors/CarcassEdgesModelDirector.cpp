//
// Created by Кирилл Воробьев on 05.06.2024.
//

#include "CarcassEdgesModelDirector.h"
#include "CarcassEdgesModelBuilder.h"

std::shared_ptr<CarcassModelEntity> CarcassEdgesModelDirector::create() {
    builder->buildVertex();
    builder->buildEdges();

    return builder->getModel();
}

CarcassEdgesModelDirector::CarcassEdgesModelDirector(std::shared_ptr<FileReader> src) {
    builder = std::make_shared<CarcassEdgesModelBuilder>(src);
}
