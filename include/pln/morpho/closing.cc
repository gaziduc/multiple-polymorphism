#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/closing.hpp>
#include "closing.hpp"
#include <pybind11/numpy.h>
#include <stdexcept>
#include <iostream>

#include "../core/se.hpp"
#include "../../../src/convert.hh"

namespace py = pybind11;

py::array pln::morpho::closing_wrapper(py::array array, const pln::se_t& se)
{
    try
    {
        return ndbuffer_image_to_numpy(pln::morpho::closing(numpy_to_ndbuffer_image(array), se));
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        py::array empty_array;
        return empty_array;
    }
}


mln::ndbuffer_image pln::morpho::closing(mln::ndbuffer_image input, const pln::se_t& se)
{
    auto *image = input.template cast_to<uint8_t, 2>();

    if (!image)
        throw std::invalid_argument("pylene: closing: incorrect numpy array: should be a 2D grey-scale image");

    auto type_id = se.get_type();

    switch (type_id)
    {
        case s_element::DISC:
        {
            auto res = mln::morpho::closing(*image, dynamic_cast<const pln::se_template<mln::se::disc> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case s_element::RECTANGLE:
        {
            auto res = mln::morpho::closing(*image, dynamic_cast<const pln::se_template<mln::se::rect2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case s_element::PERIODIC_LINE:
        {
            auto res = mln::morpho::closing(*image, dynamic_cast<const pln::se_template<mln::se::periodic_line2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case s_element::MASK:
        {
            auto res = mln::morpho::closing(*image, dynamic_cast<const pln::se_template<mln::se::mask2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }


        default:
            std::cout << "pylene: closing: could not detect structuring element type\n";
            return input;
    }
}
