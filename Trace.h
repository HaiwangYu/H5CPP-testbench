#ifndef  H_WireCellH5CPP_Trace
#define  H_WireCellH5CPP_Trace

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define H_WireCellH5CPP_Cluster_MAX_Charge 1024

namespace WireCellH5CPP {
    struct Trace {
        float charge[H_WireCellH5CPP_Cluster_MAX_Charge];
#ifndef H5CPP
        Trace() {
          std::fill_n(charge, H_WireCellH5CPP_Cluster_MAX_Charge, 0);
          }
        Trace(const int seed) {
          std::srand(seed);
          std::fill_n(charge, H_WireCellH5CPP_Cluster_MAX_Charge, 0);
          for (int i=seed;i<seed+100; ++i) charge[i] = std::rand();
          }
#endif
        void print() const {std::cout << "Trace::print: charge: " << charge[0] << ", " << charge[1] << std::endl;};
    };
}
#endif
