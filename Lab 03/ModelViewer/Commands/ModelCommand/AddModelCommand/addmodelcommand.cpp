#include "addmodelcommand.h"
#include "loadmanager.h"
#include "managercreator.h"

AddModelCommand::AddModelCommand() {}

void AddModelCommand::execute()
{
    auto loadManager = ManagerCreator<LoadManager>::CreateManager();
    loadManager->loadModelFromFile();
}
