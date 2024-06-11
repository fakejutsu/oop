#ifndef MOVEMODELCOMMAND_H
#define MOVEMODELCOMMAND_H

#include <ModelCommand.h>


class MoveModelCommand : public ModelCommand
{
public:
    MoveModelCommand(int modelId, double dx, double dy, double dz);
    virtual void execute() override;

protected:
    double dx;
    double dy;
    double dz;
};

#endif // MOVEMODELCOMMAND_H
