//
// Created by Rick Mark on 10/14/21.
//

#ifndef LIBIMOBILEDEVICE_GLUE_DEBUG_H
#define LIBIMOBILEDEVICE_GLUE_DEBUG_H

#include <stdarg.h>

#define LIMD_LOG_MAX_LINE 1024

// Copy syslog because it has the most complete list of possible wants
typedef enum {
    LIMD_EMERGENCY = 0,
    LIMD_ALERT = 1,
    LIMD_CRITICAL = 2,
    LIMD_ERROR = 3,
    LIMD_WARN = 4,
    LIMD_NOTICE = 5,
    LIMD_INFO = 6,
    LIMD_DEBUG = 7
} LIMD_message_t;

typedef void (*LIMD_logging_handler)(LIMD_message_t type, const char* subsystem, const char* message);

// Because this can only be set once, it must only be done from the entry point and not any wrapping libraries
void LIMD_set_logging_handler(LIMD_logging_handler handler);
void LIMD_log_message(LIMD_message_t type, const char* subsystem, const char* template, ...);

#endif //LIBIMOBILEDEVICE_GLUE_DEBUG_H
