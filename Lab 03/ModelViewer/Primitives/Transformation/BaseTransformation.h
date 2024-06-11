//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_BASETRANSFORMATION_H
#define MODELVIEWER_BASETRANSFORMATION_H

#include "TransformHelper.h"

class BaseTransformation {
public:
    BaseTransformation(double x, double y, double z);
    BaseTransformation() = default;

    operator Point3dForm() const;

protected:
    double x = 1,
    y = 1,
    z = 1;
};


#endif //MODELVIEWER_BASETRANSFORMATION_H
