//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSEDGESDATAIMPLEMENTOR_H
#define MODELVIEWER_CARCASSEDGESDATAIMPLEMENTOR_H

#include <memory>
#include "CarcassModelImplementor.h"

class CarcassEdgesDataImplementor : public CarcassModelImplementor {
public:
    CarcassEdgesDataImplementor();
    ~CarcassEdgesDataImplementor() override;
    explicit CarcassEdgesDataImplementor(std::shared_ptr<std::vector<EdgeData>> edges);
    virtual std::vector<EdgeData> & getEdges() override;
    void addNewEdge(const EdgeData &edgeData);
protected:
    std::shared_ptr<std::vector<EdgeData>> edges;
};


#endif //MODELVIEWER_CARCASSEDGESDATAIMPLEMENTOR_H
