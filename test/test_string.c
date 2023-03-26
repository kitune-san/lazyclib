#include "TesUT/tesut.h"
#include "string.h"

static void strcpy_test_01(void)
{
    char dest[7] = {'\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'A', 'B', 'C', '\0', 'D', 'E', 'F'};
    char *ret;

    ret = strcpy(dest, src);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strcpy_test_02(void)
{
    char dest[7] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'\0', 'A', 'B', 'C', 'D', 'E', 'F'};
    char *ret;

    ret = strcpy(dest, src);

    TESU_ASSERT_EQUAL(dest[0], '\0');
    TESU_ASSERT_EQUAL(dest[1], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[2], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[3], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}


static void strncpy_test_01(void)
{
    char dest[7] = {'\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'A', 'B', 'C', '\0', 'D', 'E', 'F'};
    char *ret;

    ret = strncpy(dest, src, 2);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[3], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncpy_test_02(void)
{
    char dest[7] = {'\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'A', 'B', 'C', '\0', 'D', 'E', 'F'};
    char *ret;

    ret = strncpy(dest, src, 6);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], '\0');
    TESU_ASSERT_EQUAL(dest[5], '\0');
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncpy_test_03(void)
{
    char dest[7] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'\0', 'A', 'B', 'C', 'D', 'E', 'F'};
    char *ret;

    ret = strncpy(dest, src, 6);

    TESU_ASSERT_EQUAL(dest[0], '\0');
    TESU_ASSERT_EQUAL(dest[1], '\0');
    TESU_ASSERT_EQUAL(dest[2], '\0');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], '\0');
    TESU_ASSERT_EQUAL(dest[5], '\0');
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncpy_test_04(void)
{
    char dest[7] = {'\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'A', 'B', 'C', '\0', 'D', 'E', 'F'};
    char *ret;

    ret = strncpy(dest, src, 0);

    TESU_ASSERT_EQUAL(dest[0], '\0');
    TESU_ASSERT_EQUAL(dest[1], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[2], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[3], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strcat_test_01(void)
{
    char dest[10] = {'A', 'B', 'C', '\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'D', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strcat(dest, src);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], 'D');
    TESU_ASSERT_EQUAL(dest[4], 'E');
    TESU_ASSERT_EQUAL(dest[5], 'F');
    TESU_ASSERT_EQUAL(dest[6], '\0');
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strcat_test_02(void)
{
    char dest[10] = {'\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'D', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strcat(dest, src);

    TESU_ASSERT_EQUAL(dest[0], 'D');
    TESU_ASSERT_EQUAL(dest[1], 'E');
    TESU_ASSERT_EQUAL(dest[2], 'F');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strcat_test_03(void)
{
    char dest[10] = {'A', 'B', 'C', '\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'\0', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strcat(dest, src);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncat_test_01(void)
{
    char dest[10] = {'A', 'B', 'C', '\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'D', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strncat(dest, src, 2);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], 'D');
    TESU_ASSERT_EQUAL(dest[4], 'E');
    TESU_ASSERT_EQUAL(dest[5], '\0');
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncat_test_02(void)
{
    char dest[10] = {'A', 'B', 'C', '\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'D', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strncat(dest, src, 7);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], 'D');
    TESU_ASSERT_EQUAL(dest[4], 'E');
    TESU_ASSERT_EQUAL(dest[5], 'F');
    TESU_ASSERT_EQUAL(dest[6], '\0');
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strncat_test_03(void)
{
    char dest[10] = {'A', 'B', 'C', '\0', 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char src[7]  = {'D', 'E', 'F', '\0', 'H', 'I', 'J'};
    char *ret;

    ret = strncat(dest, src, 0);

    TESU_ASSERT_EQUAL(dest[0], 'A');
    TESU_ASSERT_EQUAL(dest[1], 'B');
    TESU_ASSERT_EQUAL(dest[2], 'C');
    TESU_ASSERT_EQUAL(dest[3], '\0');
    TESU_ASSERT_EQUAL(dest[4], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[5], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[6], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[7], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[8], (char)0xFF);
    TESU_ASSERT_EQUAL(dest[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(dest, ret);

    return;
}

static void strcmp_test_01(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strcmp(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strcmp_test_02(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', '\0', '\0'};
    int ret;

    ret = strcmp(str1, str2);

    TESU_ASSERT(ret > 0);

    return;
}

static void strcmp_test_03(void)
{
    char str1[5] = {'A', 'B', 'C', '\0', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strcmp(str1, str2);

    TESU_ASSERT(ret < 0);

    return;
}

static void strcmp_test_04(void)
{
    char str1[5] = {'A', 'B', 'C', 'E', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strcmp(str1, str2);

    TESU_ASSERT(ret > 0);

    return;
}

static void strcmp_test_05(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', 'E', '\0'};
    int ret;

    ret = strcmp(str1, str2);

    TESU_ASSERT(ret < 0);

    return;
}

static void strncmp_test_01(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strncmp(str1, str2, 5);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strncmp_test_02(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', '\0', '\0'};
    int ret;

    ret = strncmp(str1, str2, 5);

    TESU_ASSERT(ret > 0);

    return;
}

static void strncmp_test_03(void)
{
    char str1[5] = {'A', 'B', 'C', '\0', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strncmp(str1, str2, 5);

    TESU_ASSERT(ret < 0);

    return;
}

static void strncmp_test_04(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'E', 'F', '\0'};
    int ret;

    ret = strncmp(str1, str2, 2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strncmp_test_05(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'E', 'F', '\0'};
    int ret;

    ret = strncmp(str1, str2, 3);

    TESU_ASSERT(ret < 0);

    return;
}

static void strncmp_test_06(void)
{
    char str1[5] = {'A', 'B', 'E', 'F', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strncmp(str1, str2, 3);

    TESU_ASSERT(ret > 0);

    return;
}

static void strncmp_test_07(void)
{
    char str1[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    int ret;

    ret = strncmp(str1, str2, 0);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strchr_test_01(void)
{
    char str[5] = {'A', 'B', 'B', 'C', '\0'};
    char *ret;

    ret = strchr(str, 'B');

    TESU_ASSERT_PTR_EQUAL(ret, &str[1]);

    return;
}

static void strchr_test_02(void)
{
    char str[5] = {'A', 'B', 'B', '\0', 'C'};
    char *ret;

    ret = strchr(str, 'C');

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strchr_test_03(void)
{
    char str[5] = {'A', 'B', 'B', '\0', 'C'};
    char *ret;

    ret = strchr(str, '\0');

    TESU_ASSERT_PTR_EQUAL(ret, &str[3]);

    return;
}

static void strrchr_test_01(void)
{
    char str[5] = {'A', 'B', 'B', 'C', '\0'};
    char *ret;

    ret = strrchr(str, 'B');

    TESU_ASSERT_PTR_EQUAL(ret, &str[2]);

    return;
}

static void strrchr_test_02(void)
{
    char str[5] = {'A', 'B', 'B', '\0', 'C'};
    char *ret;

    ret = strrchr(str, 'C');

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strrchr_test_03(void)
{
    char str[5] = {'A', 'B', 'B', '\0', '\0'};
    char *ret;

    ret = strrchr(str, '\0');

    TESU_ASSERT_PTR_EQUAL(ret, &str[3]);

    return;
}

static void strspn_test_01(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'A', 'B', '\0', 'C', 'D'};
    size_t ret;

    ret = strspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 4);

    return;
}

static void strspn_test_02(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'C', 'D', '\0', 'A', 'B'};
    size_t ret;

    ret = strspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strspn_test_03(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    size_t ret;

    ret = strspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 7);

    return;
}

static void strspn_test_04(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'\0', 'A', 'B', 'C', 'D'};
    size_t ret;

    ret = strspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strspn_test_05(void)
{
    char str1[8] = {'\0', 'A', 'B', 'B', 'A', 'C', 'A', 'B'};
    char str2[5] = {'A', 'B', 'C', 'D', '\0'};
    size_t ret;

    ret = strspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strcspn_test_01(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'C', 'D', '\0', 'A', 'B'};
    size_t ret;

    ret = strcspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 4);

    return;
}

static void strcspn_test_02(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'A', 'B', '\0', 'C', 'D'};
    size_t ret;

    ret = strcspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strcspn_test_03(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'D', 'E', 'F', 'G', '\0'};
    size_t ret;

    ret = strcspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 7);

    return;
}

static void strcspn_test_04(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    char str2[5] = {'\0', 'D', 'E', 'F', 'G'};
    size_t ret;

    ret = strcspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 7);

    return;
}

static void strcspn_test_05(void)
{
    char str1[8] = {'\0', 'A', 'B', 'B', 'A', 'C', 'A', 'B'};
    char str2[5] = {'D', 'E', 'F', 'G', '\0'};
    size_t ret;

    ret = strcspn(str1, str2);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strcspn_test_06(void)
{
    char str1[8] = {'A', 'B', 'B', 'A', 'C', 'A', 'B', '\0'};
    size_t ret;

    ret = strcspn(str1, NULL);

    TESU_ASSERT_EQUAL(ret, 7);

    return;
}

static void strpbrk_test_01(void)
{
    char str1[8] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};
    char str2[5] = {'B', 'D', 'E', '\0', 'A'};
    char *ret;

    ret = strpbrk(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[2]);

    return;
}

static void strpbrk_test_02(void)
{
    char str1[8] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};
    char str2[5] = {'I', 'J', 'K', '\0', 'A'};
    char *ret;

    ret = strpbrk(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strpbrk_test_03(void)
{
    char str1[8] = {'\0', 'A', 'C', 'D', 'E', 'F', 'G', 'H'};
    char str2[5] = {'B', 'D', 'E', '\0', 'A'};
    char *ret;

    ret = strpbrk(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);

    return;

}

static void strpbrk_test_04(void)
{
    char str1[8] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', '\0'};
    char str2[5] = {'\0', 'B', 'D', 'E', 'A'};
    char *ret;

    ret = strpbrk(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strstr_test_01(void)
{
    char str1[10] = {'A', 'B', 'D', 'E', 'D', 'D', 'E', 'F', 'G', '\0'};
    char str2[5] = {'D', 'E', 'F', '\0', 'A'};
    char *ret;

    ret = strstr(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[5]);

    return;
}

static void strstr_test_02(void)
{
    char str1[10] = {'A', 'B', 'D', 'E', 'D', 'D', 'E', 'F', 'G', '\0'};
    char str2[5] = {'H', 'I', 'J', '\0', 'A'};
    char *ret;

    ret = strstr(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strstr_test_03(void)
{
    char str1[10] = {'\0', 'A', 'B', 'D', 'E', 'D', 'D', 'E', 'F', 'G'};
    char str2[5] = {'D', 'E', 'F', '\0', 'A'};
    char *ret;

    ret = strstr(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void strstr_test_04(void)
{
    char str1[10] = {'A', 'B', 'D', 'E', 'D', 'D', 'E', 'F', 'G', '\0'};
    char str2[5] = {'\0', 'D', 'E', 'F', 'A'};
    char *ret;

    ret = strstr(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[0]);

    return;
}

static void strlen_test_01(void)
{
    char str[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0'};
    size_t ret;

    ret = strlen(str);

    TESU_ASSERT_EQUAL(ret, 9);

    return;
}

static void strlen_test_02(void)
{
    char str[10] = {'\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    size_t ret;

    ret = strlen(str);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void strtok_test_01(void)
{
    char str1[10] = {'A', 'B', '.', 'D', 'E', '/', 'G', 'H', 'I', '\0'};
    char str2[4] = {'.', '/', '\0', 'H'};
    char *ret;

    ret = strtok(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[0]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '/');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[3]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '\0');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[6]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '\0');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_NULL(ret);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '\0');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    return;
}

static void strtok_test_02(void)
{
    char str1[10] = {'A', 'B', '.', '.', '.', 'F', 'G', '/', 'I', '\0'};
    char str2[4] = {'.', '/', '\0', 'H'};
    char *ret;

    ret = strtok(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[0]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '.');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '/');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[5]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '.');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '\0');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[8]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '.');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '\0');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_NULL(ret);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '.');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '\0');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    return;
}

static void strtok_test_03(void)
{
    char str1[10] = {'A', 'B', '.', '/', '.', 'F', 'G', '/', 'I', '\0'};
    char str2[4] = {'.', '/', '\0', 'H'};
    char *ret;

    ret = strtok(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[0]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '/');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '/');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[5]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '\0');
    TESU_ASSERT_EQUAL(str1[3], '/');
    TESU_ASSERT_EQUAL(str1[4], '.');
    TESU_ASSERT_EQUAL(str1[5], 'F');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], '\0');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    return;
}

static void strtok_test_04(void)
{
    char str1[10] = {'\0', 'A', 'B', '.', 'D', 'E', '/', 'G', 'H', 'I'};
    char str2[4] = {'.', '/', '\0', 'H'};
    char *ret;

    ret = strtok(str1, str2);

    TESU_ASSERT_PTR_NULL(ret);
    TESU_ASSERT_EQUAL(str1[0], '\0');
    TESU_ASSERT_EQUAL(str1[1], 'A');
    TESU_ASSERT_EQUAL(str1[2], 'B');
    TESU_ASSERT_EQUAL(str1[3], '.');
    TESU_ASSERT_EQUAL(str1[4], 'D');
    TESU_ASSERT_EQUAL(str1[5], 'E');
    TESU_ASSERT_EQUAL(str1[6], '/');
    TESU_ASSERT_EQUAL(str1[7], 'G');
    TESU_ASSERT_EQUAL(str1[8], 'H');
    TESU_ASSERT_EQUAL(str1[9], 'I');

    return;
}

static void strtok_test_05(void)
{
    char str1[10] = {'A', 'B', '.', 'D', 'E', '/', 'G', 'H', 'I', '\0'};
    char str2[4]  = {'\0', '.', '/', 'H'};
    char *ret;

    ret = strtok(str1, str2);

    TESU_ASSERT_PTR_EQUAL(ret, &str1[0]);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '.');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '/');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    ret = strtok(NULL, str2);
    TESU_ASSERT_PTR_NULL(ret);
    TESU_ASSERT_EQUAL(str1[0], 'A');
    TESU_ASSERT_EQUAL(str1[1], 'B');
    TESU_ASSERT_EQUAL(str1[2], '.');
    TESU_ASSERT_EQUAL(str1[3], 'D');
    TESU_ASSERT_EQUAL(str1[4], 'E');
    TESU_ASSERT_EQUAL(str1[5], '/');
    TESU_ASSERT_EQUAL(str1[6], 'G');
    TESU_ASSERT_EQUAL(str1[7], 'H');
    TESU_ASSERT_EQUAL(str1[8], 'I');
    TESU_ASSERT_EQUAL(str1[9], '\0');

    return;
}

static void memcpy_test_01(void)
{
    char mem1[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char mem2[5] = {'A', 'B', 'C', 'D', 'E'};
    char *ret;

    ret = memcpy(mem1, mem2, 3);

    TESU_ASSERT_EQUAL(mem1[0], 'A');
    TESU_ASSERT_EQUAL(mem1[1], 'B');
    TESU_ASSERT_EQUAL(mem1[2], 'C');
    TESU_ASSERT_EQUAL(mem1[3], (char)0xFF);
    TESU_ASSERT_EQUAL(mem1[4], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(ret, mem1);

    return;
}

static void memcpy_test_02(void)
{
    char mem1[5] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char mem2[5] = {'A', 'B', 'C', 'D', 'E'};
    char *ret;

    ret = memcpy(mem1, mem2, 0);

    TESU_ASSERT_EQUAL(mem1[0], (char)0xFF);
    TESU_ASSERT_EQUAL(mem1[1], (char)0xFF);
    TESU_ASSERT_EQUAL(mem1[2], (char)0xFF);
    TESU_ASSERT_EQUAL(mem1[3], (char)0xFF);
    TESU_ASSERT_EQUAL(mem1[4], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(ret, mem1);

    return;
}

static void memmove_test_01(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[1], &mem[5], 3);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'F');
    TESU_ASSERT_EQUAL(mem[2], 'G');
    TESU_ASSERT_EQUAL(mem[3], 'H');
    TESU_ASSERT_EQUAL(mem[4], 'E');
    TESU_ASSERT_EQUAL(mem[5], 'F');
    TESU_ASSERT_EQUAL(mem[6], 'G');
    TESU_ASSERT_EQUAL(mem[7], 'H');
    TESU_ASSERT_EQUAL(mem[8], 'I');
    TESU_ASSERT_EQUAL(mem[9], 'J');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[1]);

    return;
}

static void memmove_test_02(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[5], &mem[1], 3);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'B');
    TESU_ASSERT_EQUAL(mem[2], 'C');
    TESU_ASSERT_EQUAL(mem[3], 'D');
    TESU_ASSERT_EQUAL(mem[4], 'E');
    TESU_ASSERT_EQUAL(mem[5], 'B');
    TESU_ASSERT_EQUAL(mem[6], 'C');
    TESU_ASSERT_EQUAL(mem[7], 'D');
    TESU_ASSERT_EQUAL(mem[8], 'I');
    TESU_ASSERT_EQUAL(mem[9], 'J');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[5]);

    return;
}

static void memmove_test_03(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[3], &mem[5], 5);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'B');
    TESU_ASSERT_EQUAL(mem[2], 'C');
    TESU_ASSERT_EQUAL(mem[3], 'F');
    TESU_ASSERT_EQUAL(mem[4], 'G');
    TESU_ASSERT_EQUAL(mem[5], 'H');
    TESU_ASSERT_EQUAL(mem[6], 'I');
    TESU_ASSERT_EQUAL(mem[7], 'J');
    TESU_ASSERT_EQUAL(mem[8], 'I');
    TESU_ASSERT_EQUAL(mem[9], 'J');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[3]);

    return;
}

static void memmove_test_04(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[5], &mem[3], 5);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'B');
    TESU_ASSERT_EQUAL(mem[2], 'C');
    TESU_ASSERT_EQUAL(mem[3], 'D');
    TESU_ASSERT_EQUAL(mem[4], 'E');
    TESU_ASSERT_EQUAL(mem[5], 'D');
    TESU_ASSERT_EQUAL(mem[6], 'E');
    TESU_ASSERT_EQUAL(mem[7], 'F');
    TESU_ASSERT_EQUAL(mem[8], 'G');
    TESU_ASSERT_EQUAL(mem[9], 'H');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[5]);

    return;
}

static void memmove_test_05(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[1], &mem[5], 0);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'B');
    TESU_ASSERT_EQUAL(mem[2], 'C');
    TESU_ASSERT_EQUAL(mem[3], 'D');
    TESU_ASSERT_EQUAL(mem[4], 'E');
    TESU_ASSERT_EQUAL(mem[5], 'F');
    TESU_ASSERT_EQUAL(mem[6], 'G');
    TESU_ASSERT_EQUAL(mem[7], 'H');
    TESU_ASSERT_EQUAL(mem[8], 'I');
    TESU_ASSERT_EQUAL(mem[9], 'J');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[1]);

    return;
}

static void memmove_test_06(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char *ret;

    ret = memmove(&mem[1], &mem[1], 5);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'B');
    TESU_ASSERT_EQUAL(mem[2], 'C');
    TESU_ASSERT_EQUAL(mem[3], 'D');
    TESU_ASSERT_EQUAL(mem[4], 'E');
    TESU_ASSERT_EQUAL(mem[5], 'F');
    TESU_ASSERT_EQUAL(mem[6], 'G');
    TESU_ASSERT_EQUAL(mem[7], 'H');
    TESU_ASSERT_EQUAL(mem[8], 'I');
    TESU_ASSERT_EQUAL(mem[9], 'J');
    TESU_ASSERT_PTR_EQUAL(ret, &mem[1]);

    return;
}

static void memcmp_test_01(void)
{
    char mem1[5] = {'A', 'B', 'C', 'D', 'E'};
    char mem2[5] = {'A', 'B', 'C', 'F', 'G'};
    int ret;

    ret = memcmp(mem1, mem2, 3);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void memcmp_test_02(void)
{
    char mem1[5] = {'A', 'B', 'C', 'D', 'G'};
    char mem2[5] = {'A', 'B', 'C', 'F', 'G'};
    int ret;

    ret = memcmp(mem1, mem2, 5);

    TESU_ASSERT(ret < 0);

    return;
}

static void memcmp_test_03(void)
{
    char mem1[5] = {'A', 'B', 'C', 'F', 'G'};
    char mem2[5] = {'A', 'B', 'C', 'D', 'G'};
    int ret;

    ret = memcmp(mem1, mem2, 5);

    TESU_ASSERT(ret > 0);

    return;
}

static void memcmp_test_04(void)
{
    char mem1[5] = {'A', 'B', 'C', 'D', 'E'};
    char mem2[5] = {'A', 'B', 'C', 'F', 'G'};
    int ret;

    ret = memcmp(mem1, mem2, 0);

    TESU_ASSERT_EQUAL(ret, 0);

    return;
}

static void memchr_test_01(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
    char *ret;

    ret = memchr(mem, 'C', 10);

    TESU_ASSERT_PTR_EQUAL(ret, &mem[2]);

    return;
}

static void memchr_test_02(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'F'};
    char *ret;

    ret = memchr(mem, 'F', 10);

    TESU_ASSERT_PTR_EQUAL(ret, &mem[9]);

    return;
}

static void memchr_test_03(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
    char *ret;

    ret = memchr(mem, 'F', 10);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void memchr_test_04(void)
{
    char mem[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
    char *ret;

    ret = memchr(mem, 'C', 0);

    TESU_ASSERT_PTR_NULL(ret);

    return;
}

static void memset_test_01(void)
{
    char mem[10] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char *ret;

    ret = memset(mem, 'A', 5);

    TESU_ASSERT_EQUAL(mem[0], 'A');
    TESU_ASSERT_EQUAL(mem[1], 'A');
    TESU_ASSERT_EQUAL(mem[2], 'A');
    TESU_ASSERT_EQUAL(mem[3], 'A');
    TESU_ASSERT_EQUAL(mem[4], 'A');
    TESU_ASSERT_EQUAL(mem[5], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[6], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[7], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[8], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(ret, mem);

    return;
}

static void memset_test_02(void)
{
    char mem[10] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    char *ret;

    ret = memset(mem, 'A', 0);

    TESU_ASSERT_EQUAL(mem[0], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[1], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[2], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[3], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[4], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[5], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[6], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[7], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[8], (char)0xFF);
    TESU_ASSERT_EQUAL(mem[9], (char)0xFF);
    TESU_ASSERT_PTR_EQUAL(ret, mem);

    return;
}

void Test_String(void)
{
    TESU_TEST Suite[] = {
        {strcpy_test_01,  "strcpy_test_01",  TESU_NO_FATAL},
        {strcpy_test_02,  "strcpy_test_02",  TESU_NO_FATAL},
        {strncpy_test_01, "strncpy_test_01", TESU_NO_FATAL},
        {strncpy_test_02, "strncpy_test_02", TESU_NO_FATAL},
        {strncpy_test_03, "strncpy_test_03", TESU_NO_FATAL},
        {strncpy_test_04, "strncpy_test_04", TESU_NO_FATAL},
        {strcat_test_01,  "strcat_test_01",  TESU_NO_FATAL},
        {strcat_test_02,  "strcat_test_02",  TESU_NO_FATAL},
        {strcat_test_03,  "strcat_test_03",  TESU_NO_FATAL},
        {strncat_test_01, "strncat_test_01", TESU_NO_FATAL},
        {strncat_test_02, "strncat_test_02", TESU_NO_FATAL},
        {strncat_test_03, "strncat_test_03", TESU_NO_FATAL},
        {strcmp_test_01,  "strcmp_test_01",  TESU_NO_FATAL},
        {strcmp_test_02,  "strcmp_test_02",  TESU_NO_FATAL},
        {strcmp_test_03,  "strcmp_test_03",  TESU_NO_FATAL},
        {strcmp_test_04,  "strcmp_test_04",  TESU_NO_FATAL},
        {strcmp_test_05,  "strcmp_test_05",  TESU_NO_FATAL},
        {strncmp_test_01, "strncmp_test_01", TESU_NO_FATAL},
        {strncmp_test_02, "strncmp_test_02", TESU_NO_FATAL},
        {strncmp_test_03, "strncmp_test_03", TESU_NO_FATAL},
        {strncmp_test_04, "strncmp_test_04", TESU_NO_FATAL},
        {strncmp_test_05, "strncmp_test_05", TESU_NO_FATAL},
        {strncmp_test_06, "strncmp_test_06", TESU_NO_FATAL},
        {strncmp_test_07, "strncmp_test_07", TESU_NO_FATAL},
        {strchr_test_01,  "strchr_test_01",  TESU_NO_FATAL},
        {strchr_test_02,  "strchr_test_02",  TESU_NO_FATAL},
        {strchr_test_03,  "strchr_test_03",  TESU_NO_FATAL},
        {strrchr_test_01, "strrchr_test_01", TESU_NO_FATAL},
        {strrchr_test_02, "strrchr_test_02", TESU_NO_FATAL},
        {strrchr_test_03, "strrchr_test_03", TESU_NO_FATAL},
        {strspn_test_01,  "strspn_test_01",  TESU_NO_FATAL},
        {strspn_test_02,  "strspn_test_02",  TESU_NO_FATAL},
        {strspn_test_03,  "strspn_test_03",  TESU_NO_FATAL},
        {strspn_test_04,  "strspn_test_04",  TESU_NO_FATAL},
        {strspn_test_05,  "strspn_test_05",  TESU_NO_FATAL},
        {strcspn_test_01, "strcspn_test_01", TESU_NO_FATAL},
        {strcspn_test_02, "strcspn_test_02", TESU_NO_FATAL},
        {strcspn_test_03, "strcspn_test_03", TESU_NO_FATAL},
        {strcspn_test_04, "strcspn_test_04", TESU_NO_FATAL},
        {strcspn_test_05, "strcspn_test_05", TESU_NO_FATAL},
        {strcspn_test_06, "strcspn_test_06", TESU_NO_FATAL},
        {strpbrk_test_01, "strpbrk_test_01", TESU_NO_FATAL},
        {strpbrk_test_02, "strpbrk_test_02", TESU_NO_FATAL},
        {strpbrk_test_03, "strpbrk_test_03", TESU_NO_FATAL},
        {strpbrk_test_04, "strpbrk_test_04", TESU_NO_FATAL},
        {strstr_test_01,  "strstr_test_01",  TESU_NO_FATAL},
        {strstr_test_02,  "strstr_test_02",  TESU_NO_FATAL},
        {strstr_test_03,  "strstr_test_03",  TESU_NO_FATAL},
        {strstr_test_04,  "strstr_test_04",  TESU_NO_FATAL},
        {strlen_test_01,  "strlen_test_01",  TESU_NO_FATAL},
        {strlen_test_02,  "strlen_test_02",  TESU_NO_FATAL},
        {strtok_test_01,  "strtok_test_01",  TESU_NO_FATAL},
        {strtok_test_02,  "strtok_test_02",  TESU_NO_FATAL},
        {strtok_test_03,  "strtok_test_03",  TESU_NO_FATAL},
        {strtok_test_04,  "strtok_test_04",  TESU_NO_FATAL},
        {strtok_test_05,  "strtok_test_05",  TESU_NO_FATAL},
        {memcpy_test_01,  "memcpy_test_01",  TESU_NO_FATAL},
        {memcpy_test_02,  "memcpy_test_02",  TESU_NO_FATAL},
        {memmove_test_01, "memmove_test_01", TESU_NO_FATAL},
        {memmove_test_02, "memmove_test_02", TESU_NO_FATAL},
        {memmove_test_03, "memmove_test_03", TESU_NO_FATAL},
        {memmove_test_04, "memmove_test_04", TESU_NO_FATAL},
        {memmove_test_05, "memmove_test_05", TESU_NO_FATAL},
        {memmove_test_06, "memmove_test_06", TESU_NO_FATAL},
        {memcmp_test_01,  "memcmp_test_01",  TESU_NO_FATAL},
        {memcmp_test_02,  "memcmp_test_02",  TESU_NO_FATAL},
        {memcmp_test_03,  "memcmp_test_03",  TESU_NO_FATAL},
        {memcmp_test_04,  "memcmp_test_04",  TESU_NO_FATAL},
        {memchr_test_01,  "memchr_test_01",  TESU_NO_FATAL},
        {memchr_test_02,  "memchr_test_02",  TESU_NO_FATAL},
        {memchr_test_03,  "memchr_test_03",  TESU_NO_FATAL},
        {memchr_test_04,  "memchr_test_04",  TESU_NO_FATAL},
        {memset_test_01,  "memset_test_01",  TESU_NO_FATAL},
        {memset_test_02,  "memset_test_02",  TESU_NO_FATAL},
        TESU_TEST_INFO_NULL
    };
    TESU_Start_Suite(Suite, NULL, NULL, "String");
    return;
}

