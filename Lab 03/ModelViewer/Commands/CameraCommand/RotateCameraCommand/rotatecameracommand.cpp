#include "rotatecameracommand.h"
#include "TransformManager.h"
#include "managercreator.h"
#include "scenemanager.h"

RotateCameraCommand::RotateCameraCommand(double ox, double oy, double oz){
    this->ox = ox;
    this->oy = oy;
    this->oz = oz;
}

void RotateCameraCommand::execute()
{
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->rotateCameraTrace(ox, oy, oz);
}
