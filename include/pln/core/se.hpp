#pragma once

#include <mln/core/se/rect2d.hpp>
#include <mln/core/se/disc.hpp>
#include <mln/core/se/periodic_line2d.hpp>
#include <mln/core/se/mask2d.hpp>

namespace pln
{
    class se_t
    {
    public:
        virtual int get_type() const;
    };

    template <typename T>
    class se_template : public se_t
    {
    public:
        se_template(const T& element);

        T get_element() const;
        int get_type() const override;

    private:
        T element_;  
    };
   
    namespace se
    {
        pln::se_template<mln::se::disc> disc(float radius);
        pln::se_template<mln::se::rect2d> rectangle(int width, int height);
        pln::se_template<mln::se::periodic_line2d> periodic_line(mln::point2d v, int k);
        pln::se_template<mln::se::mask2d> mask(std::initializer_list<std::initializer_list<int>> values);
    }
}

#include "se.hxx"

