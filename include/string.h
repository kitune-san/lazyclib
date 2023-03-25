/**
 * @file  string.h
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
#include <stddef.h>

char *strcpy(char *s, const char *ct);
char *strncpy(char *s, const char *ct, size_t n);
char *strcat(char *s, const char *ct);
char *strncat(char *s, const char *ct, size_t n);
int strcmp(const char *cs, const char *ct);
int strncmp(const char *cs, const char *ct, size_t n);
char *strchr(const char *cs, int c);
char *strrchr(const char *cs, int c);
size_t strspn(const char *cs, const char *ct);
size_t strcspn(const char *cs, const char *ct);
char *strpbrk(const char *cs, const char *ct);
char *strstr(const char *cs, const char *ct);
size_t strlen(const char *cs);
char *strtok_r(char *str, const char *delm, char **saveptr);
char *strtok(char *s, const char *ct);
void *memcpy(void *s, const void *ct, size_t n);
void *memmove(void *s, const void *ct, size_t n);
int memcmp(const void *cs, const void *ct, size_t n);
void *memchr(const void *cs, int c, size_t n);
void *memset(void *s, int c, size_t n);

