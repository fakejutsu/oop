//
// Created by sneki on 24.04.24.
//

#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H

#include "IteratorBase.h"
#include "../Vector/VectorItemConcept.h"
#include "../Exceptions/InvalidIteratorException.h"
#include "../Concepts/Concepts.hpp"

template<RandomAccess T>
class ConstIterator : public IteratorBase
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = int;

    ConstIterator() = default;
    ConstIterator(ConstIterator<T> const &) noexcept;
    explicit ConstIterator(const Vector<T>&) noexcept;
    ConstIterator(std::shared_ptr<T[]> const& dataPtr, int size) noexcept;

    ~ConstIterator() = default;

    const T& operator *();
    const T* operator->();
    const T& operator[](const int offset);

    operator bool() const noexcept;

    ConstIterator<T>& operator++();
    ConstIterator<T> operator++(int);

    ConstIterator<T>& operator--();
    ConstIterator<T> operator--(int);

    template<IteratorChangeStep U>
    ConstIterator<T>& operator+=(U val);

    template<IteratorChangeStep U>
    ConstIterator<T> operator+(U number);

    template<IteratorChangeStep U>
    ConstIterator<T>& operator-=(U number);

    template<IteratorChangeStep U>
    ConstIterator<T> operator-(U number);



    auto operator<=>(const ConstIterator<T> const& second) const noexcept;
    bool operator>(const ConstIterator<T> const& second) const noexcept;
    bool operator<(const ConstIterator<T> const& second) const noexcept;
    bool operator==(const ConstIterator<T> const& second) const noexcept;

protected:
    T* GetPtr() const;

    void CheckExpired(int line);
    void CheckRange(int line, int indexToCheck);

private:
    std::weak_ptr<T[]> dataPtr;
};

#endif //ITERATOR_H

template<RandomAccess T>
inline const T& ConstIterator<T>::operator[](const int offset)
{
    CheckRange(__LINE__, this->index + offset);

    return this->GetPtr()[offset];
}

template<RandomAccess T>
inline ConstIterator<T>::operator bool() const noexcept
{
    return !(dataPtr.expired || dataPtr == nullptr);
}

template<RandomAccess T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
    ++this->index;
    return *this;
}

template<RandomAccess T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
    ConstIterator<T> old(*this);
    ++(*this);

    return old;
}


template<RandomAccess T>
template<IteratorChangeStep U>
inline ConstIterator<T>& ConstIterator<T>::operator+=(U number)
{
    this->index += number;
    return *this;
}

template<RandomAccess T>
template<IteratorChangeStep U>
inline ConstIterator<T> ConstIterator<T>::operator+(U number)
{
    ConstIterator<T> it(*this);
    it += number;

    return it;
}

template<RandomAccess T>
ConstIterator<T>& ConstIterator<T>::operator--()
{
    --this->index;
    return *this;
}

template<RandomAccess T>
ConstIterator<T> ConstIterator<T>::operator--(int)
{
    ConstIterator<T> old(*this);
    --(*this);

    return old;
}


template<RandomAccess T>
template<IteratorChangeStep U>
inline ConstIterator<T>& ConstIterator<T>::operator-=(U number)
{
    this->index -= number;
    return *this;
}

template<RandomAccess T>
template<IteratorChangeStep U>
ConstIterator<T> ConstIterator<T>::operator-(U number)
{
    ConstIterator<T> res(*this);
    res.index -= number;

    return res;
}

template<RandomAccess T>
inline T* ConstIterator<T>::GetPtr() const
{
    auto dataShared = this->dataPtr.lock();

    return dataShared.get() + this->index;
}

template<RandomAccess T>
inline void ConstIterator<T>::CheckExpired(int line)
{
    if (this->dataPtr.expired())
    {
        throw InvalidIteratorException(__FILE__, line, "Iterator data no longer exists");
    }
}

template<RandomAccess T>
inline void ConstIterator<T>::CheckRange(int line, int indexToCheck)
{
    if (indexToCheck >= this->size)
    {
        throw InvalidIteratorException(__FILE__, line, "Iterator Index Out Of Range");
    }
}

template<RandomAccess T>
inline auto ConstIterator<T>::operator<=>(const ConstIterator<T> const& second) const noexcept
{
    return this->index <=> second.index;
}


template<RandomAccess T>
inline ConstIterator<T>::ConstIterator(ConstIterator<T>const& it) noexcept
{
    this->dataPtr = it.dataPtr;
    this->index = it.index;
    this->size = it.size;
}

template<RandomAccess T>
inline ConstIterator<T>::ConstIterator(Vector<T> const & v) noexcept : ConstIterator<T>(v.cbegin())
{
}

template<RandomAccess T>
inline ConstIterator<T>::ConstIterator(std::shared_ptr<T[]> const& dataPtr, int size) noexcept
{
    this->dataPtr = dataPtr;
    this->index = 0;
    this->size = size;
}

template<RandomAccess T>
inline const T& ConstIterator<T>::operator*()
{
    CheckExpired(__LINE__);
    CheckRange(__LINE__, this->index);

    return *GetPtr();
}

template<RandomAccess T>
inline const T* ConstIterator<T>::operator->()
{
    CheckExpired(__LINE__);
    CheckRange(__LINE__, this->index);

    return GetPtr();
}



template<RandomAccess T>
inline bool ConstIterator<T>::operator>(const ConstIterator<T> const& second) const noexcept
{
    return this->index > second.index;
}


template<RandomAccess T>
inline bool ConstIterator<T>::operator<(const ConstIterator<T> const& second) const noexcept
{
    return this->index > second.index;
}


template<RandomAccess T>
inline bool ConstIterator<T>::operator==(const ConstIterator<T> const& second) const noexcept
{
    return this->index == second.index;
}