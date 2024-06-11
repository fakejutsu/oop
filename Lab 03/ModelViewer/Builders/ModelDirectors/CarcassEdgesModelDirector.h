//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_CARCASSEDGESMODELDIRECTOR_H
#define MODELVIEWER_CARCASSEDGESMODELDIRECTOR_H

#include "CarcassModelDirector.h"
#include "FileReader.h"
#include <memory>

class CarcassEdgesModelDirector : public CarcassModelDirector {
public:
    CarcassEdgesModelDirector(std::shared_ptr<FileReader> src);
    std::shared_ptr<CarcassModelEntity> create() override;
};


#endif //MODELVIEWER_CARCASSEDGESMODELDIRECTOR_H
