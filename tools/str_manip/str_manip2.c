/*
** EPITECH PROJECT, 2024
** My_tools
** File description:
** str functions
*/

#include "../../include/utility.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 1));

    for (; dest[i] != '\0'; i++)
        res[i] = dest[i];
    for (a; src[a] != '\0'; a++) {
        res[i] = src[a];
        i++;
    }
    res[i] = '\0';
    return res;
}

char *my_strcat_paths(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 2));

    for (; dest[i] != '\0'; i++)
        res[i] = dest[i];
    res[i] = '/';
    i++;
    for (; src[a] != '\0'; a++) {
        res[i] = src[a];
        i++;
    }
    res[i] = '\0';
    return res;
}

char *load_file(char *filepath)
{
    char *buf;
    int i;
    int fd;
    struct stat file;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "Inexistant file\n", 16);
        return NULL;
    }
    if (stat(filepath, &file) == -1)
        return NULL;
    buf = malloc(sizeof(char) * (file.st_size + 1));
    if (read(fd, buf, file.st_size) <= 0)
        return NULL;
    buf[file.st_size] = '\0';
    close(fd);
    return buf;
}

char **my_tabdup(char **tab)
{
    int i = 0;
    int len = 0;
    char **dup;

    if (tab == NULL)
        return NULL;
    for (len; tab[len] != NULL; len++);
    dup = malloc(sizeof(char *) * (len + 1));
    for (i; tab[i] != NULL; i++)
        dup[i] = my_strdup(tab[i]);
    dup[i] = NULL;
    return dup;
}

char *my_revstr(char *str)
{
    char s;
    int len;
    int i = 0;
    int j;

    len = my_strlen(str);
    j = len - 1;
    while (i < (len / 2)) {
        s = str[i];
        str[i] = str[j];
        str[j] = s;
        i++;
        j--;
    }
    return str;
}
