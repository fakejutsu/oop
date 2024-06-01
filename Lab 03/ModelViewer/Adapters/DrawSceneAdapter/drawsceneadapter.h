#ifndef DRAWSCENEADAPTER_H
#define DRAWSCENEADAPTER_H

#include "penadapter.h"
#include <memory>

class DrawSceneAdapter
{
public:
    DrawSceneAdapter();

    virtual void clear() = 0;
    virtual void addLine() = 0;

    virtual void setPen(std::shared_ptr<PenAdapter> pen);

protected:
    std::shared_ptr<PenAdapter> pen;
};

#endif // DRAWSCENEADAPTER_H
