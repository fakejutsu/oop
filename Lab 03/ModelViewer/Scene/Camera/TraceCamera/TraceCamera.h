//
// Created by Кирилл Воробьев on 01.06.2024.
//

#ifndef MODELVIEWER_TRACECAMERA_H
#define MODELVIEWER_TRACECAMERA_H

#include "cameraobject.h"
#include "basesceneiterator.h"

class RotateTraceCameraAdapter;
class VisitorBase;

class TraceCamera : public CameraObject {
    friend RotateTraceCameraAdapter;
public:
    TraceCamera();
    virtual ~TraceCamera();
    virtual void accept(VisitorBase &v) override;
    virtual std::string objectName() override;
    virtual Point3dForm transformPointToCameraView(Point4dForm point) override;


protected:
    double shadyExpFunc(double x);
};


#endif //MODELVIEWER_TRACECAMERA_H
