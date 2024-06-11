//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_CARCASSDOTEDGESMODELDIRECTOR_H
#define MODELVIEWER_CARCASSDOTEDGESMODELDIRECTOR_H

#include "CarcassModelDirector.h"
#include "FileReader.h"

class CarcassDotEdgesModelDirector : public CarcassModelDirector {
public:
    CarcassDotEdgesModelDirector(std::shared_ptr<FileReader> src);
    std::shared_ptr<CarcassModelEntity> create() override;

private:

};

#endif //MODELVIEWER_CARCASSDOTEDGESMODELDIRECTOR_H
