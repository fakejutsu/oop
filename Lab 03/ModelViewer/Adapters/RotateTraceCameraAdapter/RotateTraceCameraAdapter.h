//
// Created by Кирилл Воробьев on 01.06.2024.
//

#ifndef MODELVIEWER_ROTATETRACECAMERAADAPTER_H
#define MODELVIEWER_ROTATETRACECAMERAADAPTER_H

#include <memory>
#include "TraceCamera.h"
#include "TransformHelper.h"

class RotateTraceCameraAdapter {
public:

    explicit RotateTraceCameraAdapter(TraceCamera & camera);


private:
    TraceCamera & adaptee;
};


#endif //MODELVIEWER_ROTATETRACECAMERAADAPTER_H
