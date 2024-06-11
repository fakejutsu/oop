//
// Created by Кирилл Воробьев on 10.06.2024.
//

#include "GroupModelCommand.h"
#include "scenemanager.h"
#include <memory>

GroupModelCommand::GroupModelCommand(std::shared_ptr<std::vector<int>> v) : v(v)
{

}

void GroupModelCommand::execute() {
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->compositeFromObjects(*v);
}
