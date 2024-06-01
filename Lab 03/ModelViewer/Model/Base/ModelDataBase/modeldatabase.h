#ifndef MODELDATABASE_H
#define MODELDATABASE_H

#include "edgedataiterator.h"

class ModelDataBase
{
public:
    ModelDataBase();

    virtual ~ModelDataBase() = 0;

    virtual EdgeDataIterator begin() = 0;
};

#endif // MODELDATABASE_H
