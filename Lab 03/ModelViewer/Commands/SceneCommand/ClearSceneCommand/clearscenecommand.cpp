#include "clearscenecommand.h"
#include "managercreator.h"
#include "scenemanager.h"

ClearSceneCommand::ClearSceneCommand() {}

void ClearSceneCommand::execute()
{
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->clearScene();
}
