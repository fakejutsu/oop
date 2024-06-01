#include "modelcreatorsolution.h"
#include "edgesmodeldirector.h"

ModelCreatorSolution::ModelCreatorSolution() {}

std::shared_ptr<ModelCreator> ModelCreatorSolution::getModelCreatorForExtension(const std::string & filename)
{
    return std::make_shared<EdgesModelDirector>();
}
