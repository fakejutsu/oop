//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_CARCASSMODELENTITY_H
#define MODELVIEWER_CARCASSMODELENTITY_H

#include "ModelAbstraction.h"
#include "ModelEntityVisitorBase.h"
#include "CarcassModelImplementor.h"

class CarcassModelEntity : public ModelAbstraction {
public:
    ~CarcassModelEntity() override;
    explicit CarcassModelEntity(std::shared_ptr<CarcassModelImplementor> implementor);
    virtual void accept(ModelEntityVisitorBase &visitor) override;
    virtual std::vector<EdgeData> getEdges();

protected:
    std::shared_ptr<CarcassModelImplementor> implementator;
};


#endif //MODELVIEWER_CARCASSMODELENTITY_H
