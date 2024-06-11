#ifndef EDGEDATA_H
#define EDGEDATA_H

#include "point3d.h"
#include "TransformHelper.h"

struct EdgeData
{
public:
    EdgeData();
    EdgeData(Point3dForm f, Point3dForm s)
    {
        first = {f.x, f.y, f.z, 1};
        second = {s.x, s.y, s.z, 1};
    }

    Point4dForm first;
    Point4dForm second;
};

#endif // EDGEDATA_H
