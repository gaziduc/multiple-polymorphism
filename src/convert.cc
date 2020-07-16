#include <mln/core/image/ndbuffer_image.hpp>
#include <pybind11/numpy.h>
#include <mln/core/colors.hpp>
#include "convert.hh"

namespace py = pybind11;

bool is_rgb;

mln::ndbuffer_image numpy_to_ndbuffer_image(py::array array)
{
    py::buffer_info buf = array.request();

    int shape[2] = { 0 };
    for (ssize_t i = 0; i < 2; i++)
        shape[i] = buf.shape[i];

    if (buf.ndim == 3)
    {
        is_rgb = true;
        return mln::ndbuffer_image::from_buffer(reinterpret_cast<std::byte *>(buf.ptr), mln::sample_type_id::RGB8, 2, shape, nullptr, false);
    }

    is_rgb = false;
    return mln::ndbuffer_image::from_buffer(reinterpret_cast<std::byte *>(buf.ptr), mln::sample_type_id::UINT8, 2, shape, nullptr, false);
}

py::array ndbuffer_image_to_numpy(mln::ndbuffer_image buffer_image)
{
    py::buffer_info buf;
    buf.ptr = reinterpret_cast<void *>(buffer_image.buffer());
    buf.itemsize = sizeof(mln::sample_type_id::UINT8);
    buf.format = py::format_descriptor<uint8_t>::format();
    buf.ndim = buffer_image.pdim();

    if (is_rgb)
        buf.ndim++;

    std::vector<ssize_t> shape(buf.ndim);
    for (ssize_t i = 0; i < 2; i++)
        shape[i] = buffer_image.size(i);

    if (is_rgb)
        shape[2] = 3;

    buf.shape = shape;

    return py::array(buf);
}
