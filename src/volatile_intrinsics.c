#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Memory functions.
 */

void *memset(void *dest, int c, size_t n) {
    uint8_t *d = (uint8_t*)dest;
    for (size_t i = 0; i < n; ++i) {
        d[i] = (uint8_t)c;
    }

    return dest;
}

void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *d = (uint8_t*)dest;
    uint8_t *s = (uint8_t*)src;
    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }

    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    uint8_t* from = (uint8_t*) src;
	uint8_t* to = (uint8_t*) dest;
    assert(n < INT64_MAX);

	if (from == to || n == 0) {
        return dest;
    }

	if (to > from && to-from < n) {
		/* to overlaps with from */
		/*  <from......>         */
		/*         <to........>  */
		/* copy in reverse, to avoid overwriting from */
		for(size_t i = n-1; i >= 0 && i < n; i--) {
            to[i] = from[i];
        }

        return dest;
	}

	if (from > to && from-to < (int)n) {
		/* to overlaps with from */
		/*        <from......>   */
		/*  <to........>         */
		/* copy forwards, to avoid overwriting from */

        for(size_t i=0; i < n; i++) {
            to[i] = from[i];
        }

        return dest;
	}

	return memcpy(dest, src, n);
}

/**
 * String functions.
 */

char *strcpy(char *dest, const char *src) {
    size_t i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    } 
    
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }     
    for ( ; i < n; i++) {
        dest[i] = '\0';
    }  

    return dest;
}

