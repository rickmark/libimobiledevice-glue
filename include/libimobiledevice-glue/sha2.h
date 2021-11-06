#ifndef __LIMD_GLUE_SHA2_H
#define __LIMD_GLUE_SHA2_H


#include <stddef.h>
#include "fixedint.h"

/* state */
typedef struct LIMD_sha512_context_ {
    uint64_t  length, state[8];
    size_t curlen;
    unsigned char buf[128];
    int num_qwords;
} LIMD_sha512_context;

#define LIMD_SHA512_DIGEST_LENGTH 64

int LIMD_sha512_init(LIMD_sha512_context * md);
int LIMD_sha512_final(LIMD_sha512_context * md, unsigned char *out);
int LIMD_sha512_update(LIMD_sha512_context * md, const unsigned char *in, size_t inlen);
int LIMD_sha512(const unsigned char *message, size_t message_len, unsigned char *out);

typedef LIMD_sha512_context LIMD_sha384_context;

#define LIMD_SHA384_DIGEST_LENGTH 48

int LIMD_sha384_init(LIMD_sha384_context * md);
int LIMD_sha384_final(LIMD_sha384_context * md, unsigned char *out);
int LIMD_sha384_update(LIMD_sha384_context * md, const unsigned char *in, size_t inlen);
int LIMD_sha384(const unsigned char *message, size_t message_len, unsigned char *out);

#endif
