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
		{{-0.0428, 0.3179}, {-0.2847, 0.4941}, {0.9223, 0.0908}, {0.6368, 0.2702}, {-0.1652, 0.1066}, {-0.4568,0.0258}, {0.2257, 0.2089}, {0.4727, 0.3902}};
	std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> b_in[LEN_LTS_8] =
		{{-0.0428, 0.3179}, {-0.2847, 0.4941}, {0.9223, 0.0908}, {0.6368, 0.2702}, {-0.1652, 0.1066}, {-0.4568,0.0258}, {0.2257, 0.2089}, {0.4727, 0.3902}};
    std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> c_out;
	std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> c_out_ref;


	sigVecDotVec(a_in, b_in, c_out);
	chest_conj_a_dot_b(a_in, b_in, c_out_ref);

	std::cout << "Real part - hard: " << c_out.real() << '\n';
	std::cout << "Real part - soft: " << c_out_ref.real() << '\n';
	std::cout << "Imag part - hard: " << c_out.imag() << '\n';
	std::cout << "Imag part - soft: " << c_out_ref.imag() << '\n';

}
