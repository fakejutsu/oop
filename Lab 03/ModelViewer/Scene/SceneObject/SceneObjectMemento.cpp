//
// Created by Кирилл Воробьев on 05.06.2024.
//

#include "SceneObjectMemento.h"

SceneObjectMemento::SceneObjectMemento(std::shared_ptr<MementoData> data) {
    this->memento = data;
}

std::shared_ptr<MementoData> SceneObjectMemento::getMemento() {
    return memento;
}
