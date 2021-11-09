/*
 * debug.h
 *
 * Copyright (C) 2021 Rick Mark <rickmark@outlook.com>
 * Copyright (C) 2009 Hector Martin <hector@marcansoft.com>
 * Copyright (C) 2009 Nikias Bassen <nikias@gmx.li>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __LIMD_GLUE_DEBUG_H
#define __LIMD_GLUE_DEBUG_H

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

#endif // __LIMD_GLUE_DEBUG_H
