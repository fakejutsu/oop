#include "addcameracommand.h"
#include "managercreator.h"
#include "scenemanager.h"

AddCameraCommand::AddCameraCommand() {}

void AddCameraCommand::execute()
{
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->createCamera();
}
