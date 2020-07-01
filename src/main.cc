#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include <mln/core/image/ndbuffer_image.hpp>

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
