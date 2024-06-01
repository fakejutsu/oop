#ifndef EDGESMODELDIRECTOR_H
#define EDGESMODELDIRECTOR_H

#include "modeldirector.h"
class EdgesModelDirector : public ModelDirector
{
public:
    EdgesModelDirector();

    virtual std::shared_ptr<ModelObject> createModel() ;
};

#endif // EDGESMODELDIRECTOR_H
