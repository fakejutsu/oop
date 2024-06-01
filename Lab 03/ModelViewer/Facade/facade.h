#ifndef FACADE_H
#define FACADE_H

#include "basecommand.h"
#include <memory>

class Facade
{
public:
    Facade();

    void execute(std::shared_ptr<BaseCommand> command);

private:

};

#endif // FACADE_H
