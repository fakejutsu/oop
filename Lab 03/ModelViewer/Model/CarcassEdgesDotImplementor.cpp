//
// Created by Кирилл Воробьев on 06.06.2024.
//

#include "CarcassEdgesDotImplementor.h"

CarcassEdgesDotImplementor::CarcassEdgesDotImplementor() {
    edges_cached = std::make_shared<std::vector<EdgeData>>();
}

CarcassEdgesDotImplementor::~CarcassEdgesDotImplementor() {

}

CarcassEdgesDotImplementor::CarcassEdgesDotImplementor(std::shared_ptr<std::vector<Point3dForm>> dots,
                                                       std::shared_ptr<std::vector<std::pair<int, int>>> edges) : CarcassEdgesDotImplementor() {
    this->vertexes = std::move(dots);
    this->edges = std::move(edges);
}

std::vector<EdgeData> &CarcassEdgesDotImplementor::getEdges() {
    if (!edges_cached->size())
    {
        for (int i = 0; i < edges->size(); ++i)
        {
            EdgeData edge = {vertexes->at(edges->at(i).first), vertexes->at(edges->at(i).second)};
            edges_cached->push_back(edge);
        }
    }



    return *edges_cached;
}
