#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "../core/se.hpp"

namespace py = pybind11;

namespace pln::morpho
{
    py::array opening_wrapper(py::array array, pln::se_t se);

    mln::ndbuffer_image opening(mln::ndbuffer_image input, pln::se_t se);
}