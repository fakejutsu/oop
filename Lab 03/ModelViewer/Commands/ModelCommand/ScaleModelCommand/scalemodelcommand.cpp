#include "scalemodelcommand.h"

#include "ManagerCreator.h"
#include "TransformManager.h"

ScaleModelCommand::ScaleModelCommand(int modelId, double sx, double sy, double sz)
    : ModelCommand(modelId){

    this->sx = sx;
    this->sy = sy;
    this->sz = sz;
}

void ScaleModelCommand::execute()
{
    auto transformManager = ManagerCreator<TransformManager>::CreateManager();
    transformManager->scaleObject(modelId, sx, sy, sz);
}
