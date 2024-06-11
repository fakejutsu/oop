//
// Created by Кирилл Воробьев on 03.06.2024.
//

#include "QtSceneAdapter.h"
#include "QDebug"

void QtSceneAdapter::clear() {
 this->scene->clear();
}

void QtSceneAdapter::addLine(Point2d first, Point2d second) {
    QPointF f = QPointF(first.x, first.y);
    QPointF s = QPointF(second.x, second.y);

    this->scene->addLine(QLineF(f, s));
}

QtSceneAdapter::QtSceneAdapter(QObject *parent) {
    scene = std::make_shared<QGraphicsScene>(parent);
}

QtSceneAdapter::QtSceneAdapter(std::shared_ptr<QGraphicsScene> scene) {
    this->scene = scene;
}

QtSceneAdapter::~QtSceneAdapter() {
    qDebug() << "destruct";
}

std::shared_ptr<QGraphicsScene> QtSceneAdapter::getInner() {
    return this->scene;
}

