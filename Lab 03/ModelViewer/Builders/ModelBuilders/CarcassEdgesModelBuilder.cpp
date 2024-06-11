//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "CarcassEdgesModelBuilder.h"
#include "SourceFactory.h"

CarcassEdgesModelBuilder::CarcassEdgesModelBuilder(std::shared_ptr<FileReader> reader) {
    auto srcCreator = std::make_shared<SourceFactory<TextEdgesModelSource>>();
    this->src = srcCreator->createConrecte(reader);
    this->edges = std::make_shared<std::vector<EdgeData>>();
}

CarcassEdgesModelBuilder::~CarcassEdgesModelBuilder() {

}

void CarcassEdgesModelBuilder::buildEdges() {
    *(this->edges) = this->src->getEdges();
    ++state;
}

std::shared_ptr<CarcassModelEntity> CarcassEdgesModelBuilder::getModel() {
    std::shared_ptr<CarcassModelImplementor> impl = std::make_shared<CarcassEdgesDataImplementor>(this->edges);

    return std::make_shared<CarcassModelEntity>(impl);
}

void CarcassEdgesModelBuilder::buildVertex() {
    ++state;
}
