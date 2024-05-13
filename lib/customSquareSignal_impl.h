/* -*- c++ -*- */
/*
 * Copyright 2024 Francisco Aguirre.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_IMPL_H
#define INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_IMPL_H

#include <gnuradio/customSources/customSquareSignal.h>
#include <gnuradio/fxpt_nco.h>

namespace gr {
namespace customSources {

class customSquareSignal_impl : public customSquareSignal
{
private:
    double d_sampling_freq;
    double d_frequency;
    double d_ampl;
    float d_offset;
    double d_duty_cycle;
    gr::fxpt_nco d_nco;

public:
    customSquareSignal_impl(double sampling_freq,
                            double frequency,
                            double ampl,
                            float offset,
                            float phase,
                            double duty_cycle);
    ~customSquareSignal_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
    
    double sampling_freq() const { return d_sampling_freq; }
    double frequency() const { return d_frequency; }
    double amplitude() const { return d_ampl; }
    float offset() const { return d_offset; }
    float phase() const { return d_nco.get_phase(); }
    void set_sampling_freq(double sampling_freq);
    void set_frequency(double frequency);
    void set_amplitude(double ampl);
    void set_offset(float offset);
    void set_phase(float phase);
};

} // namespace customSources
} // namespace gr

#endif /* INCLUDED_CUSTOMSOURCES_CUSTOMSQUARESIGNAL_IMPL_H */
