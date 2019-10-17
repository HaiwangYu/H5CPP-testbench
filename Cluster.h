#ifndef  H_WireCellH5CPP_Cluster
#define  H_WireCellH5CPP_Cluster

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define H_WireCellH5CPP_Cluster_MAX_Corner 100

namespace WireCellH5CPP {
  struct Corner {
    float pos[3];
  #ifndef H5CPP
    Corner() {std::fill_n(pos, 3, 0);}
  #endif
  };

struct Blob {
  int ident;
  float value;
  double start;
  double span;
  int ncorners;
  Corner corners[H_WireCellH5CPP_Cluster_MAX_Corner];
#ifndef H5CPP
  Blob() { std::fill_n(corners, H_WireCellH5CPP_Cluster_MAX_Corner, Corner()); }
  friend std::ostream& operator<<(std::ostream& ost, const Blob& b) {
    ost << "Blob: " << b.ident << ", value: " << b.value << ", ncorners: " << b.ncorners << std::endl;
    return ost;
  };
#endif
};
} // namespace WireCellH5CPP
#endif