#include <ap_fixed.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <complex>

#define PIPELINE_OPT
#define LEN_LTS_8 8

const int W_EXD = 13; //
const int LARGE_NUM1 = 15; //

static const int W = 16; // default bit width
static const int I = 1; // default int part width

void sigVecDotVec(const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> a[LEN_LTS_8],
                  const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> b[LEN_LTS_8],
                  std::complex<ap_fixed<W,I,AP_TRN,AP_SAT>> &c);

void chest_conj_a_dot_b(const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > a[8],
                        const std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > b[8],
                        std::complex<ap_fixed<W,I,AP_TRN,AP_SAT> > &c);

template <class T>
static inline std::complex<T> operator << (const std::complex<T>& cmp, const unsigned shift) {
  std::complex<T> c, r;
  c = cmp;
  r.real(c.real() << shift);
  r.imag(c.imag() << shift);
  return r;
}

template <class T>
static inline std::complex<T> operator >> (const std::complex<T>& cmp, const unsigned shift) {
  std::complex<T> c, r;
  c = cmp;
  r.real(c.real() >> shift);
  r.imag(c.imag() >> shift);
  return r;
}
