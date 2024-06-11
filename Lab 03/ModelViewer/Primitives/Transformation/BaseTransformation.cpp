//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "BaseTransformation.h"

BaseTransformation::BaseTransformation(double x, double y, double z) : x(x), y(y), z(z) {
}

BaseTransformation::operator Point3dForm() const {
    return {x, y, z};
}
