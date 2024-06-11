//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "Scale.h"

Scale & Scale::operator+=(const Scale &other) {
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;

    return *this;
}

Scale Scale::operator+(const Scale &other) {
    return {this->x * other.x, this->y * other.y, this->z * other.z};
}

Scale::Scale(double x, double y, double z) : BaseTransformation(x, y, z) {

}

Scale::Scale() {
    x = 1;
    y = 1;
    z = 1;
}
