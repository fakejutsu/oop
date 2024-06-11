#ifndef ROTATECAMERACOMMAND_H
#define ROTATECAMERACOMMAND_H

#include "point3d.h"
#include <cameracommand.h>


class RotateCameraCommand : public CameraCommand
{
public:
    RotateCameraCommand(double ox, double oy, double oz);
    virtual void execute() override;

protected:
    double ox;
    double oy;
    double oz;
};

#endif // ROTATECAMERACOMMAND_H
