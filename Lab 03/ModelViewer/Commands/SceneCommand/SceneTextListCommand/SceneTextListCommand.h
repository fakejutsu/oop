//
// Created by Кирилл Воробьев on 01.06.2024.
//

#ifndef MODELVIEWER_SCENETEXTLISTCOMMAND_H
#define MODELVIEWER_SCENETEXTLISTCOMMAND_H


#include "scenecommand.h"
#include <string>

class SceneTextListCommand : public SceneCommand {
public:
    SceneTextListCommand(std::string &result);
    virtual void execute() override;
private:
    std::string &result;
};


#endif //MODELVIEWER_SCENETEXTLISTCOMMAND_H
