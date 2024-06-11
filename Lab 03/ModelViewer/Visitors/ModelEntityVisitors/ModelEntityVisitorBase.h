//
// Created by Кирилл Воробьев on 04.06.2024.
//

#ifndef MODELVIEWER_MODELENTITYVISITORBASE_H
#define MODELVIEWER_MODELENTITYVISITORBASE_H

class CarcassModelEntity;

class ModelEntityVisitorBase {
public:
    ModelEntityVisitorBase() = default;
    virtual ~ModelEntityVisitorBase() = default;

    virtual void visit(CarcassModelEntity & model) = 0;
};


#endif //MODELVIEWER_MODELENTITYVISITORBASE_H
