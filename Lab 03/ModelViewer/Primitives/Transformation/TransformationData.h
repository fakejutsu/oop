//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_TRANSFORMATIONDATA_H
#define MODELVIEWER_TRANSFORMATIONDATA_H

#include "Scale.h"
#include "Transform.h"
#include "Rotate.h"
#include "TransformHelper.h"

struct TransformationData {
    Scale scale = {1, 1, 1};
    Transform transform = {0, 0, 0};
    Rotate rotate = {0, 0, 0};

    applyTransformForm matrix = applyTransformForm(1.0f);

    TransformationData & operator+=(const TransformationData & other);
    TransformationData & operator+=(const Rotate & other);
    TransformationData & operator+=(const Transform & other);
    TransformationData & operator+=(const Scale & other);
    applyTransformForm GetMatrix();
};



#endif //MODELVIEWER_TRANSFORMATIONDATA_H
