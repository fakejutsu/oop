#ifndef POINT3D_H
#define POINT3D_H

struct Point3d
{
public:
    Point3d();
    Point3d(double x, double y, double z);

    double x;
    double y;
    double z;



    Point3d operator-();
    double & operator[](int index);


};

#endif // POINT3D_H
