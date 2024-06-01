#include "rotatecameracommand.h"
#include "TransformManager.h"
#include "managercreator.h"

RotateCameraCommand::RotateCameraCommand(int cameraId, double ox, double oy, double oz){

    this->cameraId = cameraId;
    this->ox = ox;
    this->oy = oy;
    this->oz = oz;
}

void RotateCameraCommand::execute()
{
    auto transformManager = ManagerCreator<TransformManager>::CreateManager();
    transformManager->rotateObject(cameraId, ox, oy, oz);
}
