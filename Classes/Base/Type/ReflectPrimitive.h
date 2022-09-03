#pragma once
#include "Base/Reflect.h"

namespace Reflect {

//--------------------------------------------------------
// A type descriptor for int
//--------------------------------------------------------

struct TypeInt : GType {
    TypeInt() : GType{"int", sizeof(int)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "int{" << *(const int*) obj << "}";
    }
};

template <>
GType* getPrimitiveType<int>() {
    static TypeInt typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for uint32
//--------------------------------------------------------

struct TypeUInt : GType {
    TypeUInt() : GType{"uint32", sizeof(uint32)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "uint32{" << *(const uint32*) obj << "}";
    }
};

template <>
GType* getPrimitiveType<uint32>() {
    static TypeUInt typeDesc;
    return &typeDesc;
}


//--------------------------------------------------------
// A type descriptor for float
//--------------------------------------------------------

struct TypeFloat : GType {
    TypeFloat() : GType{"float", sizeof(float)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "float{" << *(const float*) obj << "}";
    }
};

template <>
GType* getPrimitiveType<float>() {
    static TypeFloat typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for double
//--------------------------------------------------------

struct TypeDouble : GType {
    TypeDouble() : GType{"double", sizeof(double)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "double{" << *(const double*) obj << "}";
    }
};

template <>
GType* getPrimitiveType<double>() {
    static TypeDouble typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for bool
//--------------------------------------------------------

struct TypeBool : GType {
    TypeBool() : GType{"bool", sizeof(bool)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "bool{" << *(const bool*) obj << "}";
    }
};

template <>
GType* getPrimitiveType<bool>() {
    static TypeBool typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for std::string
//--------------------------------------------------------

struct TypeString : GType {
    TypeString() : GType{"GString", sizeof(GString)} {
    }
    virtual void dump(const void* obj, int /* unused */) const override {
        std::cout << "GString{\"" << *(const GString*) obj << "\"}";
    }
};

template <>
GType* getPrimitiveType<GString>() {
    static TypeString typeDesc;
    return &typeDesc;
}

} // namespace reflect