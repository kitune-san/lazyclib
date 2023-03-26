# lazyclib
C lib for freestanding environment (WIP)

## Description
This is a C library intended for use in a free standing or small embedded environment.

The goal is to make this library available in many development environments by copying and pasting without any troublesome work.
Therefore, functions that perform standard input/output such as scanf/scanf are not implemented (or no plans to do so).

This library is also licensed under a 1-clause BSD license. When distributing in binary form, there is no need to provide a display or paper to show the license.

## Functions

1. string.h

|Function|Implemented    |
|--------|---------------|
|strcpy  |Implemented    |
|strncpy |Implemented    |
|strcat  |Implemented    |
|strncat |Implemented    |
|strcmp  |Implemented    |
|strncmp |Implemented    |
|strchr  |Implemented    |
|strrchr |Implemented    |
|strspn  |Implemented    |
|strcspn |Implemented    |
|strpbrk |Implemented    |
|strstr  |Implemented    |
|strlen  |Implemented    |
|strerror|Not implemented|
|strtok_r|Implemented    |
|strtok  |Implemented    |
|memcpy  |Implemented    |
|memmove |Implemented    |
|memcmp  |Implemented    |
|memchr  |Implemented    |
|memset  |Implemented    |


