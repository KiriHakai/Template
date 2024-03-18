/*
** EPITECH PROJECT, 2024
** My_tools
** File description:
** str functions
*/

int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strcat_paths(char *dest, char const *src);
char **my_str_to_word_array(char const *str, char delim);
char **my_str_to_tab(char const *str);
char **my_tok_to_wa(char *str, char *delim);
char *load_file(char *filepath);
char **my_tabdup(char **tab);

#pragma once
