#include "se.hpp"

int pln::se_t::get_type() const
{
    return -1;
}

pln::rectangle::rectangle(int width, int height)
    : element_(width, height)
{}

mln::se::rect2d pln::rectangle::get_element()
{
    return element_;
}

pln::rectangle pln::se::rectangle(int width, int height)
{
    pln::rectangle res(width, height);
    return res;
}