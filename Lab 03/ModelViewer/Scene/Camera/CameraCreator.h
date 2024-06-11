//
// Created by Кирилл Воробьев on 07.06.2024.
//

#ifndef MODELVIEWER_CAMERACREATOR_H
#define MODELVIEWER_CAMERACREATOR_H

#include <memory>
#include "cameraobject.h"

class CameraCreator {
public:
    virtual ~CameraCreator() = default;
    virtual std::shared_ptr<CameraObject> create() = 0;
};

template <typename T>
class CameraFactory : public CameraCreator
{
public:
    CameraFactory() = default;
    virtual std::shared_ptr<CameraObject> create() override
    {
        return std::make_shared<T>();
    }
};


#endif //MODELVIEWER_CAMERACREATOR_H
