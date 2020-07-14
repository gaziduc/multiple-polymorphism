#include <mln/core/se/rect2d.hpp>
#include <mln/core/se/disc.hpp>
#include <mln/core/se/periodic_line2d.hpp>
#include <mln/core/se/mask2d.hpp>
#include <type_traits>

template <typename T>
pln::se_template<T>::se_template(const T& element)
    : element_(element)
{}

template <typename T>
T pln::se_template<T>::get_element() const
{
    return element_;
}

template <typename T>
int pln::se_template<T>::get_type() const
{
    if (std::is_same<decltype(element_), mln::se::disc>::value)
        return 0;

    if (std::is_same<decltype(element_), mln::se::rect2d>::value)
        return 1;

    if (std::is_same<decltype(element_), mln::se::periodic_line2d>::value)
        return 2;

    if (std::is_same<decltype(element_), mln::se::mask2d>::value)
        return 3;

    return -1;
}