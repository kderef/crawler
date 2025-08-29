#pragma once

#include <time.h>


#define DATE_FMT "%d-%m-%Y"
#define TIME_FMT "%H:%M:%S"

#define DATE_SIZE 4 + 1 + 2 + 1 + 2
#define TIME_SIZE 2 + 1 + 2 + 1 + 2

#define DATETIME_FMT DATE_FMT " " TIME_FMT
#define DATETIME_SIZE (TIME_SIZE + 1 + DATE_SIZE)

static char date_buf[DATE_SIZE + 1];
static char datetime_buf[DATETIME_SIZE + 1];

struct tm* get_time() {
    time_t raw_time;
    struct tm* now;

    time(&raw_time);
    now = localtime(&raw_time);

    return now;
}

char* get_datetime() {
    struct tm* now = get_time();

    strftime(
        datetime_buf, DATETIME_SIZE,
        DATETIME_FMT, now
    );

    return datetime_buf;
}

char* get_time_fmt() {
    char* datetime = get_datetime();

    return datetime + DATE_SIZE; // skip date fmt
}
