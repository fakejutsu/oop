#include "loadmanager.h"
#include "filereader.h"
#include "uifactorysolution.h"

LoadManager::LoadManager() {}

std::shared_ptr<ModelObject> LoadManager::loadModelFromFile()
{
    auto uiCreator = UIFactorySolution::CreateFactory();
    auto fileExplorer = uiCreator->createFileLoader();

    auto filename = std::make_shared<FileReader>(fileExplorer->getSelectedFileName());

    //auto director = std::make_shared<>

}
