/*-
 * Copyright (c) 2012-2013 Jan Breuer,
 *
 * All Rights Reserved
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   scpi_utils.h
 * @date   Thu Nov 15 10:58:45 UTC 2012
 * 
 * @brief  Conversion routines and string manipulation routines
 * 
 * 
 */

#ifndef SCPI_UTILS_H
#define	SCPI_UTILS_H

#include <stdint.h>
#include "types.h"

#ifdef	__cplusplus
extern "C" {
#endif

    #define LOCAL __attribute__((visibility ("hidden")))

    char * strnpbrk(const char *str, size_t size, const char *set) LOCAL;
    bool_t compareStr(const char * str1, size_t len1, const char * str2, size_t len2) LOCAL;
    size_t longToStr(int32_t val, char * str, size_t len) LOCAL;
    size_t doubleToStr(double val, char * str, size_t len) LOCAL;
    size_t strToLong(const char * str, int32_t * val) LOCAL;
    size_t strToDouble(const char * str, double * val) LOCAL;
    bool_t locateText(const char * str1, size_t len1, const char ** str2, size_t * len2) LOCAL;
    bool_t locateStr(const char * str1, size_t len1, const char ** str2, size_t * len2) LOCAL;
    size_t skipWhitespace(const char * cmd, size_t len) LOCAL;
    bool_t matchPattern(const char * pattern, size_t pattern_len, const char * str, size_t str_len) LOCAL;

#define min(a, b)  (((a) < (b)) ? (a) : (b))
#define max(a, b)  (((a) > (b)) ? (a) : (b))

#if 0
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SCPI_UTILS_H */

