#ifndef MANAGERCREATOR_H
#define MANAGERCREATOR_H

#include <memory>

template <typename T>
class ManagerCreator
{
public:
    ManagerCreator() = default;

    static std::shared_ptr<T> CreateManager();

protected:
    static std::shared_ptr<T> instance;

private:
    static void createInstance()
    {
        instance = std::make_shared<T>();
    }

};

template<typename T>
std::shared_ptr<T> ManagerCreator<T>::CreateManager()
{
    if (instance == nullptr)
    {
        createInstance();
    }

    return instance;
}

template<typename T>
std::shared_ptr<T> ManagerCreator<T>::instance = nullptr;


#endif // MANAGERCREATOR_H
