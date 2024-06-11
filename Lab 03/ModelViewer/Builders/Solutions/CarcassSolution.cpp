//
// Created by Кирилл Воробьев on 04.06.2024.
//

#include "CarcassCreatorSolution.h"
#include "CarcassEdgesModelBuilder.h"
#include "TextEdgesModelSource.h"
#include "CarcassModelCreator.h"


CarcassCreatorSolution::CarcassCreatorSolution(std::initializer_list<std::pair<std::string, CarcassCreatorMaker>> dependencyLink) {
    for (auto && it: dependencyLink)
    {
        this->registrate(it.first, it.second);
    }
}

bool CarcassCreatorSolution::registrate(const std::string& extension, CarcassCreatorMaker creator) {
    return dependencies.insert(DependencyLinking::value_type(extension, creator)).second;
}

bool CarcassCreatorSolution::registered(const std::string& extension) {
    return dependencies.erase(extension) == 1;
}

std::unique_ptr<CarcassModelCreator> CarcassCreatorSolution::create(const std::string& extension, std::shared_ptr<FileReader> src) {
    auto it = dependencies.find(extension);

    return it != dependencies.end() ? std::unique_ptr<CarcassModelCreator>(it->second(src)) : nullptr;
}




CarcassSourceSolution::CarcassSourceSolution(
        std::initializer_list<std::pair<std::string, SourceCreatorMaker>> dependencyLink) {
    for (auto && it: dependencyLink)
    {
        this->registrate(it.first, it.second);
    }
}

bool CarcassSourceSolution::registrate(std::string extension, SourceCreatorMaker creator) {
    return dependencies.insert(DependencyLinking::value_type(extension, creator)).second;
}

bool CarcassSourceSolution::registered(std::string extension) {
    return dependencies.erase(extension) == 1;
}

std::shared_ptr<AbsCarcassModelSource> CarcassSourceSolution::create(std::string extension, std::string path) {
    auto it = dependencies.find(extension);

    return it != dependencies.end() ? std::shared_ptr<AbsCarcassModelSource>(it->second(path)) : nullptr;
}
