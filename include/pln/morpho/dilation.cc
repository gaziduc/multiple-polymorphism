#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include "dilation.hpp"
#include <pybind11/numpy.h>
#include <stdexcept>
#include <iostream>

#include "../core/se.hpp"
#include "../../../src/convert.hh"

namespace py = pybind11;

py::array pln::morpho::dilation_wrapper(py::array array, rectangle se)
{
    try
    {
        return ndbuffer_image_to_numpy(pln::morpho::dilation(numpy_to_ndbuffer_image(array), se));
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        py::array empty_array;
        return empty_array;
    }
}


mln::ndbuffer_image pln::morpho::dilation(mln::ndbuffer_image input, rectangle se)
{
    auto *image = input.template cast_to<uint8_t, 2>();

    if (!image)
        throw std::invalid_argument("pylene: incorrect numpy array: should be a 2D grey-scale image");

    // int type_id = se.get_type();
    
  /*  switch (type_id)
    {
        case 0:
        {*/
    auto res = mln::morpho::dilation(*image, dynamic_cast<pln::rectangle *>(&se)->get_element());
    mln::ndbuffer_image output = res;
    return output;
   /*     }
        
        default:
            return input;
    }*/
}