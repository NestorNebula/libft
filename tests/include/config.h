#ifndef CONFIG_H

#define CONFIG_H

#include <bsd/string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

#ifndef NMEMB
#define NMEMB 10
#endif /* ifndef NMEMB */

#ifndef SIZE
#define SIZE 8
#endif /* ifndef SIZE */

#ifndef POSNBR
#define POSNBR 42
#endif /* ifndef POSNBR */

#ifndef POSSTR
#define POSSTR "42"
#endif /* ifndef POSSTR */

#ifndef POSLEN
#define POSLEN 2
#endif /* ifndef POSLEN */

#ifndef NEGNBR
#define NEGNBR -42
#endif /* ifndef NEGNBR */

#ifndef NEGSTR
#define NEGSTR "-42"
#endif /* ifndef NEGSTR */

#ifndef NEGLEN
#define NEGLEN 3
#endif /* ifndef NEGLEN */

#ifndef STR
#define STR "Test string"
#endif /* ifndef STR */

#ifndef SUBSTR
#define SUBSTR "str"
#endif /* ifndef SUBSTR */

#ifndef STR_SIZE
#define STR_SIZE 12
#endif /* ifndef STR_SIZE */

#ifndef STR1
#define STR1 "Test string 1"
#endif /* ifndef STR1 */

#ifndef STR2
#define STR2 "Test string 2"
#endif /* ifndef STR2 */

#ifndef STR3
#define STR3 "Test string 3"
#endif /* ifndef STR3 */

#ifndef STR_COUNT
#define STR_COUNT 3
#endif /* ifndef STR_COUNT */

#ifndef FILENAME
#define FILENAME "testfile"
#endif /* ifndef FILENAME */

#endif /* end of include guard: CONFIG_H */
