#ifndef TRANSFORMMATRIX_H
#define TRANSFORMMATRIX_H

#include "matrixbase.h"
#include "point3d.h"

using matrixType = MatrixBase<double, 4, 4>;

class TransformMatrix final
{

public:
    TransformMatrix();

    void applyRotate(double ox, double oy, double oz);
    void applyTransorm(Point3d transformPoint);
    void applyScale(double ox, double oy, double oz);

    std::shared_ptr<matrixType> getResultMatrix();

private:

    void refreshResultMatrix();

    std::shared_ptr<matrixType> moveMatrix;
    std::shared_ptr<matrixType> rotateMatrix;
    std::shared_ptr<matrixType> scaleMatrix;

    std::shared_ptr<matrixType> resultMatrix;
};

#endif // TRANSFORMMATRIX_H
