//
// Created by Кирилл Воробьев on 03.06.2024.
//

#ifndef MODELVIEWER_QTSCENEADAPTER_H
#define MODELVIEWER_QTSCENEADAPTER_H

#include "drawsceneinneradapter.h"
#include <QGraphicsScene>
#include <memory>


class QtSceneAdapter : public DrawSceneInnerAdapter<QGraphicsScene> {
public:
    explicit QtSceneAdapter(QObject *parent = nullptr);
    ~QtSceneAdapter();
    explicit QtSceneAdapter(std::shared_ptr<QGraphicsScene> scene);

    virtual void clear() override;
    virtual void addLine(Point2d first, Point2d second) override;

    virtual std::shared_ptr<QGraphicsScene> getInner() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
};


#endif //MODELVIEWER_QTSCENEADAPTER_H
