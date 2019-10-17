#!/usr/bin/env bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/cvmfs/larsoft.opensciencegrid.org/products/hdf5/v1_10_5/Linux64bit+3.10-2.17-e17/lib
export LIBRARY_PATH=$LIBRARY_PATH:/cvmfs/larsoft.opensciencegrid.org/products/hdf5/v1_10_5/Linux64bit+3.10-2.17-e17/lib
# make clean
make
