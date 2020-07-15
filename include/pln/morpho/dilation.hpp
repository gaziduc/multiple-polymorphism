#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "../core/se.hpp"

namespace py = pybind11;

namespace pln::morpho
{
    py::array dilation_wrapper(py::array array, const pln::se_t& se);

    mln::ndbuffer_image dilation(mln::ndbuffer_image input, const pln::se_t& se);
}
