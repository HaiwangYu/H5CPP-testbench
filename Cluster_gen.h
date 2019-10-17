/* Copyright (c) 2018 vargaconsulting, Toronto,ON Canada
 *     Author: Varga, Steven <steven@vargaconsulting.ca>
 */
#ifndef H5CPP_GUARD_febyv
#define H5CPP_GUARD_febyv

namespace h5{
    //template specialization of WireCellH5CPP::Blob to create HDF5 COMPOUND type
    template<> hid_t inline register_struct<WireCellH5CPP::Blob>(){
        hsize_t at_00_[] ={3};            hid_t at_00 = H5Tarray_create(H5T_NATIVE_FLOAT,1,at_00_);

        hid_t ct_00 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Corner));
        H5Tinsert(ct_00, "pos",	HOFFSET(WireCellH5CPP::Corner,pos),at_00);
        hsize_t at_01_[] ={100};            hid_t at_01 = H5Tarray_create(ct_00,1,at_01_);

        hid_t ct_01 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Blob));
        H5Tinsert(ct_01, "ident",	HOFFSET(WireCellH5CPP::Blob,ident),H5T_NATIVE_INT);
        H5Tinsert(ct_01, "value",	HOFFSET(WireCellH5CPP::Blob,value),H5T_NATIVE_FLOAT);
        H5Tinsert(ct_01, "start",	HOFFSET(WireCellH5CPP::Blob,start),H5T_NATIVE_DOUBLE);
        H5Tinsert(ct_01, "span",	HOFFSET(WireCellH5CPP::Blob,span),H5T_NATIVE_DOUBLE);
        H5Tinsert(ct_01, "ncorners",	HOFFSET(WireCellH5CPP::Blob,ncorners),H5T_NATIVE_INT);
        H5Tinsert(ct_01, "corners",	HOFFSET(WireCellH5CPP::Blob,corners),at_01);

        //closing all hid_t allocations to prevent resource leakage
        H5Tclose(at_00); H5Tclose(ct_00); H5Tclose(at_01); 

        //if not used with h5cpp framework, but as a standalone code generator then
        //the returned 'hid_t ct_01' must be closed: H5Tclose(ct_01);
        return ct_01;
    };
}
H5CPP_REGISTER_STRUCT(WireCellH5CPP::Blob);

namespace h5{
    //template specialization of WireCellH5CPP::Edge to create HDF5 COMPOUND type
    template<> hid_t inline register_struct<WireCellH5CPP::Edge>(){

        hid_t ct_00 = H5Tcreate(H5T_COMPOUND, sizeof (WireCellH5CPP::Edge));
        H5Tinsert(ct_00, "head",	HOFFSET(WireCellH5CPP::Edge,head),H5T_NATIVE_INT);
        H5Tinsert(ct_00, "tail",	HOFFSET(WireCellH5CPP::Edge,tail),H5T_NATIVE_INT);

        //if not used with h5cpp framework, but as a standalone code generator then
        //the returned 'hid_t ct_00' must be closed: H5Tclose(ct_00);
        return ct_00;
    };
}
H5CPP_REGISTER_STRUCT(WireCellH5CPP::Edge);

#endif
