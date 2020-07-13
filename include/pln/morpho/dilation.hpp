#pragma once

#include "../core/se.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

namespace pln::morpho
{
    py::array dilation_wrapper(py::array array, rectangle se);

    mln::ndbuffer_image dilation(mln::ndbuffer_image input, rectangle se);
}