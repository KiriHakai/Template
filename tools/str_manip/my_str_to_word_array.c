/*
** EPITECH PROJECT, 2023
** MY_STR_TO_WORD_ARRAY
** File description:
** takes a string, returns an array of strings
*/

#include "../../include/utility.h"


int count_lines(char const *str, char delim)
{
    int i = 0;
    int j = 0;

    if (str[0] == '\0')
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            j++;
        }
    }
    if (str[i - 1] != delim)
        j++;
    return j;
}

char **fill_tabs(char **tab, char const *str, char delim)
{
    int i = 0;
    int j = 0;
    int a = 0;

    while (i < count_lines(str, delim) && str[a] != '\0') {
        if (str[a] == delim || str[a] == '\t') {
            a++;
        }
        while (str[a] != delim && str[a] != '\t' && str[a] != '\0') {
            tab[i][j] = str[a];
            a++;
            j++;
        }
        tab[i][j] = '\0';
        j = 0;
        if (tab[i][j] != '\0')
            i++;
    }
    tab[i] = NULL;
    return tab;
}

int longest_line(char const *str, char delim)
{
    int len = my_strlen(str);
    int i = 0;
    int j = 0;
    int lg = 0;

    while (i <= len) {
        while (str[i] != delim && str[i] != '\0') {
            j++;
            i++;
        }
    lg = (j > lg ? j : lg);
        j = 0;
        i++;
    }
    return lg;
}

char **my_str_to_word_array(char const *str, char delim)
{
    int lines;
    char **tab;
    int lg;
    int i = 0;
    int j = 0;
    int a = 0;

    lines = count_lines(str, delim) + 1;
    if (lines == 0)
        return NULL;
    tab = malloc(sizeof(char *) * lines);
    tab[lines - 1] = NULL;
    lg = longest_line(str, delim) + 1;
    while (i < (lines - 1)) {
        tab[i] = malloc(sizeof(char) * lg);
        i++;
    }
    tab = fill_tabs(tab, str, delim);
    return tab;
}
