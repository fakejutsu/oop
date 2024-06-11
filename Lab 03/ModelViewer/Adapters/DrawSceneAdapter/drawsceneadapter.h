//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_DRAWSCENEADAPTER_H
#define MODELVIEWER_DRAWSCENEADAPTER_H


#include "Point2d.h"

class DrawSceneAdapter {
public:
    DrawSceneAdapter() = default;

    virtual void clear() = 0;
    virtual void addLine(Point2d first, Point2d second) = 0;
};


#endif //MODELVIEWER_DRAWSCENEADAPTER_H
