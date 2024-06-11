//
// Created by sneki on 24.04.24.
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include "IteratorBase.h"
#include "../Concepts/Concepts.hpp"
#include "../Exceptions/InvalidIteratorException.h"

template<VectorItemRequires T>
class Vector;

template<RandomAccess T>
class Iterator: public IteratorBase
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = const T;
    using pointer = T const *;
    using reference = const T &;
    using difference_type = int;

    Iterator() = default;
    Iterator(Iterator<T> const &) noexcept;
    Iterator(Vector<T> const &) noexcept;

    ~Iterator() = default;

    T &operator *();
    T *operator->();
    T &operator[](const int offset);

    operator bool() const noexcept;

    Iterator<T> & operator++();
    Iterator<T> operator++(int) ;

    Iterator<T>& operator--();
    Iterator<T> operator--(int);

    template<IteratorChangeStep U>
    Iterator<T> & operator+=(U val);

    template<IteratorChangeStep U>
    Iterator<T> operator+(U number);
    
    template<IteratorChangeStep U>
    Iterator<T> & operator-=(U number);

    template<IteratorChangeStep U>
    Iterator<T> operator-(U number);

    

    auto operator<=>(const Iterator<T> const& second) const noexcept;
    bool operator>(const Iterator<T> const& second) const noexcept;
    bool operator<(const Iterator<T> const& second) const noexcept;
    bool operator==(const Iterator<T> const& second) const noexcept;

protected:
    T* GetPtr() const;

    void CheckExpired(int line);
    void CheckRange(int line, int indexToCheck);

private:
    std::weak_ptr<T[]> dataPtr;
};

#endif //ITERATOR_H

template<RandomAccess T>
inline T& Iterator<T>::operator[](const int offset)
{
    CheckRange(__LINE__, this->index + offset);

    return this->GetPtr()[offset];
}

template<RandomAccess T>
inline Iterator<T>::operator bool() const noexcept
{
    return !(dataPtr.expired() || dataPtr.lock() == nullptr);
}

template<RandomAccess T>
Iterator<T>& Iterator<T>::operator++()
{
    ++this->index;
    return *this;
}

template<RandomAccess T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> old(*this);
    ++(*this);

    return old;
}


template<RandomAccess T>
template<IteratorChangeStep U>
Iterator<T> Iterator<T>::operator+(U number)
{
    Iterator<T> res(*this);
    res.index += number;

    return res;
}

template<RandomAccess T>
template<IteratorChangeStep U>
inline Iterator<T>& Iterator<T>::operator+=(U number)
{
    this->index += number;
    return *this;
}

template<RandomAccess T>
Iterator<T>& Iterator<T>::operator--()
{
    --this->index;
    return *this;
}

template<RandomAccess T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator<T> old(*this);
    --(*this);

    return old;
}


template<RandomAccess T>
template<IteratorChangeStep U>
inline Iterator<T>& Iterator<T>::operator-=(U number)
{
    this->index -= number;
    return *this;
}

template<RandomAccess T>
template<IteratorChangeStep U>
Iterator<T> Iterator<T>::operator-(U number)
{
    Iterator<T> res(*this);
    res.index -= number;

    return res;
}

template<RandomAccess T>
inline auto Iterator<T>::operator<=>(const Iterator<T> const& second) const noexcept
{
    return this->index <=> second.index;
}


template<RandomAccess T>
inline bool Iterator<T>::operator>(const Iterator<T> const& second) const noexcept
{
    return this->index > second.index;
}

template<RandomAccess T>
inline bool Iterator<T>::operator<(const Iterator<T> const& second) const noexcept
{
    return this->index < second.index;
}

template<RandomAccess T>
inline bool Iterator<T>::operator==(const Iterator<T> const& second) const noexcept
{
    return this->index == second.index;
}

template<RandomAccess T>
inline T* Iterator<T>::GetPtr() const
{
    auto dataShared = this->dataPtr.lock();

    return dataShared.get() + this->index;
}

template<RandomAccess T>
inline void Iterator<T>::CheckExpired(int line)
{
    if (this->dataPtr.expired())
    {
        throw InvalidIteratorException(__FILE__, line, "Iterator data no longer exists");
    }
}

template<RandomAccess T>
inline void Iterator<T>::CheckRange(int line, int indexToCheck)
{
    if (indexToCheck >= this->size)
    {
        throw InvalidIteratorException(__FILE__, line, "Iterator Index Out Of Range");
    }
}


template<RandomAccess T>
inline Iterator<T>::Iterator(Iterator<T>const &  it) noexcept
{
    this->dataPtr = it.dataPtr;
    this->index = it.index;
    this->size = it.size;
}

template<RandomAccess T>
inline Iterator<T>::Iterator(const Vector<T>& v) noexcept
{
    this->dataPtr = v.m_Data;
    this->size = v.Size();
    this->index = 0;
}

template<RandomAccess T>
inline T& Iterator<T>::operator*()
{
    CheckExpired(__LINE__);
    CheckRange(__LINE__, this->index);

    return *GetPtr();
}

template<RandomAccess T>
inline T* Iterator<T>::operator->()
{
    CheckExpired(__LINE__);
    CheckRange(__LINE__, this->index);

    return GetPtr();
}

