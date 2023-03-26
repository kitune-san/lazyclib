#include <unistd.h>
#include "../TesUT/tesut.h"
#include "../TesUT/additions/tesut-lib.h"
#include "../TesUT/additions/tesut-console.h"
#include "../test_string.h"

void user_func_putc(const char c)
{
    write(1, &c, sizeof(c));
    return;
}

void _start(void)
{
    TESU_Initialize();
    Set_TESU_Putchar(user_func_putc);
    TESU_Set_Console_Handler();
    Test_String();
    _exit(0);
}

