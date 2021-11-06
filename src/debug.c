#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "libimobiledevice-glue/debug.h"

static LIMD_logging_handler g_messageHandler;

void LIMD_set_logging_handler(LIMD_logging_handler handler) {
    g_messageHandler = handler;
}

// TODO: better error handling = for example we don't gracefully handle the race condition that
// exists when the handler is changed in a ToCToU here... or properly handle malloc etc
void LIMD_log_message(LIMD_message_t type, const char* subsystem, const char* template, ...) {
    if (g_messageHandler != NULL) {

        va_list argp;

        va_start(argp, template);

        char* log_line = malloc(LIMD_LOG_MAX_LINE);

        vsnprintf(log_line, LIMD_LOG_MAX_LINE, template, argp);

        va_end(argp);

        g_messageHandler(type, subsystem, log_line);

        free(log_line);
    }
}