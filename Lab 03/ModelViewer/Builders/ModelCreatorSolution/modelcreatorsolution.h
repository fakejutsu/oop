#ifndef MODELCREATORSOLUTION_H
#define MODELCREATORSOLUTION_H

#include "modelcreator.h"

class ModelCreatorSolution
{
public:
    ModelCreatorSolution();

    virtual std::shared_ptr<ModelCreator> getModelCreatorForExtension(const std::string &filename);
};

#endif // MODELCREATORSOLUTION_H
