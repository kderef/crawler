#pragma once

//! #define LOG_TIMESTAMP
//! #define LOG_COLORED

#include "util.c"
#include "time.c"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "raylib.h"

// used by INFO, ERROR, ...
#define _LOG(LVL, FMT, ...) \
    TraceLog(LVL, __FILE_NAME__ ":" STR(__LINE__) " - " FMT, ##__VA_ARGS__)

#define INFO(FMT, ...) _LOG(LOG_INFO, FMT, ##__VA_ARGS__)
#define ERROR(FMT, ...) _LOG(LOG_ERROR, FMT, ##__VA_ARGS__)

static FILE* log_file = NULL;

bool log_file_open(const char* path) {
    INFO("Opening log file '%s'", path);

    log_file = fopen(path, "w");

    if (!log_file) {
        return false;
    }

    INFO("Successfully opened log file '%s' at %s", path, get_datetime());

    return true;
}
void log_file_close() {
    char* datetime = get_datetime();
    INFO("Closing log file at %s", datetime);
    if (log_file) fclose(log_file);
}

void tracelog_callback(int lvl, const char* fmt, va_list args) {
    // static char buf[512] = {0};

    static struct {char* color; char* note;} levels[] = {
        [LOG_ALL] = {"", ""},
        [LOG_TRACE] = {"\033[95m", "[TRACE] "},
        [LOG_DEBUG] = {"\033[94m", "[DEBUG] "},
        [LOG_INFO] = {"\033[92m", "[INFO] "},
        [LOG_WARNING] = {"\033[93m", "[WARNING] "},
        [LOG_ERROR] = {"\033[91m", "[ERROR] "},
        [LOG_FATAL] = {"\033[31m", "[FATAL] "},
    };

    // SAFETY: lvl assumed to be in bounds
    char* lvl_str = levels[lvl].note;
    char* lvl_color = levels[lvl].color;

    #ifdef LOG_TIMESTAMP
    char* datetime = get_datetime();
    #  define _PRINT_FMT "<%s> %s", datetime
    #else
    #  define _PRINT_FMT "%s"
    #endif

    // log to file
    if (log_file) {
        fprintf(log_file, _PRINT_FMT, lvl_str);
        vfprintf(log_file, fmt, args);
        fputc('\n', log_file); // flush
    }
    
    // just log
    printf(_PRINT_FMT, lvl_str);
    vprintf(fmt, args);
    putchar('\n');
}

