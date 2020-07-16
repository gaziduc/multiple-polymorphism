#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/opening.hpp>
#include <mln/core/colors.hpp>
#include "opening.hpp"
#include <pybind11/numpy.h>
#include <stdexcept>
#include <iostream>

#include "../core/se.hpp"
#include "../../../src/convert.hh"

namespace py = pybind11;

py::array pln::morpho::opening_wrapper(py::array array, const pln::se_t& se)
{
    try
    {
        return ndbuffer_image_to_numpy(pln::morpho::opening(numpy_to_ndbuffer_image(array), se));
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        py::array empty_array;
        return empty_array;
    }
}


mln::ndbuffer_image pln::morpho::opening(mln::ndbuffer_image input, const pln::se_t& se)
{
    auto *image_rgb = input.template cast_to<mln::rgb8, 2>();
    mln::image2d<uint8_t> *image_grey = nullptr;

    if (!image_rgb)
    {
        image_grey = input.template cast_to<uint8_t, 2>();

        if (!image_grey)
            throw std::invalid_argument("pylene: opening: incorrect numpy array: cannot cast mln::buffer_image to image2d.\nThe image have to be an 2D grey-scale or RGB image.");
    }

    auto type_id = se.get_type();

    switch (type_id)
    {
        case s_element::DISC:
        {
            if (image_rgb)
            {
                auto res = mln::morpho::opening(*image_rgb, dynamic_cast<const pln::se_template<mln::se::disc> *>(&se)->get_element());
                mln::ndbuffer_image output = res;
                return output;
            }

            auto res = mln::morpho::opening(*image_grey, dynamic_cast<const pln::se_template<mln::se::disc> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }
            

        case s_element::RECTANGLE:
        {
            if (image_rgb)
            {
                auto res = mln::morpho::opening(*image_rgb, dynamic_cast<const pln::se_template<mln::se::rect2d> *>(&se)->get_element());
                mln::ndbuffer_image output = res;
                return output;
            }

            auto res = mln::morpho::opening(*image_grey, dynamic_cast<const pln::se_template<mln::se::rect2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case s_element::PERIODIC_LINE:
        {
            if (image_rgb)
            {
                auto res = mln::morpho::opening(*image_rgb, dynamic_cast<const pln::se_template<mln::se::periodic_line2d> *>(&se)->get_element());
                mln::ndbuffer_image output = res;
                return output;
            }

            auto res = mln::morpho::opening(*image_grey, dynamic_cast<const pln::se_template<mln::se::periodic_line2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }

        case s_element::MASK:
        {
            if (image_rgb)
            {
                auto res = mln::morpho::opening(*image_rgb, dynamic_cast<const pln::se_template<mln::se::mask2d> *>(&se)->get_element());
                mln::ndbuffer_image output = res;
                return output;
            }

            auto res = mln::morpho::opening(*image_grey, dynamic_cast<const pln::se_template<mln::se::mask2d> *>(&se)->get_element());
            mln::ndbuffer_image output = res;
            return output;
        }


        default:
            std::cout << "pylene: opening: could not detect structuring element type\n";
            return input;
    }
}
