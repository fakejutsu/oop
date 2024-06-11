//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "Transform.h"


Transform & Transform::operator+=(const Transform &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;

    return *this;
}

Transform Transform::operator+(const Transform &other) {
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}

Transform::Transform(double x, double y, double z) : BaseTransformation(x, y, z) {

}

Transform::Transform() {
    x = 0;
    y = 0;
    z = 0;
}
