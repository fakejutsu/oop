#ifndef UICREATOR_H
#define UICREATOR_H

#include "drawsceneinneradapter.h"
#include <memory>

#include <concepts>


class DrawSceneCreator
{
public:
    DrawSceneCreator() = default;

    virtual std::shared_ptr<DrawSceneAdapter> createDrawScene() const = 0;
};

#endif // UICREATOR_H
