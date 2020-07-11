#include <mln/core/image/ndbuffer_image.hpp>
#include <pybind11/numpy.h>
#include "convert.hh"

namespace py = pybind11;

mln::ndbuffer_image numpy_to_ndbuffer_image(py::array array)
{    
    py::buffer_info buf = array.request();

    int shape[buf.ndim] = {0};
    for (ssize_t i = 0; i < buf.ndim; i++)
        shape[i] = buf.shape[i];

    return mln::ndbuffer_image::from_buffer(reinterpret_cast<std::byte *>(buf.ptr), mln::sample_type_id::UINT8, buf.ndim, shape, nullptr, false);
}

py::array ndbuffer_image_to_numpy(mln::ndbuffer_image buffer_image)
{
    py::buffer_info buf;
    buf.ptr = reinterpret_cast<void *>(buffer_image.buffer());
    buf.itemsize = sizeof(mln::sample_type_id::UINT8);
    buf.format = "l";
    buf.ndim = buffer_image.pdim();

    std::vector<ssize_t> shape(buf.ndim);
    std::vector<ssize_t> strides(buf.ndim);
    for (ssize_t i = 0; i < buf.ndim; i++)
    {
        shape[i] = buffer_image.size(i);
        strides[i] = buffer_image.byte_stride(i);
    }

    buf.shape = shape;
    buf.strides = strides;

    return py::array(buf);
}