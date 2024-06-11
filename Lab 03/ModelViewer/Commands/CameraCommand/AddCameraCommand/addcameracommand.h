#ifndef ADDCAMERACOMMAND_H
#define ADDCAMERACOMMAND_H

#include <CameraCommand.h>


class AddCameraCommand : public CameraCommand
{
public:
    AddCameraCommand();

    virtual void execute() override;
};

#endif // ADDCAMERACOMMAND_H
