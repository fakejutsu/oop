//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_CARCASSEDGESDOTIMPLEMENTOR_H
#define MODELVIEWER_CARCASSEDGESDOTIMPLEMENTOR_H

#include <memory>
#include "edgedata.h"
#include <vector>

#include "CarcassModelImplementor.h"

class CarcassEdgesDotImplementor : public CarcassModelImplementor {
    public:
        CarcassEdgesDotImplementor();
        ~CarcassEdgesDotImplementor() override;
        explicit CarcassEdgesDotImplementor(std::shared_ptr<std::vector<Point3dForm>> dots,
                                            std::shared_ptr<std::vector<std::pair<int, int>>> edges);
        virtual std::vector<EdgeData> & getEdges() override;
    protected:
        std::shared_ptr<std::vector<std::pair<int, int>>> edges;
        std::shared_ptr<std::vector<Point3dForm>> vertexes;

        std::shared_ptr<std::vector<EdgeData>> edges_cached;
};


#endif //MODELVIEWER_CARCASSEDGESDOTIMPLEMENTOR_H
