#ifndef DRAWSCENEADAPTER_H
#define DRAWSCENEADAPTER_H

#include "Point2d.h"
#include <memory>
#include "drawsceneadapter.h"

template <typename InnerType>
class DrawSceneInnerAdapter : public DrawSceneAdapter
{
public:
    virtual std::shared_ptr<InnerType> getInner() {
        return scene;
    }

protected:
    std::shared_ptr<InnerType> scene;
};

#endif // DRAWSCENEADAPTER_H
