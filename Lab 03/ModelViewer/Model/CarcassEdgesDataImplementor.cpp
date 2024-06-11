//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "CarcassEdgesDataImplementor.h"

std::vector<EdgeData> & CarcassEdgesDataImplementor::getEdges() {
    return *edges;
}

CarcassEdgesDataImplementor::CarcassEdgesDataImplementor() {
    edges = std::make_shared<std::vector<EdgeData>>();
}

void CarcassEdgesDataImplementor::addNewEdge(const EdgeData &edgeData) {
    this->edges->push_back(edgeData);
}

CarcassEdgesDataImplementor::CarcassEdgesDataImplementor(std::shared_ptr<std::vector<EdgeData>> edges) : edges(edges) {

}

CarcassEdgesDataImplementor::~CarcassEdgesDataImplementor() {

}

