#/usr/bin/evn bash

CXXFLAGS="-std=c++17 -Wno-deprecated \
	-I /cvmfs/larsoft.opensciencegrid.org/products/eigen/v3_3_4a/include/eigen3 \
	-I /cvmfs/larsoft.opensciencegrid.org/products/hdf5/v1_10_5/Linux64bit+3.10-2.17-e17/include \
	-I /cvmfs/larsoft.opensciencegrid.org/products/h5cpp/v1_10_4_1/include"
echo $CXXFLAGS

h5cpp  Trace.cpp   -- $CXXFLAGS -I/usr/include/h5cpp-llvm -DH5CPP -DTrace_gen.h
h5cpp  Cluster.cpp -- $CXXFLAGS -I/usr/include/h5cpp-llvm -DH5CPP -DCluster_gen.h