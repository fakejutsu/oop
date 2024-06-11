//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSMODELIMPLEMENTOR_H
#define MODELVIEWER_CARCASSMODELIMPLEMENTOR_H

#include "ModelImplementor.h"

class CarcassModelImplementor : public ModelImplementor {
public:
    CarcassModelImplementor() = default;
    ~CarcassModelImplementor() override = default;
    virtual std::vector<EdgeData> & getEdges() = 0;
};


#endif //MODELVIEWER_CARCASSMODELIMPLEMENTOR_H
