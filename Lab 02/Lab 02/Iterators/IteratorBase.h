//
// Created by sneki on 24.04.24.
//

#ifndef ITERATORBASE_H
#define ITERATORBASE_H

class IteratorBase
{
public:
    virtual ~IteratorBase() = 0;

protected:
    int index = 0;
    int size = 0;
};

IteratorBase::~IteratorBase() = default;

#endif //ITERATORBASE_H
