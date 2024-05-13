/* -*- c++ -*- */
/*
 * Copyright 2024 Francisco Aguirre.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "customSquareSignal_impl.h"
#include <gnuradio/gr_complex.h>
#include <gnuradio/io_signature.h>
#include <gnuradio/math.h>

namespace gr {
namespace customSources {

using output_type = float;
customSquareSignal::sptr customSquareSignal::make(double sampling_freq,
                                                  double frequency,
                                                  double ampl,
                                                  float offset,
                                                  float phase,
                                                  double duty_cycle)
{
    return gnuradio::make_block_sptr<customSquareSignal_impl>(
        sampling_freq, frequency, ampl, offset, phase, duty_cycle);
}


/*
 * The private constructor
 */
customSquareSignal_impl::customSquareSignal_impl(double sampling_freq,
                                                 double frequency,
                                                 double ampl,
                                                 float offset,
                                                 float phase,
                                                 double duty_cycle)
    : gr::sync_block("customSquareSignal",
                     gr::io_signature::make(0, 0, 0),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type))),
      d_sampling_freq(sampling_freq),
      d_frequency(frequency),
      d_ampl(ampl),
      d_offset(offset),
      d_duty_cycle(duty_cycle)
{
    this->set_frequency(frequency);
    this->set_phase(phase);
}

/*
 * Our virtual destructor.
 */
customSquareSignal_impl::~customSquareSignal_impl() {}

int customSquareSignal_impl::work(int noutput_items,
                                  gr_vector_const_void_star& input_items,
                                  gr_vector_void_star& output_items)
{
    auto out = static_cast<output_type*>(output_items[0]);
    gr::thread::scoped_lock l(this->d_setlock);

    float t = (float) d_ampl + d_offset;
    for (int i = 0; i < noutput_items; i++) {
        if ((d_nco.get_phase() + GR_M_PI)/(2*GR_M_PI) < (d_duty_cycle))
            out[i] = t;
        else
            out[i] = d_offset;
        d_nco.step();
    }
    // Tell runtime system how many output items we produced.
    return noutput_items;
}

void customSquareSignal_impl::set_sampling_freq(double sampling_freq)
{
    d_sampling_freq = sampling_freq;
    d_nco.set_freq(2 * GR_M_PI * this->d_frequency / this->d_sampling_freq);
}

void customSquareSignal_impl::set_frequency(double frequency)
{
    d_frequency = frequency;
    d_nco.set_freq(2 * GR_M_PI * this->d_frequency / this->d_sampling_freq);
}

void customSquareSignal_impl::set_amplitude(double ampl)
{
    d_ampl = ampl;
}

void customSquareSignal_impl::set_offset(float offset)
{
    d_offset = offset;
}

void customSquareSignal_impl::set_phase(float phase)
{
    gr::thread::scoped_lock l(this->d_setlock);
    d_nco.set_phase(phase);
}

} /* namespace customSources */
} /* namespace gr */
