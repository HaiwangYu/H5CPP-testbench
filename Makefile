#  _____________________________________________________________________________
#  Copyright (c) <2018> <copyright Steven Varga, Toronto, On>
#  Contact: Steven Varga
#           steven@vargaconsulting.ca
#           2018 Toronto, On Canada
#  _____________________________________________________________________________


apps = main

CXXFLAGS =  -std=c++17 -Wno-deprecated \
	-I /cvmfs/larsoft.opensciencegrid.org/products/eigen/v3_3_4a/include/eigen3 \
	-I /cvmfs/larsoft.opensciencegrid.org/products/hdf5/v1_10_5/Linux64bit+3.10-2.17-e17/include \
	-I /cvmfs/larsoft.opensciencegrid.org/products/h5cpp/v1_10_4_1/include
LIBS = -lhdf5  -lz -ldl -lm

test: $(apps)
	@./main

# gen.h: Trace.h
# 	h5cpp  main.cpp -- $(CXXFLAGS) -I/usr/include/h5cpp-llvm -DTrace_gen.h

main.o: main.cpp Trace_gen.h
	$(CXX) -o main.o $(CXXFLAGS) -c main.cpp

all: $(apps)

main: main.o
	$(CXX) $^ $(LIBS) -o $@

clean:
	@$(RM) *.o *.prof *.h5 $(apps)

.PHONY: test

