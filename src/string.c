/**
 * @file  string.c
 * @brief lazyclib string functions
 *
 * Copyright (c) 2023, kitune-san
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <string.h>

/**
 * @brief   strcpy
 * @param   [out] s   destination
 * @param   [in]  ct  source string
 * @return  s
 */
char *strcpy(char *s, const char *ct)
{
    char *ret;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    ret = s;

    while (1) {
        *s = *ct;
        if (*ct == '\0') {
            break;
        }
        ++s;
        ++ct;
    }

    return ret;
}

/**
 * @brief   strncpy
 * @param   [out] s   destination
 * @param   [in]  ct  source string
 * @param   [in]  n   size of source string
 * @return  s
 */
char *strncpy(char *s, const char *ct, size_t n)
{
    char *ret;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    ret = s;

    while (n > 0) {
        --n;
        *s = *ct;
        ++s;
        if (*ct == '\0') {
            break;
        }
        ++ct;
    }

    while (n > 0) {
        --n;
        *s = '\0';
        ++s;
    }

    return ret;
}

/**
 * @brief   strcat
 * @param   [in,out]  s   string1
 * @param   [in]      ct  string2
 * @return  s
 */
char *strcat(char *s, const char *ct)
{
    char *ret;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    ret = s;

    while (*s != '\0') {
        ++s;
    }

    strcpy(s, ct);

    return ret;
}

/**
 * @brief   strncat
 * @param   [in,out]  s   string1
 * @param   [in]      ct  string2
 * @param   [in]      n   size of string2
 * @return  s
 */
char *strncat(char *s, const char *ct, size_t n)
{
    char *ret;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    ret = s;

    while (*s != '\0') {
        ++s;
    }

    while (n > 0) {
        --n;
        *s = *ct;
        if (*ct == '\0') {
            break;
        }
        ++s;
        ++ct;
    }

    *s = '\0';

    return ret;
}

/**
 * @brief   strcmp
 * @param   [in]      cs  string1
 * @param   [in]      ct  string2
 * @retval  0         string1 == string2
 * @retval  <0        string1 <  string2
 * @retval  >0        string1 >  string2
 */
int strcmp(const char *cs, const char *ct)
{
    const unsigned char *str1;
    const unsigned char *str2;
    int diff;

    if (cs == NULL) {
        if (ct == NULL) return  0;
        else            return -1;
    }
    if (ct == NULL)     return  1;

    str1 = (const unsigned char *)cs;
    str2 = (const unsigned char *)ct;

    while (1) {
        diff = (int)*str1 - (int)*str2;
        if (0 != diff) {
            break;
        }
        if (*str1 == '\0') {
            break;
        }
        ++str1;
        ++str2;
    }

    return diff;
}

/**
 * @brief   strncmp
 * @param   [in]      cs  string1
 * @param   [in]      ct  string2
 * @param   [in]      n   size of string
 * @retval  0         string1 == string2
 * @retval  <0        string1 <  string2
 * @retval  >0        string1 >  string2
 */
int strncmp(const char *cs, const char *ct, size_t n)
{
    const unsigned char *str1;
    const unsigned char *str2;
    int diff = 0;

    if (cs == NULL) {
        if (ct == NULL) return  0;
        else            return -1;
    }
    if (ct == NULL)     return  1;

    str1 = (const unsigned char *)cs;
    str2 = (const unsigned char *)ct;

    while (n > 0) {
        --n;
        diff = (int)*str1 - (int)*str2;
        if (0 != diff) {
            break;
        }
        if (*str1 == '\0') {
            break;
        }
        ++str1;
        ++str2;
    }

    return diff;
}

/**
 * @brief   strchr
 * @paran   [in]      cs  search target string
 * @paran   [in]      c   search character
 * @return  Pointer to the first character matched to c
 */
char *strchr(const char *cs, int c)
{
    char *ret = NULL;

    if (cs == NULL) return NULL;

    while (1) {
        if (*cs == (char)c) {
            ret = (char *)cs;
            break;
        }
        if (*cs == '\0') {
            break;
        }
        ++cs;
    }

    return ret;
}

/**
 * @brief   strrchr
 * @paran   [in]      cs  search target string
 * @paran   [in]      c   search character
 * @return  Pointer to the last character matched to c
 */
char *strrchr(const char *cs, int c)
{
    char *ret = NULL;

    if (cs == NULL) return NULL;

    while (1) {
        if (*cs == (char)c) {
            ret = (char *)cs;
        }
        if (*cs == '\0') {
            break;
        }
        ++cs;
    }

    return ret;
}

/**
 * @brief   strspn
 * @paran   [in]      cs  search target string
 * @paran   [in]      ct  search characters
 * @return  Length of cs prefix consisting of characters in ct
 */
size_t strspn(const char *cs, const char *ct)
{
    size_t i = 0;
    size_t search;

    if (cs == NULL) return 0;
    if (ct == NULL) return 0;

    while (*cs != '\0') {
        search = 0;
        while (ct[search] != *cs) {
            if (ct[search] == '\0') {
                goto NO_MATCH;
            }
            ++search;
        }
        ++i;
        ++cs;
    }

NO_MATCH:
    return i;
}

/**
 * @brief   strcspn
 * @paran   [in]      cs  search target string
 * @paran   [in]      ct  search characters
 * @return  Length of cs prefix not consisting of characters in ct
 */
size_t strcspn(const char *cs, const char *ct)
{
    size_t i = 0;
    size_t search;

    if (cs == NULL) return 0;
    if (ct == NULL) {
        ct = "\0";
    };

    while (*cs != '\0') {
        search = 0;
        while (ct[search] != '\0') {
            if (ct[search] == *cs) {
                goto MATCH;
            }
            ++search;
        }
        ++i;
        ++cs;
    }

MATCH:
    return i;
}

/**
 * @brief   strpbrk
 * @paran   [in]      cs  search target string
 * @paran   [in]      ct  search characters
 * @return  Pointer to the character matched to ct
 */
char *strpbrk(const char *cs, const char *ct)
{
    char *ret = NULL;
    size_t search;

    if (cs == NULL) return NULL;
    if (ct == NULL) return NULL;

    while (*cs != '\0') {
        search = 0;
        while (ct[search] != '\0') {
            if (ct[search] == *cs) {
                ret = (char *)cs;
                goto MATCH;
            }
            ++search;
        }
        ++cs;
    }

MATCH:
    return ret;
}

/**
 * @brief   strstr
 * @paran   [in]      cs  search target string
 * @paran   [in]      ct  search string
 * @return  Pointer to the string matched to ct
 */
char *strstr(const char *cs, const char *ct)
{
    char *ret = NULL;
    size_t search;

    if (cs == NULL)   return NULL;
    if (ct == NULL)   return (char *)cs;
    if (*ct == '\0')  return (char *)cs;

    while (*cs != '\0') {
        search = 0;
        while (ct[search] == cs[search]) {
            ++search;
            if (ct[search] == '\0') {
                ret = (char *)cs;
                goto MATCH;
            }
        }
        ++cs;
    }

MATCH:
    return ret;
}

/**
 * @brief   strlen
 * @paran   [in]      cs  string
 * @return  length of cs
 */
size_t strlen(const char *cs)
{
    size_t i = 0;

    if (cs == NULL) return 0;

    while (*cs != '\0') {
        ++cs;
        ++i;
    }

    return i;
}

/**
 * @brief   strtok_r
 * @paran   [in,out]  str     string
 * @paran   [in]      delm    delimiter
 * @paran   [in,out]  saveptr state save pointer
 * @return  Pointer to delimited string
 */
char *strtok_r(char *str, const char *delm, char **saveptr)
{
    char *ret = NULL;
    char *next;
    size_t i;

    if (str == NULL) {
        if (saveptr == NULL)  return NULL;
        if (*saveptr == NULL) return NULL;
        str = *saveptr;
    }
    if (delm == NULL) {
        delm = "\0";
    }

    i = strcspn(str, delm);
    next = &str[i];
    if (i != 0) {
        ret = str;

        if (*next != '\0') {
            *next = '\0';
            ++next;
            i = strspn(next, delm);
            next = &next[i];
        }
    }

    if (saveptr != NULL) {
        *saveptr = next;
    }

    return ret;
}

/**
 * @brief   strtok
 * @paran   [in,out]  s   string
 * @paran   [in]      ct  delimiter
 * @return  Pointer to delimited string
 */
char *strtok(char *s, const char *ct)
{
    static char *save = NULL;
    return strtok_r(s, ct, &save);
}

/**
 * @brief   memcpy
 * @param   [out] s   destination
 * @param   [in]  ct  source
 * @param   [in]  n   copy count
 * @return  s
 */
void *memcpy(void *s, const void *ct, size_t n)
{
    unsigned char *dest;
    const unsigned char *src;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    dest  = (unsigned char *)s;
    src   = (const unsigned char *)ct;

    while (n > 0) {
        --n;
        *dest = *src;
        ++dest;
        ++src;
    }

    return s;
}

/**
 * @brief   memmove
 * @param   [out] s   destination
 * @param   [in]  ct  source
 * @param   [in]  n   copy count
 * @return  s
 */
void *memmove(void *s, const void *ct, size_t n)
{
    unsigned char *dest;
    const unsigned char *src;

    if (s  == NULL) return s;
    if (ct == NULL) return s;

    dest  = (unsigned char *)s;
    src   = (const unsigned char *)ct;

    if (dest <= src) {
        while (n > 0) {
            --n;
            *dest = *src;
            ++dest;
            ++src;
        }
    } else {
        while (n > 0) {
            --n;
            dest[n] = src[n];
        }
    }

    return s;
}

/**
 * @brief   memcmp
 * @param   [in]      cs  memory1
 * @param   [in]      ct  memory2
 * @param   [in]      n   size of memory
 * @retval  0         memory1 == memory2
 * @retval  <0        memory1 <  memory2
 * @retval  >0        memory1 >  memory2
 */
int memcmp(const void *cs, const void *ct, size_t n)
{
    const unsigned char *mem1;
    const unsigned char *mem2;
    int diff = 0;

    if (cs == NULL) {
        if (ct == NULL) return  0;
        else            return -1;
    }
    if (ct == NULL)     return  1;

    mem1 = (const unsigned char *)cs;
    mem2 = (const unsigned char *)ct;

    while (n > 0) {
        --n;
        diff = (int)*mem1 - (int)*mem2;
        if (0 != diff) {
            break;
        }
        ++mem1;
        ++mem2;
    }

    return diff;
}

/**
 * @brief   memchr
 * @paran   [in]      cs  search target memory
 * @paran   [in]      c   search character
 * @param   [in]      n   size of memory
 * @return  Pointer to the first character matched to c
 */
void *memchr(const void *cs, int c, size_t n)
{
    void *ret = NULL;
    const unsigned char *mem;

    if (cs == NULL) return NULL;

    mem = (const unsigned char *)cs;

    while (n > 0) {
        --n;
        if (*mem == (unsigned char)c) {
            ret = (void *)mem;
            break;
        }
        ++mem;
    }

    return ret;
}

/**
 * @brief   memset
 * @paran   [out]     s   search target memory
 * @paran   [in]      c   set character
 * @param   [in]      n   size of memory
 * @return  s
 */
void *memset(void *s, int c, size_t n)
{
    unsigned char *mem;

    if (s == NULL) return s;

    mem = (unsigned char *)s;

    while (n > 0) {
        --n;
        *mem = (unsigned char)c;
        ++mem;
    }

    return s;
}

