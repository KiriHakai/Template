/*
** EPITECH PROJECT, 2024
** My_tools
** File description:
** Comparison functions
*/

#include "../../include/utility.h"

int my_char_is_alphanum(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    } else if ((c >= 48 && c <= 57)) {
        return 1;
    } else {
        return 0;
    }
}

int my_char_is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != 0 && s2[i] != 0) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return 0;
}
