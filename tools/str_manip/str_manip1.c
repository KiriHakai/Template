/*
** EPITECH PROJECT, 2024
** My_tools
** File description:
** str functions
*/

#include "../../include/utility.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
        }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
        } else {
            return -1;
        }
        i++;
    }
    return (nb * sign);
}

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return a;
}

char *my_strdup(char *src)
{
    int i = 0;
    int len;
    char *dest;

    if (src == NULL)
        return NULL;
    len = my_strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    for (i; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
