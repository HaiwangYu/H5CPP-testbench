/* Copyright (c) 2018 vargaconsulting, Toronto,ON Canada
 *     Author: Varga, Steven <steven@vargaconsulting.ca>
 */
#ifndef H5CPP_GUARD_bOhEs
#define H5CPP_GUARD_bOhEs

namespace h5{
    //template specialization of WireCellH5CPP::Cluster to create HDF5 COMPOUND type
    template<> hid_t inline register_struct<WireCellH5CPP::Cluster>(){
        hsize_t at_00_[] ={3};            hid_t at_00 = H5Tarray_create(H5T_NATIVE_FLOAT,1,at_00_);

        hid_t ct_00 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Corner));
        H5Tinsert(ct_00, "pos",	HOFFSET(WireCellH5CPP::Corner,pos),at_00);
        hsize_t at_01_[] ={100};            hid_t at_01 = H5Tarray_create(ct_00,1,at_01_);

        hid_t ct_01 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Cluster));
        H5Tinsert(ct_01, "corners",	HOFFSET(WireCellH5CPP::Cluster,corners),at_01);

        //closing all hid_t allocations to prevent resource leakage
        H5Tclose(at_00); H5Tclose(ct_00); H5Tclose(at_01); 

        //if not used with h5cpp framework, but as a standalone code generator then
        //the returned 'hid_t ct_01' must be closed: H5Tclose(ct_01);
        return ct_01;
    };
}
H5CPP_REGISTER_STRUCT(WireCellH5CPP::Cluster);

#endif
