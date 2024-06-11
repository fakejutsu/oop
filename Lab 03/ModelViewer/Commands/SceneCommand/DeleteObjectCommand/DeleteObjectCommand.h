//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_DELETEOBJECTCOMMAND_H
#define MODELVIEWER_DELETEOBJECTCOMMAND_H

#include "basecommand.h"

class DeleteObjectCommand : public BaseCommand {
public:
    DeleteObjectCommand(int objId);
    virtual void execute() override;
private:
    int objId;
};


#endif //MODELVIEWER_DELETEOBJECTCOMMAND_H
