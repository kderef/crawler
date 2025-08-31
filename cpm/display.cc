#include "common.cc"

using namespace types;

template<typename T>
struct format;

#define FORMAT_IMPL(T, SPECIFIER, FMT_ARG) \
    template<> struct format<T> {\
        constexpr const char* specifier() {return (SPECIFIER);} \
        auto fmt_arg(T& v) {return (FMT_ARG);} \
    }

FORMAT_IMPL(int, "%d", v);

FORMAT_IMPL(int8, "%d", v);
FORMAT_IMPL(int16, "%d", v);
// FORMAT_IMPL(int32, "%d", v);
FORMAT_IMPL(int64, "%d", v);

FORMAT_IMPL(uint8, "%u", v);
FORMAT_IMPL(uint16, "%u", v);
FORMAT_IMPL(uint32, "%u", v);
FORMAT_IMPL(uint64, "%u", v);

FORMAT_IMPL(char, "%c", v);
FORMAT_IMPL(char*, "%s", v);
FORMAT_IMPL(const char*, "%s", v);
FORMAT_IMPL(bool, "%s", v ? "true" : "false");

#undef FORMAT_IMPL
