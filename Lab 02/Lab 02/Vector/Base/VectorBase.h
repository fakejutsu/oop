#ifndef VECTOR_BASE_H
#define VECTOR_BASE_H

class VectorBase
{

private:
    
public:
    virtual bool IsEmpty() const = 0;
    virtual ~VectorBase() = default;
};

#endif