//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_INSTALLGRAPHICSCENECOMMAND_H
#define MODELVIEWER_INSTALLGRAPHICSCENECOMMAND_H

#include "drawsceneinneradapter.h"

class InstallGraphicSceneCommand {
public:
    InstallGraphicSceneCommand(std::shared_ptr<DrawSceneAdapter> scene);
};


#endif //MODELVIEWER_INSTALLGRAPHICSCENECOMMAND_H
