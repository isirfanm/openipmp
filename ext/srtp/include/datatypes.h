/*
 * datatypes.h
 * 
 * data types for bit vectors and finite fields
 *
 * David A. McGrew
 * Cisco Systems, Inc.
 */

/*
 *	
 * Copyright (c) 2001-2005, Cisco Systems, Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * 
 *   Neither the name of the Cisco Systems, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef _DATATYPES_H
#define _DATATYPES_H

#include "integers.h"           /* definitions of uint32_t, et cetera   */
#include "alloc.h"

/* if DATATYPES_USE_MACROS is defined, then little functions are macros */
#define DATATYPES_USE_MACROS  

typedef unsigned char octet_t;

typedef union {
  unsigned char octet[2];
  uint16_t value;
} v16_t;

typedef union {
  unsigned char octet[4];
  uint16_t v16[2];
  uint32_t value;
} v32_t;

typedef union {
  unsigned char octet[8];
  uint16_t v16[4];
  uint32_t v32[2];
  uint64_t value;
} v64_t;

typedef union {
  unsigned char octet[16];
  uint16_t v16[8];
  uint32_t v32[4];
  uint64_t v64[2];
} v128_t;


/* some useful and simple math functions */

#define pow_2(X) ( (unsigned int)1 << (X) )   /* 2^X     */

#define pow_minus_one(X) ( (X) ? -1 : 1 )      /* (-1)^X  */


/*
 * octet_weight(x) returns the hamming weight (number of bits equal to
 * one) in the octet x
 */

int
octet_get_weight(octet_t octet);

char *
octet_bit_string(octet_t x);

#define MAX_PRINT_STRING_LEN 1024

char *
octet_string_hex_string(const void *str, int length);

char *
v128_bit_string(v128_t *x);

char *
v128_hex_string(v128_t *x);

octet_t
nibble_to_hex_char(octet_t nibble);

char *
char_to_hex_string(char *x, int num_char);

octet_t
hex_string_to_octet(char *s);

/*
 * hex_string_to_octet_string(raw, hex, len) converts the hexadecimal
 * string at *hex (of length len octets) to the equivalent raw data
 * and writes it to *raw.
 *
 * if a character in the hex string that is not a hexadeciaml digit
 * (0123456789abcdefABCDEF) is encountered, the function stops writing
 * data to *raw
 *
 * the number of hex digits copied (which is two times the number of
 * octets in *raw) is returned
 */

int
hex_string_to_octet_string(char *raw, char *hex, int len);

v128_t
hex_string_to_v128(char *s);

void
v128_copy_octet_string(v128_t *x, const octet_t s[16]);

void
v128_left_shift(v128_t *x, int index);

void
v128_right_shift(v128_t *x, int index);

/*
 * the following macros define the data manipulation functions
 * 
 * If DATATYPES_USE_MACROS is defined, then these macros are used
 * directly (and function call overhead is avoided).  Otherwise,
 * the macros are used through the functions defined in datatypes.c
 * (and the compiler provides better warnings).
 */

#define _v128_set_to_zero(x)     \
(                               \
  (x)->v32[0] = 0,              \
  (x)->v32[1] = 0,              \
  (x)->v32[2] = 0,              \
  (x)->v32[3] = 0               \
)

#define _v128_copy(x, y)          \
(                                \
  (x)->v32[0] = (y)->v32[0],     \
  (x)->v32[1] = (y)->v32[1],     \
  (x)->v32[2] = (y)->v32[2],     \
  (x)->v32[3] = (y)->v32[3]      \
)

#define _v128_xor(z, x, y)                       \
(                                               \
   (z)->v32[0] = (x)->v32[0] ^ (y)->v32[0],     \
   (z)->v32[1] = (x)->v32[1] ^ (y)->v32[1],     \
   (z)->v32[2] = (x)->v32[2] ^ (y)->v32[2],     \
   (z)->v32[3] = (x)->v32[3] ^ (y)->v32[3]      \
)

#define _v128_and(z, x, y)                       \
(                                               \
   (z)->v32[0] = (x)->v32[0] & (y)->v32[0],     \
   (z)->v32[1] = (x)->v32[1] & (y)->v32[1],     \
   (z)->v32[2] = (x)->v32[2] & (y)->v32[2],     \
   (z)->v32[3] = (x)->v32[3] & (y)->v32[3]      \
)

#define _v128_or(z, x, y)                        \
(                                               \
   (z)->v32[0] = (x)->v32[0] | (y)->v32[0],     \
   (z)->v32[1] = (x)->v32[1] | (y)->v32[1],     \
   (z)->v32[2] = (x)->v32[2] | (y)->v32[2],     \
   (z)->v32[3] = (x)->v32[3] | (y)->v32[3]      \
)

#define _v128_complement(x)        \
(                                  \
   (x)->v32[0] = ~(x)->v32[0],     \
   (x)->v32[1] = ~(x)->v32[1],     \
   (x)->v32[2] = ~(x)->v32[2],     \
   (x)->v32[3] = ~(x)->v32[3]      \
)

/* ok for NO_64BIT_MATH if it can compare uint64_t's (even as structures) */
#define _v128_is_eq(x, y)                                        \
  (((x)->v64[0] == (y)->v64[0]) && ((x)->v64[1] == (y)->v64[1]))


#ifdef NO_64BIT_MATH
#define _v128_xor_eq(z, x)         \
(                                  \
   (z)->v32[0] ^= (x)->v32[0],     \
   (z)->v32[1] ^= (x)->v32[1],     \
   (z)->v32[2] ^= (x)->v32[2],     \
   (z)->v32[3] ^= (x)->v32[3]      \
)
#else
#define _v128_xor_eq(z, x)         \
(                                  \
   (z)->v64[0] ^= (x)->v64[0],     \
   (z)->v64[1] ^= (x)->v64[1]      \
)
#endif

/* NOTE!  This assumes an odd ordering! */
/* This will not be compatible directly with math on some processors */
/* bit 0 is first 32-bit word, low order bit. in little-endian, that's
   the first byte of the first 32-bit word.  In big-endian, that's
   the 3rd byte of the first 32-bit word */
/* The get/set bit code is used by the replay code ONLY, and it doesn't
   really care which bit is which.  AES does care which bit is which, but
   doesn't use the 128-bit get/set or 128-bit shifts  */

#define _v128_get_bit(x, bit)                     \
(                                                 \
  ((((x)->v32[(bit) >> 5]) >> ((bit) & 31)) & 1)  \
)

#define _v128_set_bit(x, bit)                                    \
(                                                                \
  (((x)->v32[(bit) >> 5]) |= ((uint32_t)1 << ((bit) & 31))) \
)

#define _v128_clear_bit(x, bit)                                   \
(                                                                 \
  (((x)->v32[(bit) >> 5]) &= ~((uint32_t)1 << ((bit) & 31))) \
)

#define _v128_set_bit_to(x, bit, value)   \
(                                         \
   (value) ? _v128_set_bit(x, bit) :      \
             _v128_clear_bit(x, bit)      \
)


#if 0
/* nothing uses this */
#if WORDS_BIGENDIAN

#define _v128_add(z, x, y) {                    \
  uint64_t tmp;					\
    						\
  tmp = x->v32[3] + y->v32[3];                  \
  z->v32[3] = (uint32_t) tmp;			\
  						\
  tmp =  x->v32[2] + y->v32[2] + (tmp >> 32);	\
  z->v32[2] = (uint32_t) tmp;                   \
						\
  tmp =  x->v32[1] + y->v32[1] + (tmp >> 32);	\
  z->v32[1] = (uint32_t) tmp;			\
                                                \
  tmp =  x->v32[0] + y->v32[0] + (tmp >> 32);	\
  z->v32[0] = (uint32_t) tmp;			\
}

#else /* assume little endian architecture */

#define _v128_add(z, x, y) {                    \
  uint64_t tmp;					\
						\
  tmp = htonl(x->v32[3]) + htonl(y->v32[3]);	\
  z->v32[3] = ntohl((uint32_t) tmp);		\
  						\
  tmp =  htonl(x->v32[2]) + htonl(y->v32[2])	\
       + htonl(tmp >> 32);			\
  z->v32[2] = ntohl((uint32_t) tmp);		\
                                                \
  tmp =  htonl(x->v32[1]) + htonl(y->v32[1])	\
       + htonl(tmp >> 32);			\
  z->v32[1] = ntohl((uint32_t) tmp);		\
  						\
  tmp =  htonl(x->v32[0]) + htonl(y->v32[0])	\
       + htonl(tmp >> 32);			\
  z->v32[0] = ntohl((uint32_t) tmp);		\
}
#endif /* WORDS_BIGENDIAN */                      
#endif /* 0 */


#ifdef DATATYPES_USE_MACROS  /* little functions are really macros */

#define v128_set_to_zero(z)       _v128_set_to_zero(z)
#define v128_copy(z, x)           _v128_copy(z, x)
#define v128_xor(z, x, y)         _v128_xor(z, x, y)
#define v128_and(z, x, y)         _v128_and(z, x, y)
#define v128_or(z, x, y)          _v128_or(z, x, y)
#define v128_complement(x)        _v128_complement(x) 
#define v128_is_eq(x, y)          _v128_is_eq(x, y)
#define v128_xor_eq(x, y)         _v128_xor_eq(x, y)
#define v128_get_bit(x, i)        _v128_get_bit(x, i)
#define v128_set_bit(x, i)        _v128_set_bit(x, i)
#define v128_clear_bit(x, i)      _v128_clear_bit(x, i)
#define v128_set_bit_to(x, i, y)  _v128_set_bit_to(x, i, y)

#else

void
v128_set_to_zero(v128_t *x);

int
v128_is_eq(const v128_t *x, const v128_t *y);

void
v128_copy(v128_t *x, const v128_t *y);

void
v128_xor(v128_t *z, v128_t *x, v128_t *y);

void
v128_and(v128_t *z, v128_t *x, v128_t *y);

void
v128_or(v128_t *z, v128_t *x, v128_t *y); 

void
v128_complement(v128_t *x);

int
v128_get_bit(const v128_t *x, int i);

void
v128_set_bit(v128_t *x, int i) ;     

void
v128_clear_bit(v128_t *x, int i);    

void
v128_set_bit_to(v128_t *x, int i, int y);

#endif /* DATATYPES_USE_MACROS */

/*
 * octet_string_is_eq(a,b, len) returns 1 if the length len strings a
 * and b are not equal, returns 0 otherwise
 */

int
octet_string_is_eq(octet_t *a, octet_t *b, int len);

void
octet_string_set_to_zero(octet_t *s, int len);


/* 
 * bswap_32() is an optimized version of htonl/ntohl
 */

uint32_t
bswap_32(uint32_t v);

uint64_t
bswap_64(uint64_t v);


#endif /* _DATATYPES_H */