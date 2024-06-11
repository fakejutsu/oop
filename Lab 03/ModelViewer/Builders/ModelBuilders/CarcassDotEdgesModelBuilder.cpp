//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "CarcassDotEdgesModelBuilder.h"
#include "CarcassEdgesDataImplementor.h"
#include "CarcassEdgesDotImplementor.h"
#include "ModelSourceCreator.h"
#include "TextDotEdgesModelSource.h"
#include "SourceFactory.h"

CarcassDotEdgesModelBuilder::CarcassDotEdgesModelBuilder(std::shared_ptr<FileReader> reader) {
    auto sourceCreator = std::make_shared<SourceFactory<TextDotEdgesModelSource>>();
    this->source = sourceCreator->createConrecte(reader);
}

CarcassDotEdgesModelBuilder::~CarcassDotEdgesModelBuilder() {

}

void CarcassDotEdgesModelBuilder::buildEdges() {
    this->edges =std::make_shared<std::vector<std::pair<int, int>>>(this->source->getEdgesIdPairs());
}

void CarcassDotEdgesModelBuilder::buildVertex() {
    this->points = std::make_shared<std::vector<Point3dForm>>(this->source->getVertexes());
}

std::shared_ptr<CarcassModelEntity> CarcassDotEdgesModelBuilder::getModel() {
    std::shared_ptr<CarcassModelImplementor> impl = std::make_shared<CarcassEdgesDotImplementor>(points, edges);

    return std::make_shared<CarcassModelEntity>(impl);
}
