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

struct Cluster {
  Corner corners[H_WireCellH5CPP_Cluster_MAX_Corner];
#ifndef H5CPP
  Cluster() { std::fill_n(corners, H_WireCellH5CPP_Cluster_MAX_Corner, Corner()); }
#endif
  void print() const {
  };
};
} // namespace WireCellH5CPP
#endif