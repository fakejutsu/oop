//
// Created by Кирилл Воробьев on 01.06.2024.
//

#ifndef MODELVIEWER_TRACECAMERA_H
#define MODELVIEWER_TRACECAMERA_H

#include "cameraobject.h"

class TraceCamera : public CameraObject {
    friend VisitorBase;
public:
    virtual ~TraceCamera() = default;
    virtual void accept(VisitorBase &v) override;
protected:
    Point3d tracePoint;
};


#endif //MODELVIEWER_TRACECAMERA_H
