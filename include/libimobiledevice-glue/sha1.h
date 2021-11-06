#ifndef SHA1_H
#define SHA1_H

/*
   SHA-1 in C
   By Steve Reid <steve@edmweb.com>
   100% Public Domain

    * Adapted for use in libimobiledevice-glue by Rick Mark
 */

#include "stdint.h"

typedef struct
{
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} LIMD_SHA1_CTX;

void LIMD_SHA1Transform(
    uint32_t state[5],
    const unsigned char buffer[64]
    );

void LIMD_SHA1Init(
    LIMD_SHA1_CTX * context
    );

void LIMD_SHA1Update(
    LIMD_SHA1_CTX * context,
    const unsigned char *data,
    size_t len
    );

void LIMD_SHA1Final(
    unsigned char digest[20],
    LIMD_SHA1_CTX * context
    );

void LIMD_SHA1(
    const unsigned char *str,
    size_t len,
    unsigned char *hash_out);

#endif /* SHA1_H */
