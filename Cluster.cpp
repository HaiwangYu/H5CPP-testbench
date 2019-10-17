#include "Cluster.h"
#include <h5cpp/core>
  #include "Cluster_gen.h"
#include <h5cpp/io>

int main () {
  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  std::vector<WireCellH5CPP::Cluster> v_cluster;
  h5::write(fd, "/v_cluster", v_cluster);
  return 0;
}