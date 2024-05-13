/* -*- c++ -*- */
/*
 * Copyright 2024 Francisco Aguirre.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_H
#define INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_H

#include <gnuradio/customSources/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace customSources {

/*!
 * \brief <+description of block+>
 * \ingroup customSources
 *
 */
class CUSTOMSOURCES_API customSquareSignal : virtual public gr::sync_block
{
public:
    typedef std::shared_ptr<customSquareSignal> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of customSources::customSquareSignal.
     *
     * To avoid accidental use of raw pointers, customSources::customSquareSignal's
     * constructor is in a private implementation
     * class. customSources::customSquareSignal::make is the public interface for
     * creating new instances.
     */
    static sptr make(double sampling_freq,
                     double frequency = 1,
                     double ampl = 1,
                     float offset = 0,
                     float phase = 0,
                     double duty_cycle = 0);
};

} // namespace customSources
} // namespace gr

#endif /* INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_H */
