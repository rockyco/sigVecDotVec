#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

#include "sigVecDotVec.h"

int main(void)
{
	bool is_lts_1 = 1;
	std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> a_in[LEN_LTS_8] =
		{{0.2620, 0.3950}, {0.8380, -0.4440}, {0.8510, 0.3470}, {-0.4950, -0.1370}, {0.2010, 0.5670}, {0.0150, 0.4180}, {0.0380, 0.3960}, {-0.2840, 0.3490}};
	std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> b_in[LEN_LTS_8] =
		{{0.0640, 0.3540}, {-0.1140, 0.0940}, {-0.1000, 0.1930}, {0.2290, 0.0250}, {-0.3110, 0.5920}, {-0.1760, 0.1170}, {-0.3540, 0.2010}, {0.0070, 0.2690}};
    std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> c_out;
	std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> c_out_ref;


	sigVecDotVec(a_in, b_in, c_out);
	chest_conj_a_dot_b(a_in, b_in, c_out_ref);

	std::cout << "Real part - hard: " << c_out.real() << '\n';
	std::cout << "Real part - soft: " << c_out_ref.real() << '\n';
	std::cout << "Imag part - hard: " << c_out.imag() << '\n';
	std::cout << "Imag part - soft: " << c_out_ref.imag() << '\n';

}
