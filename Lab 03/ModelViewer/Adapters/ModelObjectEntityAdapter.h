//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_MODELOBJECTENTITYADAPTER_H
#define MODELVIEWER_MODELOBJECTENTITYADAPTER_H

#include "modelobject.h"

class ModelObjectEntityAdapter {
public:
    ModelObjectEntityAdapter(ModelObject &adaptee);
    void installTheEntity(std::shared_ptr<ModelAbstraction> entity);
    std::shared_ptr<ModelAbstraction> getEntity();
protected:
    ModelObject & adaptee;
};


#endif //MODELVIEWER_MODELOBJECTENTITYADAPTER_H
