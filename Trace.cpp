#include "Trace.h"
#include <h5cpp/core>
  #include "Trace_gen.h"
#include <h5cpp/io>

int main () {
  h5::fd_t fd = h5::create("example.h5", H5F_ACC_TRUNC);
  std::vector<WireCellH5CPP::Trace> v;
  h5::write(fd, "/v", v);
  return 0;
}