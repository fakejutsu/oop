#include "transformmatrix.h"


TransformMatrix::TransformMatrix() {
    moveMatrix = matrixType::IdentityMatrix();
    rotateMatrix = matrixType::IdentityMatrix();
    scaleMatrix = matrixType::IdentityMatrix();
}

void TransformMatrix::applyTransorm(const Point3d transformPoint) {


    refreshResultMatrix();
}

void TransformMatrix::applyRotate(double ox, double oy, double oz) {


    refreshResultMatrix();
}

void TransformMatrix::applyScale(double ox, double oy, double oz) {


    refreshResultMatrix();
}

 std::shared_ptr<matrixType> TransformMatrix::getResultMatrix() {
    return resultMatrix;
}

void TransformMatrix::refreshResultMatrix() {

}


