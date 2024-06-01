#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include "basecommand.h"
class ModelCommand : public BaseCommand
{
public:
    ModelCommand(int modelId);
protected:
    int modelId;
};

#endif // MODELCOMMAND_H
