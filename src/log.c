#pragma once

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
    INFO("[%s] Closing log file", datetime);
    if (log_file) fclose(log_file);
}

void tracelog_callback(int lvl, const char* fmt, va_list args) {
    // static char buf[512] = {0};

    static char* levels[] = {
        [LOG_ALL] = "",
        [LOG_TRACE] = "[TRACE] ",
        [LOG_DEBUG] = "[DEBUG] ",
        [LOG_INFO] = "[INFO] ",
        [LOG_WARNING] = "[WARNING] ",
        [LOG_ERROR] = "[ERROR] ",
        [LOG_FATAL] = "[FATAL] ",
    };

    // SAFETY: lvl assumed to be in bounds
    char* lvl_str = levels[lvl];

    // log to file
    if (log_file) {
        fprintf(log_file, "%s", lvl_str);
        vfprintf(log_file, fmt, args);
        fputc('\n', log_file); // flush
    }
    
    // just log
    printf("%s", lvl_str);
    vprintf(fmt, args);
    putchar('\n');
}

