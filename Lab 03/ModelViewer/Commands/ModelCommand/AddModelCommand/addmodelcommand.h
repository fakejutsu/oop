#ifndef ADDMODELCOMMAND_H
#define ADDMODELCOMMAND_H

#include "string"
#include "basecommand.h"

class AddModelCommand : public BaseCommand
{
public:
    AddModelCommand(std::string &path);

    virtual void execute();
private:
    std::string path;
};

#endif // ADDMODELCOMMAND_H
