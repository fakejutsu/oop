#ifndef SCALEMODELCOMMAND_H
#define SCALEMODELCOMMAND_H

#include "modelcommand.h"
#include "point3d.h"
class ScaleModelCommand : public ModelCommand
{
public:
    ScaleModelCommand(int modelId, double sx, double sy, double sz);
    virtual void execute() override;


protected:
    double sx;
    double sy;
    double sz;

};



#endif // SCALEMODELCOMMAND_H
