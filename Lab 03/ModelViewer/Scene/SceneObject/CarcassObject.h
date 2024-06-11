//
// Created by Кирилл Воробьев on 06.06.2024.
//

#ifndef MODELVIEWER_CARCASSOBJECT_H
#define MODELVIEWER_CARCASSOBJECT_H


#include "modelobject.h"
#include <memory>
#include "CarcassModelEntity.h"


class CarcassObject : public ModelObject {
public:
    friend ModelObjectEntityAdapter;
    CarcassObject(std::shared_ptr<ModelAbstraction> modelEntity);
    virtual ~CarcassObject() override;
    virtual void accept(VisitorBase &v) override;
    virtual std::string objectName() override;
    virtual std::shared_ptr<ModelAbstraction> getEntity() override;

protected:
    std::shared_ptr<ModelAbstraction> entity;
};


#endif //MODELVIEWER_CARCASSOBJECT_H
