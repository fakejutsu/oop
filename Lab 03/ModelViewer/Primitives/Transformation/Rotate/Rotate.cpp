//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "Rotate.h"


Rotate & Rotate::operator+=(const Rotate &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;

    return *this;
}

Rotate Rotate::operator+(const Rotate &other) {
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}

Rotate::Rotate(double x, double y, double z) : BaseTransformation(x, y, z) {

}

Rotate::Rotate() {
    x = 0;
    y = 0;
    z = 0;
}
