#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "basecommand.h"
class UndoCommand : public BaseCommand
{
public:
    UndoCommand();
    virtual void execute() override;
};

#endif // UNDOCOMMAND_H
