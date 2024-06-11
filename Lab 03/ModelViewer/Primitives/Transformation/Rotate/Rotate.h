//
// Created by Кирилл Воробьев on 02.06.2024.
//

#ifndef MODELVIEWER_ROTATE_H
#define MODELVIEWER_ROTATE_H


#include "BaseTransformation.h"

class Rotate : public BaseTransformation {
public:
    Rotate();
    Rotate(double x, double y, double z);
    Rotate operator+(const Rotate &other);
    Rotate & operator+=(const Rotate &other);
};



#endif //MODELVIEWER_ROTATE_H
