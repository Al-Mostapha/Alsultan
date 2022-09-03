#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstddef>
#include "Include/IncludeBase.h"

namespace Reflect {

//--------------------------------------------------------
// Base class of all type descriptors
//--------------------------------------------------------

struct GType {
    const char* Name;
    size_t Size;
    GType(const char* name, size_t size) : Name{name}, Size{size} {}
    virtual ~GType() {}
    virtual std::string getName() const { return Name; }
    virtual void dump(const void* obj, int indentLevel = 0) const = 0;
};

//--------------------------------------------------------
// Finding type descriptors
//--------------------------------------------------------

// Declare the function template that handles primitive types such as int, std::string, etc.:
template <typename T>
GType* getPrimitiveType();

// A helper class to find TypeDescriptors in different ways:
struct GResolverBase {
    template <typename T> static char func(decltype(&T::Reflection));
    template <typename T> static int func(...);
    template <typename T>
    struct IsReflected {
        enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) };
    };

    // This version is called if T has a static member named "Reflection":
    template <typename T, typename std::enable_if<IsReflected<T>::value, int>::type = 0>
    static GType* get() {
        return &T::Reflection;
    }

    // This version is called otherwise:
    template <typename T, typename std::enable_if<!IsReflected<T>::value, int>::type = 0>
    static GType* get() {
        return getPrimitiveType<T>();
    }
};

// This is the primary class template for finding all TypeDescriptors:
template <typename T>
struct GResolver {
    static GType* get() {
        return GResolverBase::get<T>();
    }
};

//--------------------------------------------------------
// Type descriptors for user-defined structs/classes
//--------------------------------------------------------

struct GTypeStruct : GType {
    struct Member {
        const char* Name;
        size_t Offset;
        GType* Type;
    };

    GVector<Member> Members;

    GTypeStruct(void (*init)(GTypeStruct*)) : GType{nullptr, 0} {
        init(this);
    }
    GTypeStruct(const char* name, size_t size, const std::initializer_list<Member>& init) : GType{nullptr, 0}, Members{init} {
    }
    virtual void dump(const void* obj, int indentLevel) const override {
        std::cout << Name << " {" << std::endl;
        for (const Member& member : Members) {
            std::cout << std::string(4 * (indentLevel + 1), ' ') << member.Name << " = ";
            member.Type->dump((char*) obj + member.Offset, indentLevel + 1);
            std::cout << std::endl;
        }
        std::cout << std::string(4 * indentLevel, ' ') << "}";
    }
};

#define REFLECT() \
    friend struct Reflect::GResolverBase; \
    static Reflect::GTypeStruct Reflection; \
    static void initReflection(Reflect::GTypeStruct*);

#define REFLECT_BEGIN(type) \
    Reflect::GTypeStruct type::Reflection{type::initReflection}; \
    void type::initReflection(Reflect::GTypeStruct* typeDesc) { \
        using T = type; \
        typeDesc->Name = #type; \
        typeDesc->Size = sizeof(T); \
        typeDesc->Members = {

#define REFLECT_MEMBER(name) \
            {#name, offsetof(T, name), Reflect::GResolver<decltype(T::name)>::get()},

#define REFLECT_END() \
        }; \
    }
} // namespace reflect