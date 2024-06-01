#ifndef MOVECAMERACOMMAND_H
#define MOVECAMERACOMMAND_H

#include <CameraCommand.h>


class MoveCameraCommand : public CameraCommand
{
public:
    MoveCameraCommand(int cameraId, double dx, double dy, double dz);
    virtual void execute() override;

protected:
    int cameraId;
    double dx;
    double dy;
    double dz;
};

#endif // MOVECAMERACOMMAND_H
