/* Copyright (c) 2018 vargaconsulting, Toronto,ON Canada
 *     Author: Varga, Steven <steven@vargaconsulting.ca>
 */
#ifndef H5CPP_GUARD_EnoZH
#define H5CPP_GUARD_EnoZH

namespace h5{
    //template specialization of WireCellH5CPP::Trace to create HDF5 COMPOUND type
    template<> hid_t inline register_struct<WireCellH5CPP::Trace>(){
        hsize_t at_00_[] ={1024};            hid_t at_00 = H5Tarray_create(H5T_NATIVE_FLOAT,1,at_00_);

        hid_t ct_00 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Trace));
        H5Tinsert(ct_00, "ident",	HOFFSET(WireCellH5CPP::Trace,ident),H5T_NATIVE_INT);
        H5Tinsert(ct_00, "ncharge",	HOFFSET(WireCellH5CPP::Trace,ncharge),H5T_NATIVE_INT);
        H5Tinsert(ct_00, "charge",	HOFFSET(WireCellH5CPP::Trace,charge),at_00);

        //closing all hid_t allocations to prevent resource leakage
        H5Tclose(at_00); 

        //if not used with h5cpp framework, but as a standalone code generator then
        //the returned 'hid_t ct_00' must be closed: H5Tclose(ct_00);
        return ct_00;
    };
}
H5CPP_REGISTER_STRUCT(WireCellH5CPP::Trace);

#endif
