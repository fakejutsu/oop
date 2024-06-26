//
// Created by sneki on 18.04.24.
//

#ifndef LAB_02_VECTOR_H
#define LAB_02_VECTOR_H

#include "Base/VectorBase.h"
#include "memory"
#include "../Exceptions/EmptyVectorException.h"
#include "../Exceptions/MemoryAllocException.h"
#include "../Exceptions/OperationInvalidParams.h"
#include "../Exceptions/ZeroDivException.h"
#include "../Iterators/Iterator.hpp"
#include "../Iterators/ConstIterator.hpp"
#include "../Concepts/Concepts.hpp"
#include <numeric>
#include <ranges>
#include <algorithm>
#include <tuple>
#include <vector>

template <typename T>
concept RangeConcept = requires (T t)
{
    t.begin(); t.end();
};


template <VectorItemRequires T>
class Vector : public VectorBase
{
	friend Iterator<T>;
	friend ConstIterator<T>;

private:
	int m_Size = 0;
	std::shared_ptr<T[]> m_Data = nullptr;



	void AllocSize(int size);

	template<VectorItemRequires U>
	void CheckZeroDiv(int line, Vector<U> const& vectorToCheck) const;

	template<VectorItemRequires U>
	void CheckZeroDiv(int line, U numberToCheck) const;

	void CheckLength(int line);
	void CheckRange(int line, int indexToCheck);

public:

    using value_type = T;
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;

	bool IsEmpty() const override;
	int Size() const noexcept;

#pragma region constructors

	Vector();

	explicit Vector(int length);

	Vector(const Vector& v);

	explicit Vector(Vector&& v);

	Vector(int length, std::shared_ptr<T[]> arr);

	Vector(int length, const T& fill);

	Vector(int length, T* arr);

	explicit Vector(const std::initializer_list<T> fromList);


    static Vector<T> UnitVector(int length);

#pragma endregion constructors

	~Vector() = default;

#pragma region operations


	template <VectorItemRequires U>
	decltype(auto) Sum(Vector<U> const& v2) const;

	template <VectorItemRequires U>
	decltype(auto) Mul(Vector<U> const& v2) const;

	template <VectorItemRequires U>
	decltype(auto) Div(Vector<U> const& v2) const;

	template <VectorItemRequires U>
	decltype(auto) Diff(Vector<U> const& v2) const;


	template <typename U>
	decltype(auto) ScalarProduct(const Vector<U>& v2) const;


	template <VectorItemRequires U>
	decltype(auto) operator +(const U& el);

	template <VectorItemRequires U>
	decltype(auto) operator +(Vector<U> const& v2);


	template <VectorItemRequires U>
	decltype(auto) operator -(const U& el);

	template <VectorItemRequires U>
	decltype(auto) operator -(Vector<U> const& v2);

	template <VectorItemRequires U>
	decltype(auto) operator *(Vector<U> const& v2);

	template <VectorItemRequires U>
	decltype(auto) operator *(const U& el);

	template<VectorItemRequires U>
	decltype(auto) operator/(Vector<U> const& v2);

	template<VectorItemRequires U>
	decltype(auto) operator/(const U& el);


#pragma endregion operations

	std::strong_ordering operator <=>(Vector<T> const& v2);
	bool operator ==(Vector<T> const& v2);
	bool operator !=(Vector<T> const& v2);

	decltype(auto) VectorLen() const noexcept;

	decltype(auto) Normalized();

	T& operator[](int index);
	const T& operator[](int index) const;

	Iterator<T> begin() noexcept;
	Iterator<T> end() noexcept;

    ConstIterator<T> begin() const noexcept {
        return cbegin();
    }

    ConstIterator<T> end() const noexcept {
        return cend();
    }

    ConstIterator<T> cbegin() const noexcept;
	ConstIterator<T> cend() const noexcept;


};



#endif //LAB_02_VECTOR_H


template<VectorItemRequires T>
inline void Vector<T>::AllocSize(int size)
{
	try {
		m_Data = std::make_shared<T[]>(size);
		if (m_Data == nullptr)
		{
			throw std::bad_alloc();
		}
	}
	catch (std::exception ex)
	{
		throw MemoryAllocException(__FILE__, __LINE__);
	}
}


template<VectorItemRequires T>
inline void Vector<T>::CheckLength(int line)
{
	if (this->Size() == 0)
	{
		throw EmptyVectorException(__FILE__, line, "Нулевой вектор при выполнении операции, которая этого не предусматривает");
	}
}

template<VectorItemRequires T>
inline void Vector<T>::CheckRange(int line, int indexToCheck)
{
	if (this->Size() <= indexToCheck || indexToCheck < 0)
	{
		throw OperationInvalidParams(__FILE__, line, "Некорректный индекс запрашиваемого элемента вектора");
	}
}

template<VectorItemRequires T>
inline bool Vector<T>::IsEmpty() const
{
	return m_Size == 0;
}

template<VectorItemRequires T>
inline Vector<T>::Vector() : Vector(0)
{
}

template<VectorItemRequires T>
inline Vector<T>::Vector(int length)
{
	AllocSize(length);
	this->m_Size = length;
}

template<VectorItemRequires T>
inline Vector<T>::Vector(const Vector& v) : Vector(v.Size())
{
    std::copy(v.cbegin(), v.cend(), begin());
}
template<VectorItemRequires T>
inline Vector<T>::Vector(Vector&& v)
{
	m_Data = v.m_Data;
	m_Size = v.m_Size;

	v.m_Data.reset();
}

template<VectorItemRequires T>
inline Vector<T>::Vector(int length, std::shared_ptr<T[]> arr) : Vector(length) {
    std::copy(arr, arr + length, begin());
}

template<VectorItemRequires T>
inline Vector<T>::Vector(int length, const T& fill) : Vector(length)
{
	std::fill(begin(), end(), fill);
}

template<VectorItemRequires T>
inline Vector<T>::Vector(int length, T* arr) : Vector(length)
{
    std::copy(arr, arr + length, begin());
}

template<VectorItemRequires T>
inline Vector<T>::Vector(const std::initializer_list<T> fromList) : Vector(fromList.end() - fromList.begin())
{
    std::copy(fromList.begin(), fromList.end(), begin());
}


template<VectorItemRequires T>
inline Vector<T> Vector<T>::UnitVector(int length)
{
	return Vector<T>(length, 1);
}

template<VectorItemRequires T>
inline int Vector<T>::Size() const noexcept
{
	return m_Size;
}

template<VectorItemRequires T>
inline std::strong_ordering Vector<T>::operator<=>(Vector<T> const& v2)
{
	return this->VectorLen() <=> v2.VectorLen();
}


template<VectorItemRequires T>
inline bool Vector<T>::operator==(Vector<T> const& v2)
{
	return this->VectorLen() == v2.VectorLen();
}

template<VectorItemRequires T>
inline bool Vector<T>::operator!=(Vector<T> const& v2)
{
	return !((*this) == v2);
}

template<VectorItemRequires T>
inline decltype(auto) Vector<T>::VectorLen() const noexcept
{
	decltype(T() * T() + T() * T()) sqSum = 0;
	decltype(sqrt(sqSum)) len = 0;

    auto squares = *this | std::views::transform([](T el) { return el * el; });

    sqSum = std::accumulate(squares.begin(), squares.end(), 0);

	len = sqrt(sqSum);

	return len;
}

template<VectorItemRequires T>
inline decltype(auto) Vector<T>::Normalized()
{
	auto len = VectorLen();

    Vector< decltype((1.0 * (*this)[0]) / len)> normalizedVector = *this | std::views::transform([](T el) { return  (1.0 * (el) / len);});

	return normalizedVector;
}

template<VectorItemRequires T>
inline T& Vector<T>::operator[](int index)
{
	auto it = this->begin();
	return it[index];
}

template<VectorItemRequires T>
inline const T& Vector<T>::operator[](int index) const
{
	auto it = this->cbegin();
	return it[index];
}

template<VectorItemRequires T>
inline Iterator<T> Vector<T>::begin() noexcept
{
	return Iterator<T>(*this);
}

template<VectorItemRequires T>
inline Iterator<T> Vector<T>::end() noexcept
{
	return Iterator<T>(*this) + this->Size();
}

template<VectorItemRequires T>
inline ConstIterator<T> Vector<T>::cbegin() const noexcept
{
	return ConstIterator<T>(*this);
}


template<VectorItemRequires T>
inline ConstIterator<T> Vector<T>::cend() const noexcept
{
	return ConstIterator<T>(*this) + Size();
}

template<VectorItemRequires T>
std::ostream& operator << (std::ostream& os, const Vector<T>& v)
{
	os << '(';
	std::for_each(v.cbegin(), v.cbegin() + v.Size(), [&os](T el) { os << el << ',';});

	return os << ')';
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline void Vector<T>::CheckZeroDiv(int line, Vector<U> const& vectorToCheck) const
{

    if (std::ranges::any_of(vectorToCheck, [](U el) { return el ==  U(0);}))
    {
        throw ZeroDivException(__FILE__, line, "При деление векторов делитель не может содержать нулевых координат");
    }
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline void Vector<T>::CheckZeroDiv(int line, U numberToCheck) const
{
	if (numberToCheck == 0)
	{
		throw ZeroDivException(__FILE__, line, "При деление вектора делитель не может быть нулём");
	}
}


template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::Sum(Vector<U> const& v2) const
{
	if (this->IsEmpty() || v2.IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

	if (this->Size() != v2.Size())
	{
		throw OperationInvalidParams(__FILE__, __LINE__, "Невозможно сложить разные по размеру векторы");
	}

    auto v1 = std::ranges::views::filter(*this, [](T el) { return true ;});
    auto v3 = std::ranges::views::filter(v2, [](U el) { return true ;});

    Vector<decltype(v2[0] + (*this)[0])> answer(this->Size());

    auto zipped = std::ranges::views::zip(v1, v3);

    auto res = zipped | std::ranges::views::transform([] (const auto & p) { return std::get<0>(p) + std::get<1>(p); });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

	return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::Mul(Vector<U> const& v2) const
{
	if (this->IsEmpty() || v2.IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

	if (this->Size() != v2.Size())
	{
		throw OperationInvalidParams(__FILE__, __LINE__, "Невозможно умножить разные по размеру векторы");
	}

    auto v1 = std::ranges::views::filter(*this, [](T el) { return true ;});
    auto v3 = std::ranges::views::filter(v2, [](U el) { return true ;});

    Vector<decltype(v2[0] + (*this)[0])> answer(this->Size());

    auto zipped = std::ranges::views::zip(v1, v3);

    auto res = zipped | std::ranges::views::transform([] (const auto & p) { return std::get<0>(p) * std::get<1>(p); });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

	return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::Div(Vector<U> const& v2) const
{
	if (this->IsEmpty() || v2.IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

	if (this->Size() != v2.Size())
	{
		throw OperationInvalidParams(__FILE__, __LINE__, "Невозможно разделить разные по размеру векторы");
	}

	std::cout << "Debug: " << *this << '\n' << v2 << '\n';

	CheckZeroDiv(__LINE__, v2);

    auto v1 = std::ranges::views::filter(*this, [](T el) { return true ;});
    auto v3 = std::ranges::views::filter(v2, [](U el) { return true ;});

    Vector<decltype(v2[0] + (*this)[0])> answer(this->Size());

    auto zipped = std::ranges::views::zip(v1, v3);

    auto res = zipped | std::ranges::views::transform([] (const auto & p) { return std::get<0>(p) / std::get<1>(p); });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

    return answer;

	return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::Diff(Vector<U> const& v2) const
{
	if (this->IsEmpty() || v2.IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

	if (this->Size() != v2.Size())
	{
		throw OperationInvalidParams(__FILE__, __LINE__, "Невозможно отнять разные по размеру векторы");
	}

    auto v1 = std::ranges::views::filter(*this, [](T el) { return true ;});
    auto v3 = std::ranges::views::filter(v2, [](U el) { return true ;});

    Vector<decltype(v2[0] + (*this)[0])> answer(this->Size());

    auto zipped = std::ranges::views::zip(v1, v3);

    auto res = zipped | std::ranges::views::transform([] (const auto & p) { return std::get<0>(p) - std::get<1>(p); });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

    return answer;
}

template<VectorItemRequires T>
template<typename U>
inline decltype(auto) Vector<T>::ScalarProduct(const Vector<U>& v2) const
{
	if (this->m_Size == 0 || v2.m_Size == 0)
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}
	if (this->m_Size != v2.m_Size)
	{
		throw OperationInvalidParams(__FILE__, __LINE__, "Vector sizes is not equal");
	}

    auto v1 = std::ranges::views::filter(*this, [](T el) { return true ;});
    auto v3 = std::ranges::views::filter(v2, [](U el) { return true ;});

    auto zipped = std::ranges::views::zip(v1, v3);

    double sum = 0;

    auto f = zipped | std::ranges::views::transform([&sum] (const auto & p) { sum += std::get<0>(p) * std::get<1>(p); return std::get<0>(p);});
    auto v123 = std::ranges::to<std::vector<int>>();

	return sum;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator+(const U& el)
{
	if (this->IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}


    Vector<decltype((*this)[0] / el)> answer(this->Size());

    auto res = *this | std::ranges::views::transform([&el](T a) { return a + el; });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

    return answer;

	return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator-(const U& el)
{
	if (this->IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

    Vector<decltype((*this)[0] / el)> answer(this->Size());

    auto res = *this | std::ranges::views::transform([&el](T a) { return a - el; });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

	return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator+(Vector<U> const& v2)
{
	return Sum(v2);
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator-(Vector<U> const& v2)
{
	return Diff(v2);
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator*(Vector<U> const& v2)
{
	return Mul(v2);
}


template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator*(const U& el)
{
	if (this->IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

    Vector<decltype((*this)[0] / el)> answer(this->Size());

    auto res = *this | std::ranges::views::transform([&el](T a) { return a * el; });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

    return answer;
}

template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator/(Vector<U> const& v2)
{
	return Div(v2);
}


template<VectorItemRequires T>
template<VectorItemRequires U>
inline decltype(auto) Vector<T>::operator/(const U& el)
{
	if (this->IsEmpty())
	{
		throw EmptyVectorException(__FILE__, __LINE__);
	}

	CheckZeroDiv(__LINE__, el);

    Vector<decltype((*this)[0] / el)> answer(this->Size());

    auto res = *this | std::ranges::views::transform([&el](T a) { return a / el; });

    std::ranges::copy(res.begin(), res.end(), answer.begin());

    return answer;

}