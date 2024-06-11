//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_SETNEWMAINCAMERACOMMAND_H
#define MODELVIEWER_SETNEWMAINCAMERACOMMAND_H

#include "basecommand.h"

class SetNewMainCameraCommand : public BaseCommand {
public:
    SetNewMainCameraCommand(int cameraId);
    virtual void execute() override;
private:
    int cameraId;
};


#endif //MODELVIEWER_SETNEWMAINCAMERACOMMAND_H
