//--------------------------
// cpm.h - C plus minus
//--------------------------
// === IMPORTANT === //
// > define CPM_IMPLEMENTATION to get function implementations.

/*************************************/
// === RULES === //

// 1. NO CONSTRUCTORS/DESTRUCTORS, use factories
// 2. NO C++ STANDARD LIBRARY, use libc instead.
// 3. NO CLASSES/INHERITANCE ALLOWED, use structs


namespace cpm {

#include "common.cc"
#include "io.cc"
#include "arrays.cc"

using io::print;
using io::println;

// basic types
using namespace types;

// --- export
using namespace arrays;
using namespace types;
}
