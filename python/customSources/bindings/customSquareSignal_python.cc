/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(customSquareSignal.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(1fdef98ca954b2b8801098b367131505)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/customSources/customSquareSignal.h>
// pydoc.h is automatically generated in the build directory
#include <customSquareSignal_pydoc.h>

void bind_customSquareSignal(py::module& m)
{

    using customSquareSignal = ::gr::customSources::customSquareSignal;


    py::class_<customSquareSignal,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<customSquareSignal>>(
        m, "customSquareSignal", D(customSquareSignal))

        .def(py::init(&customSquareSignal::make),
             py::arg("sampling_freq"),
             py::arg("frequency") = 1,
             py::arg("ampl") = 1,
             py::arg("offset") = 0,
             py::arg("phase") = 0,
             py::arg("duty_cycle") = 0,
             D(customSquareSignal, make))


        ;
}
