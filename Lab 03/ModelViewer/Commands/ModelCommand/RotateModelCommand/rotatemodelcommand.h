#ifndef ROTATEMODELCOMMAND_H
#define ROTATEMODELCOMMAND_H

#include "modelcommand.h"
#include "point3d.h"
class RotateModelCommand : public ModelCommand
{
public:
    RotateModelCommand(int modelId, double ox, double oy, double oz);
    virtual void execute() override;

protected:
    double ox;
    double oy;
    double oz;
};

#endif // ROTATEMODELCOMMAND_H
