#include "loadmanager.h"
#include "CarcassCreatorSolution.h"
#include "CarcassModelDirector.h"
#include "CarcassModelBuilder.h"
#include "managercreator.h"
#include "DependencyManager.h"
#include "scenemanager.h"
#include "ModelObjectFactory.h"
#include "CarcassObject.h"
#include "FileReader.h"
#include "FileReaderCreator.h"

LoadManager::LoadManager() {}


std::shared_ptr<ModelObject> LoadManager::loadModelFromFile(std::string &path)
{
    if (path == "")
    {
        return nullptr;
    }

    auto dependency = ManagerCreator<DependencyManager>::CreateManager();
    auto creatorSolution = dependency->getCarcassDirectorSolution();
    auto sourceSolution = dependency->getSourceSolution();

    if (creatorSolution == nullptr)
    {
        throw std::runtime_error("No dependencies");
    }

    std:: string ext = getFileExtension(path);

    try {
        auto readerCreator = std::make_shared<FileReaderFactory<FileReader>>();
        auto reader = readerCreator->create(path);

        auto modelCreator = creatorSolution->create(ext, reader);
//-------------------------------------
        std::shared_ptr<ModelAbstraction> model = modelCreator->create();
        auto creator = std::make_shared<ModelObjectFactory<CarcassObject>>();
        auto object = creator->createModelObject(model);

        auto sceneManager = ManagerCreator<SceneManager>::CreateManager();

        sceneManager->addObject(object);
        sceneManager->drawScene();

        return object;
    }
    catch (std::exception ex)
    {
        throw ex;
    }
}

std::string LoadManager::getFileExtension(std::string &path) {
    int dotPos = path.find_last_of('.');
    if (dotPos == std::string::npos || dotPos == path.size() - 1)
    {
        return "";
    }

    return path.substr(dotPos + 1, path.size() - dotPos - 1);
}

