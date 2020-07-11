#include "se.hpp"

template <typename T>
pln::se<T>::se(const T& element)
    : element_(element)
{}

template <typename T>
T pln::se<T>::get_se() const
{
    return element_;
}