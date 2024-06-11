#include "deletecameracommand.h"
#include "managercreator.h"
#include "scenemanager.h"

DeleteCameraCommand::DeleteCameraCommand(int cameraId) : cameraId(cameraId) {}

void DeleteCameraCommand::execute()
{
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->deleteCamera(cameraId);
}
