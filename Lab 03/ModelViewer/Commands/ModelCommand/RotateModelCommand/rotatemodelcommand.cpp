#include "rotatemodelcommand.h"


#include "ManagerCreator.h"
#include "TransformManager.h"

RotateModelCommand::RotateModelCommand(int modelId, double ox, double oy, double oz)
    : ModelCommand(modelId){

    this->ox = ox;
    this->oy = oy;
    this->oz = oz;
}

void RotateModelCommand::execute()
{
    auto transformManager = ManagerCreator<TransformManager>::CreateManager();
    transformManager->rotateObject(modelId, ox, oy, oz);
}
