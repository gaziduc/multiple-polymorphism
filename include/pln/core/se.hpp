#pragma once

#include <mln/core/se/rect2d.hpp>

namespace pln
{
    class se_t
    {
    public:
        virtual int get_type() const;
    };

    class rectangle : se_t
    {
    public:
        rectangle(int width, int height);

        mln::se::rect2d get_element();

    private:
        mln::se::rect2d element_;   
    };


    namespace se
    {
        rectangle rectangle(int width, int height);
    }
}

#include "se.hxx"

