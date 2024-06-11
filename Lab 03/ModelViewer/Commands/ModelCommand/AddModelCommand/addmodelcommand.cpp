#include "addmodelcommand.h"
#include "loadmanager.h"
#include "managercreator.h"
#include "AbsCorrectModelSource.h"

AddModelCommand::AddModelCommand(std::string & path) : path(path) {}

void AddModelCommand::execute()
{
    auto loadManager = ManagerCreator<LoadManager>::CreateManager();
    loadManager->loadModelFromFile(path);
}
