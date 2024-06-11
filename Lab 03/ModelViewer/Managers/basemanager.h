#ifndef BASEMANAGER_H
#define BASEMANAGER_H

class BaseManager
{
public:
    BaseManager(const BaseManager &create) = delete;
    BaseManager & operator=(const BaseManager &) = delete;
protected:
    BaseManager();

};

#endif // BASEMANAGER_H
