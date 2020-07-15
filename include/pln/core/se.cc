#include <iostream>
#include "se.hpp"

enum pln::s_element pln::se_t::get_type() const
{
    return s_element::UNDEFINED;
}

pln::se_template<mln::se::disc> pln::se::disc(float radius)
{
    mln::se::disc d(radius);
    pln::se_template<mln::se::disc> res(d);
    return res;
}

pln::se_template<mln::se::rect2d> pln::se::rectangle(int width, int height)
{
    mln::se::rect2d r(width, height);
    pln::se_template<mln::se::rect2d> res(r);
    return res;
}

pln::se_template<mln::se::periodic_line2d> pln::se::periodic_line(mln::point2d v, int k)
{
    if (k < 0)
    {
        std::cout << "pylene: periodic_line(v, k): k must be greater or equal to 0. defaulting to k = 0\n";
        k = 0;
    }

    mln::se::periodic_line2d pl(v, k);
    pln::se_template<mln::se::periodic_line2d> res(pl);
    return res;
}

pln::se_template<mln::se::mask2d> pln::se::mask(std::initializer_list<std::initializer_list<int>> values)
{
    mln::se::mask2d m(values);
    pln::se_template<mln::se::mask2d> res(m);
    return res;
}