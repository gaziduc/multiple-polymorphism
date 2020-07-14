#include <pybind11/pybind11.h>

#include "convert.hh"
#include "../include/pln/morpho/dilation.hpp"
#include "../include/pln/core/se.hpp"

namespace py = pybind11;

PYBIND11_PLUGIN(pylene)
{
    py::module m("pylene", "pylene extension");

    auto morpho = m.def_submodule("morpho");
    morpho.def("dilation", &pln::morpho::dilation_wrapper);

    auto se = m.def_submodule("se");

    py::class_<pln::rectangle>(se, "rectangle").def(py::init<int, int>(), py::arg("width"), py::arg("height"));

    return m.ptr();
}