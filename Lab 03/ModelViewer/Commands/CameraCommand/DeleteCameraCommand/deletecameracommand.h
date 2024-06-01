#ifndef DELETECAMERACOMMAND_H
#define DELETECAMERACOMMAND_H

#include <CameraCommand.h>


class DeleteCameraCommand : public CameraCommand
{
public:
    DeleteCameraCommand(int cameraId);
    virtual void execute() override;

protected:
    int cameraId;

};

#endif // DELETECAMERACOMMAND_H
