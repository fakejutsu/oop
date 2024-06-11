#ifndef REDRAWSCENECOMMAND_H
#define REDRAWSCENECOMMAND_H

#include "scenecommand.h"
class RedrawSceneCommand : public SceneCommand
{
public:
    RedrawSceneCommand();
    virtual void execute() override;
};

#endif // REDRAWSCENECOMMAND_H
