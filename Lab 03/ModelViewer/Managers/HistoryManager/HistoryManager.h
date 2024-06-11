//
// Created by Кирилл Воробьев on 05.06.2024.
//

#ifndef MODELVIEWER_HISTORYMANAGER_H
#define MODELVIEWER_HISTORYMANAGER_H

#include "basemanager.h"
#include <stack>
#include "SceneObjectMemento.h"
#include "sceneobject.h"
#include <memory>

using pairType = std::pair<std::weak_ptr<SceneObject>, std::shared_ptr<SceneObjectMemento>>;
using historyCollection = std::stack<pairType>;

class HistoryManager : public BaseManager {
public:
    virtual void pushMemento(std::weak_ptr<SceneObject>, std::shared_ptr<SceneObjectMemento> memento);
    virtual void undo();
    virtual pairType popMemento();

    HistoryManager(const HistoryManager &m) = delete;
    HistoryManager & operator=(const HistoryManager &) = delete;
protected:
    HistoryManager();
private:
    void refresh();
    const int historyMaxSize = 30;
    std::shared_ptr<historyCollection> history;
};


#endif //MODELVIEWER_HISTORYMANAGER_H
