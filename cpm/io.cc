
namespace io {
#include "common.cc"
#include "display.cc"

using namespace types;

// print
template<typename T>
int print(T value) {
    format<T> fmt;
    return c::printf(fmt.specifier(), fmt.fmt_arg(value));
}

template<typename T, typename ...Rest>
int print(T value, Rest... rest) {
    int acc = print(value);
    if (sizeof ...(rest) > 0) {
        acc += c::printf(" ");
        acc += print(rest...);
    }
    return acc;
}


// println
template<typename T>
int println(T value) {
    int p = c::printf(format<T>::specifier(), format<T>::fmt_arg(value));
    c::printf("\n");
    return p;
}


template<typename T, typename ...Rest>
int println(T value, Rest... rest) {
    int acc = print(value);
    acc += c::printf(" ");
    acc += print(rest...);
    c::printf("\n");
    return acc;
}
    
}


