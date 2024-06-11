//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_DEPENDENCYMANAGER_H
#define MODELVIEWER_DEPENDENCYMANAGER_H

#include "basemanager.h"
#include "CarcassCreatorSolution.h"
#include "CarcassModelDirector.h"
#include <memory>

class DependencyManager : public  BaseManager{

public:
    void setCarcassDirectorSolution(std::shared_ptr<CarcassCreatorSolution> solution);
    std::shared_ptr<CarcassCreatorSolution> getCarcassDirectorSolution();
    void setSourceSolution(std::shared_ptr<CarcassSourceSolution> solution);
    std::shared_ptr<CarcassSourceSolution> getSourceSolution();

    DependencyManager(const DependencyManager &create) = delete;
    DependencyManager & operator=(const DependencyManager &) = delete;
protected:
    DependencyManager();

    std::shared_ptr<CarcassCreatorSolution> carcassDirectorSolution = nullptr;
    std::shared_ptr<CarcassSourceSolution> sourceSolution = nullptr;

};


#endif //MODELVIEWER_DEPENDENCYMANAGER_H
