#pragma once

#include <mln/core/image/ndbuffer_image.hpp>
#include <pybind11/numpy.h>

namespace py = pybind11;

mln::ndbuffer_image numpy_to_ndbuffer_image(py::array array);

py::array ndbuffer_image_to_numpy(mln::ndbuffer_image buffer_image);