//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_CARCASSCREATORSOLUTION_H
#define MODELVIEWER_CARCASSCREATORSOLUTION_H

#include <memory>
#include "CarcassModelBuilder.h"
#include "CarcassModelDirector.h"
#include "AbsCorrectModelSource.h"
#include "FileReader.h"

#include <map>


class CreateCarcassCreator
{
public:
    template<typename T>
    static std::unique_ptr<CarcassModelCreator> createCarcassCreator(std::shared_ptr<FileReader> src)
    {
        return std::make_unique<T>(src);
    }
};

class CarcassCreatorSolution
{
public:
    using CarcassCreatorMaker = std::unique_ptr<CarcassModelCreator>(&)(std::shared_ptr<FileReader> src);
    using DependencyLinking = std::map<std::string, CarcassCreatorMaker>;

    CarcassCreatorSolution() = default;
    CarcassCreatorSolution(std::initializer_list<std::pair<std::string, CarcassCreatorMaker>> dependencyLink);

    bool registrate(const std::string& extension, CarcassCreatorMaker creator);
    bool registered(const std::string& extension);

    std::unique_ptr<CarcassModelCreator> create(const std::string& extension, std::shared_ptr<FileReader> src);

    static std::shared_ptr<CarcassCreatorSolution> makeSolution(std::initializer_list<std::pair<std::string, CarcassCreatorMaker>> dependencyLink)
    {
        return std::shared_ptr<CarcassCreatorSolution>(new CarcassCreatorSolution(dependencyLink));
    }

private:
    DependencyLinking dependencies;
};



class CreateCarcassSourceCreator
{
public:
    template<typename T>
    static std::shared_ptr<AbsCarcassModelSource> createSourceCreator(std::string path)
    {
        return std::make_shared<T>(path);
    }
};


class CarcassSourceSolution
{
public:
    using SourceCreatorMaker = std::shared_ptr<AbsCarcassModelSource>(&)(std::string path);
    using DependencyLinking = std::map<std::string, SourceCreatorMaker>;

    CarcassSourceSolution() = default;
    CarcassSourceSolution(std::initializer_list<std::pair<std::string, SourceCreatorMaker>> dependencyLink);

    bool registrate(std::string extension, SourceCreatorMaker creator);
    bool registered(std::string extension);

    std::shared_ptr<AbsCarcassModelSource> create(std::string extension, std::string path);

    static std::shared_ptr<CarcassSourceSolution> makeSolution(std::initializer_list<std::pair<std::string, SourceCreatorMaker>> dependencyLink)
    {
        return std::shared_ptr<CarcassSourceSolution>(new CarcassSourceSolution(dependencyLink));
    }

private:
    DependencyLinking dependencies;
};

#endif //MODELVIEWER_CARCASSCREATORSOLUTION_H
