/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** takes a string, returns an array of strings
*/

#include "../../include/utility.h"

char **fill_t(char **tab, char const *str)
{
    int i = 0;
    int j = 0;
    int a = 0;

    while (tab[j] != NULL) {
        if (str[a] == '\n') {
            a++;
        }
        while (str[a] != '\n') {
            tab[j][i] = str[a];
            a++;
            i++;
        }
        tab[j][i] = '\0';
        i = 0;
        j++;
    }
    return tab;
}

int count_l(char const *str)
{
    int i;
    int j = 0;

    if (str[0] == '\0')
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
    }
    return j;
}

int longest_l(char const *str)
{
    int i = 0;
    int j = 0;
    int lg = 0;

    while (str[i] != '\0') {
        while (str[i] != '\n' && str[i] != '\0') {
            j++;
            i++;
        }
        if (j > lg)
            lg = j;
        j = 0;
        i++;
    }
    return lg;
}

char **my_str_to_tab(char const *str)
{
    int lines;
    char **tab;
    int lg;
    int i = 0;
    int j = 0;
    int a = 0;

    lines = count_l(str) + 1;
    if (lines == 0)
        return NULL;
    tab = malloc(lines * sizeof(char *));
    tab[lines - 1] = NULL;
    lg = longest_l(str) + 1;
    while (i < (lines - 1)) {
        tab[i] = malloc(lg * sizeof(char));
        i++;
    }
    return fill_t(tab, str);
}
