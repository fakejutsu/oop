//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_MODELABSTRACTION_H
#define MODELVIEWER_MODELABSTRACTION_H

#include <memory>
#include "ModelImplementor.h"

class ModelEntityVisitorBase;

class ModelAbstraction {

protected:
public:
    virtual ~ModelAbstraction() = default;
    virtual void accept(ModelEntityVisitorBase &visitor) = 0;
};


#endif //MODELVIEWER_MODELABSTRACTION_H
