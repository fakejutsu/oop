//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_TRANSFORM_H
#define MODELVIEWER_TRANSFORM_H

#include "BaseTransformation.h"

class Transform : public BaseTransformation {
public:
    Transform(double x, double y, double z);
    Transform();
    Transform operator+(const Transform &other);
    Transform & operator+=(const Transform &other);
};


#endif //MODELVIEWER_TRANSFORM_H
