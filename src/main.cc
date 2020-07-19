#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include "convert.hh"
#include "../include/pln/morpho/dilation.hpp"
#include "../include/pln/morpho/erosion.hpp"
#include "../include/pln/morpho/opening.hpp"
#include "../include/pln/morpho/closing.hpp"
#include "../include/pln/core/se.hpp"

namespace py = pybind11;

PYBIND11_PLUGIN(pylene)
{
    py::module m("pylene", "pylene extension");

    auto morpho = m.def_submodule("morpho");
    morpho.def("dilation", &pln::morpho::dilation_wrapper);
    morpho.def("erosion", &pln::morpho::erosion_wrapper);
    morpho.def("opening", &pln::morpho::opening_wrapper);
    morpho.def("closing", &pln::morpho::closing_wrapper);

    auto se = m.def_submodule("se");

    py::class_<pln::se_t> base(se, "se_t");

    py::class_<pln::se_template<mln::se::disc>>(se, "se_disc", base);
    py::class_<pln::se_template<mln::se::rect2d>>(se, "se_rect2d", base);
    py::class_<pln::se_template<mln::se::periodic_line2d>>(se, "se_periodicline2d", base);
    py::class_<pln::se_template<mln::se::mask2d>>(se, "se_mask2d", base);

    py::class_<py::array>(se, "se_mask_points")
    .def(py::init(
        [](py::array a) {
            return a;
        })
    );

    se.def("disc", &pln::se::disc);
    se.def("rectangle", &pln::se::rectangle, py::arg("width"), py::arg("height"));
    se.def("periodic_line", &pln::se::periodic_line);
    se.def("mask", &pln::se::mask, py::arg("se_mask_points"));

    return m.ptr();
}