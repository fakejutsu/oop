//
// Created by Кирилл Воробьев on 04.06.2024.
//

#include "SetNewMainCameraCommand.h"
#include "managercreator.h"
#include "scenemanager.h"

void SetNewMainCameraCommand::execute() {
    auto sceneManager = ManagerCreator<SceneManager>::CreateManager();
    sceneManager->setMainCamera(cameraId);
}

SetNewMainCameraCommand::SetNewMainCameraCommand(int cameraId) : cameraId(cameraId) {

}
