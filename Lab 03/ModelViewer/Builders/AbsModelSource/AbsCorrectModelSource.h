//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_ABSCORRECTMODELSOURCE_H
#define MODELVIEWER_ABSCORRECTMODELSOURCE_H

#include <vector>
#include "edgedata.h"


class AbsCarcassModelSource {
public:
    virtual ~AbsCarcassModelSource() = default;
    virtual std::vector<EdgeData>&& getEdges() = 0;
    virtual std::vector<std::pair<int, int>>&& getEdgesIdPairs() = 0;
    virtual std::vector<Point3dForm>&& getVertexes() = 0;
};


#endif //MODELVIEWER_ABSCORRECTMODELSOURCE_H
