//
// Created by Кирилл Воробьев on 01.06.2024.
//

#include "SceneTextListCommand.h"
#include "scenemanager.h"
#include "managercreator.h"

void SceneTextListCommand::execute() {
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    result = sceneManager->sceneTextList();
}

SceneTextListCommand::SceneTextListCommand(std::string &result) : result(result) {

}
