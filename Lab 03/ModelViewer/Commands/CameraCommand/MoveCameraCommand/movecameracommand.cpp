#include "movecameracommand.h"
#include "transformmanager.h"
#include "managercreator.h"

MoveCameraCommand::MoveCameraCommand(int cameraId, double dx, double dy, double dz){

    this->cameraId = cameraId;
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}

void MoveCameraCommand::execute()
{
    auto transformManager = ManagerCreator<TransformManager>::CreateManager();
    transformManager->transformObject(cameraId, dx, dy, dz);
}
