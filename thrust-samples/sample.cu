#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/generate.h>
#include <thrust/reduce.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <thrust/complex.h>

struct complex_abs_functor
{
    __host__ thrust::complex<float> operator()(const thrust::complex<float> z) {
        // return thrust::asinh(z);
        // return thrust::atanh(z);
        return thrust::acosh(z);
    }
};

int main(void) {
    thrust::host_vector<thrust::complex<float>> H(4);
    H[0] = 0.95;
    H[1] = 20.23;
    H[2] = 38.23;
    H[3] = 46.23;
    std::cout << "Size: " << H.size() << std::endl;
    thrust::host_vector<thrust::complex<float>> OUT(4);
    thrust::transform(H.begin(), H.end(), OUT.begin(), complex_abs_functor());
    std::cout << OUT[0] << ", " << OUT[1] << ", " << OUT[2] << ", " << OUT[3] << std::endl;
}
/*
int main(void)
{
  // generate random data serially
  thrust::host_vector<int> h_vec(100);
  std::generate(h_vec.begin(), h_vec.end(), rand);

  // transfer to device and compute sum
  thrust::device_vector<int> d_vec = h_vec;
  int x = thrust::reduce(d_vec.begin(), d_vec.end(), 0, thrust::plus<int>());
  std::cout << "X: " << x << std::endl;
  return 0;
}*/
