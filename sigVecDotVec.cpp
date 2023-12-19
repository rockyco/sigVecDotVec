/**
 * This function is responsible for performing a Channel Estimation task.
 * It takes in certain parameters and returns a specific value.
 * 
 * @param param1 The first parameter of the function.
 * @param param2 The second parameter of the function.
 * @return The result of the task performed by the function.
 */

#include <stdio.h>
#include "sigVecDotVec.h"

void sigVecDotVec(const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> a[LEN_LTS_8],
                  const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> b[LEN_LTS_8],
                  std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> &c) 
{
    std::complex<ap_fixed<W+W,I,AP_TRN,AP_SAT>> a_conj_cast;
    std::complex<ap_fixed<W+W,I,AP_TRN,AP_SAT>> b_cast;
    std::complex<ap_fixed<W+W_EXD+4,I+W_EXD+4-LARGE_NUM1,AP_TRN,AP_SAT>> sum_c;

    MulAdd_loop:
    for (int i=0; i<LEN_LTS_8; i++) {
#pragma HLS UNROLL
        a_conj_cast = std::conj(a[i]);
        b_cast = b[i];
        sum_c += a_conj_cast*b_cast;
    }
    c = (sum_c >> (0+0));
}

void chest_conj_a_dot_b(const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > a[8],
                        const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > b[8],
                        std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > &c) {
  #pragma HLS ARRAY_PARTITION variable=a,b complete dim=1
  #pragma HLS PIPELINE II=1


	  std::complex<ap_fixed<W+W+1,I+1+1,AP_TRN,AP_SAT> > mul0[8];
	  std::complex<ap_fixed<W+W_EXD+1,I+W_EXD+1-LARGE_NUM1,AP_TRN,AP_SAT> > mul[8];
	  #pragma HLS ARRAY_PARTITION variable=mul complete dim=1
	  for (int i=0; i<8; ++i) {
//	    #pragma HLS UNROLL
	    std::complex<ap_fixed<W+W,I,AP_TRN,AP_SAT> > a_conj_cast = std::conj(a[i]);
	    std::complex<ap_fixed<W+W,I,AP_TRN,AP_SAT> > b_cast = b[i];
	    mul0[i] = a_conj_cast*b_cast;
	    mul[i]=  mul0[i];
	  }

  // add
  std::complex<ap_fixed<W+W_EXD+2,I+W_EXD+2-LARGE_NUM1,AP_TRN,AP_SAT> > sum_a[4];
  std::complex<ap_fixed<W+W_EXD+3,I+W_EXD+3-LARGE_NUM1,AP_TRN,AP_SAT> > sum_b[2];
  std::complex<ap_fixed<W+W_EXD+4,I+W_EXD+4-LARGE_NUM1,AP_TRN,AP_SAT> > sum_c[1];
  std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > c2;
  sum_a[0] = mul[0] + mul[1];
  sum_a[1] = mul[2] + mul[3];
  sum_a[2] = mul[4] + mul[5];
  sum_a[3] = mul[6] + mul[7];

  sum_b[0] = (sum_a[0] + sum_a[1])>>0;
  sum_b[1] = (sum_a[2] + sum_a[3])>>0;
  sum_c[0] = (sum_b[0] + sum_b[1])>>0;

  c = (sum_c[0] >>(0+0) );
//  c2 = (sum_c[0] >>(W_EXD+3) );
}

