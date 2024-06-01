#include "facade.h"
#include <memory>

Facade::Facade() {}

void Facade::execute(std::shared_ptr<BaseCommand> command)
{
    command->execute();
}
