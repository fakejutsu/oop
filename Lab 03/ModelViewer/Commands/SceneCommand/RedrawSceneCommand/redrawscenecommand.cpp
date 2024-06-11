#include "redrawscenecommand.h"
#include "managercreator.h"
#include "scenemanager.h"

RedrawSceneCommand::RedrawSceneCommand() {}

void RedrawSceneCommand::execute()
{
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->drawScene();
}
