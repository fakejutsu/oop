//
// Created by Кирилл Воробьев on 04.06.2024.
//

#include "DeleteObjectCommand.h"
#include "managercreator.h"
#include "scenemanager.h"

DeleteObjectCommand::DeleteObjectCommand(int objId) : objId(objId) {

}

void DeleteObjectCommand::execute() {
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->removeObjectById(objId);
}
