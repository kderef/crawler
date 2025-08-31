#pragma once


namespace std {
    #include <stdio.h>
    #include <stdint.h>
    #include <errno.h>
    #include <string.h>
}


// option type
template<typename T>
struct optional {
    T data;
    bool ok;

    constexpr optional<T> empty() {
        return  {.ok = false};  
    }
    constexpr optional<T> some(T data) {
        return {.ok = true, .data = data};
    }
};



namespace c {
    extern "C"{

    #ifndef uintptr_t
    #define uintptr_t
    #endif

    using namespace std;

    extern void* malloc(size_t);
    extern void* realloc(void*, size_t);
    extern void free(void*);
    
    }
}

namespace types {

    // defined int types shorthands (remove _t)
    #define DEF_INT(BITS) typedef c::int##BITS##_t int##BITS; typedef c::uint##BITS##_t uint##BITS
    DEF_INT(8);
    DEF_INT(16);
    DEF_INT(32);
    DEF_INT(64);
    #undef DEF_INT
    
    typedef unsigned int uint;
}
