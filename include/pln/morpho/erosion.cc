#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/erosion.hpp>
#include "erosion.hpp"
#include <pybind11/numpy.h>
#include <stdexcept>
#include <iostream>

#include "../core/se.hpp"
#include "../../../src/convert.hh"

namespace py = pybind11;

py::array pln::morpho::erosion_wrapper(py::array array, pln::se_t& se)
{
    try
    {
        return ndbuffer_image_to_numpy(pln::morpho::erosion(numpy_to_ndbuffer_image(array), se));
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        py::array empty_array;
        return empty_array;
    }
}


mln::ndbuffer_image pln::morpho::erosion(mln::ndbuffer_image input, pln::se_t& se)
{
   auto *image = input.template cast_to<uint8_t, 2>();

    if (!image)
        throw std::invalid_argument("pylene: erosion: incorrect numpy array: should be a 2D grey-scale image");

    int type_id = se.get_type();

    switch (type_id)
    {
        case 0:
        {
            auto res = mln::morpho::erosion(*image, dynamic_cast<pln::se_template<mln::se::disc> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case 1:
        {
            auto res = mln::morpho::erosion(*image, dynamic_cast<pln::se_template<mln::se::rect2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case 2:
        {
            auto res = mln::morpho::erosion(*image, dynamic_cast<pln::se_template<mln::se::periodic_line2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case 3:
        {
            auto res = mln::morpho::erosion(*image, dynamic_cast<pln::se_template<mln::se::mask2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }


        default:
            std::cout << "pylene: erosion: could not detect structuring element type\n";
            return input;
    }
}
