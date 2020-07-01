#include <mln/core/image/ndbuffer_image.hpp>
#include <pybind11/pybind11.h>

mln::ndbuffer_image numpy_to_buffer_image(PyObject *obj)
{
    /*
    PyArrayObject *arr = getNPArray();
    *m = getShape(arr, 0);
    *n = getShape(arr, 1);
    */
}

PyObject* buffer_image_to_numpy(mln::ndbuffer_image buffer_image)
{

}
