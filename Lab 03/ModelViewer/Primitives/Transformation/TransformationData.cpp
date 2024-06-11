//
// Created by Кирилл Воробьев on 02.06.2024.
//

#include "TransformationData.h"

TransformationData &TransformationData::operator+=(const TransformationData &other) {
    *this += other.transform;
    *this += other.rotate;
    *this += other.scale;

    return *this;
}

TransformationData &TransformationData::operator+=(const Rotate &other) {
    this->rotate += other;

    this->matrix = TransformHelper::rotate(matrix, {other.operator Point3dForm()});

    return *this;
}

TransformationData &TransformationData::operator+=(const Transform &other) {
    this->transform += other;

    this->matrix = TransformHelper::translate(matrix, {other.operator Point3dForm()});

    return *this;
}

TransformationData &TransformationData::operator+=(const Scale &other) {
    this->scale += other;

    this->matrix = TransformHelper::scale(matrix, {other.operator Point3dForm()});

    return *this;
}

applyTransformForm TransformationData::GetMatrix() {
//    applyTransformForm id = applyTransformForm(1.0f);
//
//    applyTransformForm change = TransformHelper::rotate(id, rotate);
//    change = TransformHelper::translate(change, transform);
//    change = TransformHelper::scale(change, scale);
//    return change;

    return matrix;
}



