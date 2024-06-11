//
// Created by Кирилл Воробьев on 05.06.2024.
//

#include "HistoryManager.h"

HistoryManager::HistoryManager() {
    this->history = std::make_shared<historyCollection>();
}

void HistoryManager::pushMemento(std::weak_ptr<SceneObject> obj, std::shared_ptr<SceneObjectMemento> memento) {
    if (history->size() >= historyMaxSize)
    {
        refresh();
    }
    auto pair = pairType(obj, memento);
    this->history->push(pair);
}

pairType HistoryManager::popMemento() {
    auto ret = this->history->top();
    this->history->pop();

    return ret;
}

void HistoryManager::refresh()
{
    std::shared_ptr<historyCollection> tempReverse = std::make_shared<historyCollection>();
    for (int i = 0; i < history->size() / 2; ++i)
    {
        auto el = history->top();
        history->pop();
        tempReverse->push(el);
    }

    while (!history->empty())
    {
        history->pop();
    }

    while (!tempReverse->empty())
    {
        auto el = tempReverse->top();
        tempReverse->pop();
        history->push(el);
    }
}

void HistoryManager::undo() {
    if (this->history->empty())
        return;

    auto pr = popMemento();
    while (pr.first.expired() && !this->history->empty())
    {
        pr = popMemento();
    }

    if (!pr.first.expired())
    {
        auto obj = pr.first.lock();
        auto data = pr.second;

        obj->restoreMemento(data);
    }
}
