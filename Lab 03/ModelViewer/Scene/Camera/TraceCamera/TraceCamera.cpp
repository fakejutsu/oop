//
// Created by Кирилл Воробьев on 01.06.2024.
//

#include "TraceCamera.h"
#include "QDebug"
#include "TransformationData.h"



void TraceCamera::accept(VisitorBase &v) {
    return v.visit(*this);
}

std::string TraceCamera::objectName() {
    return "Луч-камера";
}


TraceCamera::~TraceCamera() {
    qDebug() << "trace";
}

TraceCamera::TraceCamera() {

}

Point3dForm TraceCamera::transformPointToCameraView(Point4dForm point) {
    double fovl = this->getPos().z;
    double persp_coeff = (1600 / point.z);
    double resx = persp_coeff * point.x;
    double resy = persp_coeff * point.y;

    return {resx, resy, 0};
}

double TraceCamera::shadyExpFunc(double x) {
    if (x >= 1)
        return x;

    return exp((x - 1) / 2.71828);
}
