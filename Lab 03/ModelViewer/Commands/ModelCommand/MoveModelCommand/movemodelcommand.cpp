#include "movemodelcommand.h"
#include "managercreator.h"
#include "transformmanager.h"

MoveModelCommand::MoveModelCommand(int modelId, double dx, double dy, double dz)
    : ModelCommand(modelId){

    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}

void MoveModelCommand::execute()
{
    auto transformManager = ManagerCreator<TransformManager>::CreateManager();
    transformManager->transformObject(modelId, dx, dy, dz);
}
