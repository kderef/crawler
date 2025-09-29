#include "prelude.h"
#include "raylib.h"
#include <stddef.h>
#include <stdio.h>
#include <time.h>

static FILE* log_file = NULL;

#define LOG(FMT, ...) do { \
        char* datetime = get_datetime(); \
        fprintf(stderr, "[%s] " FMT "\n", datetime, ##__VA_ARGS__); \
        if (log_file) fprintf(log_file, "[%s] " FMT "\n", datetime, ##__VA_ARGS__); \
    } while (0)


#define DATETIME_BUF_LEN 32
static char datetime_buf[DATETIME_BUF_LEN] = {0}; 

char* get_datetime() {
    static time_t rawtime;
    static struct tm* time_info;
    
    time(&rawtime);
    time_info = localtime(&rawtime);

    strftime(
         datetime_buf, DATETIME_BUF_LEN,
         "%d-%m-%Y - %H:%M:%S",
        time_info
    );

    return datetime_buf;
}

void tracelog_callback(int log_level, const char* text, va_list args) {
    char* datetime = get_datetime();
    
    static const char* LEVELS[] = {
        [LOG_ALL] = "ALL",
        [LOG_DEBUG] = "DEBUG",
        [LOG_FATAL] = "FATAL",
        [LOG_ERROR] = "ERROR",
        [LOG_INFO ] = "INFO",
        [LOG_TRACE] = "TRACE",
        [LOG_WARNING] = "WARNING",
    };

    const char* color = "";
    switch (log_level) {
        case LOG_WARNING: color = "\033[93m"; break;
        case LOG_ERROR:
        case LOG_FATAL: color = "\033[91m"; break;
        case LOG_INFO: color = "\033[92m"; break;
        case LOG_TRACE: color = "\033[94m"; break;
    }

    // write to console
    fprintf(stdout, "[%s] %s[%s]\033[0m : ", datetime, color, LEVELS[log_level]);
    vprintf(text, args);
    fprintf(stdout, "\n");
    
    // write to log file
    if (log_file) {
        fprintf(log_file, "[%s] [%s]\033 : ", datetime, LEVELS[log_level]);
        vfprintf(log_file, text, args);
        fprintf(log_file, "\n");
    }
}

void log_hook_raylib() {
    SetTraceLogCallback(tracelog_callback);
}

/// Try to open `log_file`, return true on success
bool log_open_file(const char* path) {
    FILE* fp = fopen(path, "w");

    if (fp == NULL) return false;
    
    // success
    log_file = fp;

    LOG("Opened log file");
    
    return true;
}

/// Close log file, ignoring errors
void log_close_file() {
    if (log_file) {
        LOG("Closing log file");
        fclose(log_file);
    }
}
