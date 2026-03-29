#include "Array.h"

template<typename T>
Array<T>::Array() : arrData(0), size_arr(0){    }

template<typename T>
Array<T>::Array(unsigned int n) : arrData(new T[n]), size_arr(n){    }
template<typename T>
Array<T>::Array(const Array<T> *to_copy) : arrData(new T[to_copy.size_arr]), size_arr(to_copy->size_arr)
{
    for (unsigned int i = 0; i < size_arr; i++)
    {
        arrData[i] = to_copy->arrData[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &original)
{
    if (this != &original)
    {
        delete [] arrData;
        size_arr = original.size_arr;
        arrData = new T[size_arr];
          for (unsigned int i = 0; i < size_arr; i++)
    {
        arrData[i] = original->arrData[i];
    }
    }
    return *this;
}
template<typename T>
Array<T>::~Array()
{
    delete[] arrData;
}
template<typename T>
T &Array<T>::operator[](unsigned int n)
{
    if (size_arr <= n)
        throw LimitsExceptions();
    return (arrData[n]);
}
template<typename T>
const T &Array<T>::operator[](unsigned int n) const
{
    if (size_arr <= n)
        throw LimitsExceptions();
    return (arrData[n]);
}

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->size_arr);
}

template<typename T>
const char *Array<T>::LimitsExceptions::what() const throw()
{
    return ("Error: index out of bounds")
}
