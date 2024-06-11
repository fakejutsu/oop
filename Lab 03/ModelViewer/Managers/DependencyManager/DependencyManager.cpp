//
// Created by Кирилл Воробьев on 05.06.2024.
//

#include "DependencyManager.h"


void DependencyManager::setCarcassDirectorSolution(std::shared_ptr<CarcassCreatorSolution> solution) {
    carcassDirectorSolution = std::move(solution);
}

std::shared_ptr<CarcassCreatorSolution> DependencyManager::getCarcassDirectorSolution() {
    return carcassDirectorSolution;
}

void DependencyManager::setSourceSolution(std::shared_ptr<CarcassSourceSolution> solution) {
    sourceSolution = std::move(solution);
}

std::shared_ptr<CarcassSourceSolution> DependencyManager::getSourceSolution() {
    return sourceSolution;
}

DependencyManager::DependencyManager() {

}
