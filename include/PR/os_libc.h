#ifndef _OS_LIBC_H_
#define _OS_LIBC_H_

#include "ultratypes.h"

// old bstring functions that aren't present on some platforms

#if defined(__APPLE__) || defined(__HAIKU__)

// macOS libc has them
#include <strings.h>

#elif defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE >= 200809L) || defined(NO_BZERO_BCOPY)

// there's no way that shit's defined, use memcpy/memset
#include <string.h>
#undef bzero
#undef bcopy
#define bzero(buf, len) memset((buf), 0, (len))
#define bcopy(src, dst, len) memcpy((dst), (src), (len))

#else

// hope for the best
extern void bcopy(const void *, void *, size_t);
extern void bzero(void *, size_t);

#ifdef TARGET_XBOX
#include <string.h>
#define bcopy(src, dst, size) memcpy(dst, src, size)
#define bzero(dst, size) memset(dst, 0, size)
#endif

#endif

#endif /* !_OS_LIBC_H_ */
