#include "Cluster.h"
#include <h5cpp/core>
  #include "Cluster_gen.h"
#include <h5cpp/io>

int main () {
  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  {
    std::vector<WireCellH5CPP::Blob> v;
    h5::write(fd, "/v", v);
  }
  {
    std::vector<WireCellH5CPP::Edge> v;
    h5::write(fd, "/v", v);
  }
  return 0;
}