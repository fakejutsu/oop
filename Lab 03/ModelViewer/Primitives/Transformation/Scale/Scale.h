//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_SCALE_H
#define MODELVIEWER_SCALE_H

#include "BaseTransformation.h"


class Scale : public BaseTransformation {
public:
    Scale(double x, double y, double z);
    Scale();
    Scale operator+(const Scale &other);
    Scale & operator+=(const Scale &other);
};


#endif //MODELVIEWER_SCALE_H
