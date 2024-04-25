#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP

template <typename T>
concept VectorItemRequires = requires (T a, T b)
{
	a + b; a = b; a - b; a* b; a / b; a / (double)(3); sqrt(a); a * 1.0;
};

template <typename T>
concept VectorItemRequires = std::is_arithmetic<T>::value;


template<typename T>
concept RandomAccess = std::is_arithmetic<T>::value;

template<typename U>
concept IteratorChangeStep = std::is_arithmetic<U>::value;


#endif