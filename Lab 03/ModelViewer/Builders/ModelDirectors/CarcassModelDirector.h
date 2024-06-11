//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSMODELDIRECTOR_H
#define MODELVIEWER_CARCASSMODELDIRECTOR_H

#include "CarcassModelBuilder.h"
#include "CarcassModelCreator.h"

#include <memory>

class CarcassModelDirector : public CarcassModelCreator {
public:
    CarcassModelDirector(std::unique_ptr<AbsCarcassModelSource>) {};
    CarcassModelDirector() = default;

protected:
    std::shared_ptr<CarcassModelBuilder> builder;
};


#endif //MODELVIEWER_CARCASSMODELDIRECTOR_H
