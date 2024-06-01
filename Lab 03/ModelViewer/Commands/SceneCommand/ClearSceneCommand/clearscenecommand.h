#ifndef CLEARSCENECOMMAND_H
#define CLEARSCENECOMMAND_H

#include "scenecommand.h"
class ClearSceneCommand : SceneCommand
{
public:
    ClearSceneCommand();

    virtual void execute() override;
};

#endif // CLEARSCENECOMMAND_H
