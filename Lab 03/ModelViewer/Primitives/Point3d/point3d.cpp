#include "point3d.h"

Point3d::Point3d() {
    x = 0;
    y = 0;
    z = 0;
}

Point3d Point3d::operator-() {
    return {-this->x, -this->y, -this->z};
}

Point3d::Point3d(double x, double y, double z)  : x(x), y(y), z(z){

}

double & Point3d::operator[](int index)
{
    if (index == 0)
    {
        return x;
    }
    else if (index == 1)
    {
        return y;
    }

    return z;
}