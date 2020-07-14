#include <mln/core/image/ndbuffer_image.hpp>
#include <mln/core/image/ndimage.hpp>
#include <mln/morpho/dilation.hpp>
#include "dilation.hpp"
#include <mln/core/concepts/structuring_element.hpp>
#include "../core/se.hpp"
#include <mln/core/vec_base.hpp>
#include <pybind11/numpy.h>
#include "../../../src/convert.hh"
#include <iostream>



namespace py = pybind11;

py::array pln::morpho::dilation_wrapper(py::array array, rectangle se)
{
    return ndbuffer_image_to_numpy(pln::morpho::dilation(numpy_to_ndbuffer_image(array), se));
}


mln::ndbuffer_image pln::morpho::dilation(mln::ndbuffer_image input, rectangle se)
{
    std::cout << "1" << '\n';
    auto *image = input.template cast_to<uint8_t, 2>();

    if (!image)
        std::cout << "error\n";
        
    // int type_id = se.get_type();
    
  /*  switch (type_id)
    {
        case 0:
        {*/
    std::cout << "2" << '\n';
    auto res = mln::morpho::dilation(*image, dynamic_cast<pln::rectangle *>(&se)->get_element());
    std::cout << "3" << '\n';
    mln::ndbuffer_image output = res;
    std::cout << "4" << '\n';
    return output;
   /*     }
        
        default:
            return input;
    }*/
}