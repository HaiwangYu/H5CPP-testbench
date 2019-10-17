/* Copyright (c) 2018 vargaconsulting, Toronto,ON Canada
 * Author: Varga, Steven <steven@vargaconsulting.ca>
 */

/** @example vector.cpp
 * A description of the example file, causes the example file to show up in 
 * Examples */
#include <unsupported/Eigen/FFT>

#include <vector>
#include <string>
#include <algorithm>

#include <cstdint>
#include "Trace.h"
#include "Cluster.h"
#include <h5cpp/core>
  #include "Trace_gen.h"
  #include "Cluster_gen.h"
#include <h5cpp/io>

#define log(x) std::cout << x << std::endl

void test_vector() {
  using T = std::vector<float>;

  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  {
    // WireCellH5CPP::Trace vec(42);
    std::vector<float> vec = {41, 42};
    auto ds = h5::write(fd, "/vec", vec);
    ds["tag"] = "hello";
  }

  { // read entire dataset back
    auto data = h5::read<T>(fd, "vec");
    log("read back");
    for (auto a : data)
      log(a);
  }
}

void test_class() {

  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  {
    const int size = 128;
    
    // std::vector<WireCellH5CPP::Trace> v_trace;
    // v_trace.resize(size);
    // // std::fill_n(vec.begin(), size, WireCellH5CPP::Trace());
    // for(int i=0; i<size; ++i) v_trace[i] = WireCellH5CPP::Trace(i);
    // h5::write(fd, "/v_trace", v_trace, h5::gzip{9} | h5::chunk{size});

    std::vector<WireCellH5CPP::Cluster> v_cluster;
    v_cluster.resize(size);
    std::fill_n(v_cluster.begin(), size, WireCellH5CPP::Cluster());
    for(int i=0; i<size; ++i) v_cluster[i] = WireCellH5CPP::Cluster();
    h5::write(fd, "/v_cluster", v_cluster, h5::gzip{9} | h5::chunk{size});
  }

  { // read entire dataset back
    auto v_trace = h5::read<std::vector<WireCellH5CPP::Trace>>(fd, "/v_cluster");
    log("read back");
    for(auto a : v_trace) std::cout << a;
  }
}

void test_array() {
  
  const int nrow = 6000, ncol = 2560;

  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  {
    // Eigen::ArrayXXf d1 = Eigen::ArrayXXf::Random(nrow, ncol);
    Eigen::ArrayXXf d1 = Eigen::ArrayXXf::Zero(nrow, ncol);
    float *vec = d1.data();
    auto ds = h5::write<float>(fd, "/vec", vec, h5::count{ncol, nrow}
    , h5::chunk{10, nrow} | h5::gzip{9}
    );
  }

  { // read entire dataset back
    float *data = new float[ncol*nrow];
    h5::read<float>(fd, "/vec", data, h5::count{ncol, nrow});
    log("read back");
    Eigen::ArrayXXf d1 = Eigen::ArrayXXf::Zero(ncol, nrow);
    d1 = *data;
    log(d1.size());
  }
}

int main() {
  test_class();
  return 0;
}
