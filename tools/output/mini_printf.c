/*
** EPITECH PROJECT, 2023
** MINI_PRINTF
** File description:
** a basic reproduction of printf
*/

#include "../../include/utility.h"

int specifier(char const *str, int i, va_list *args)
{
    if (str[i + 1] == 'd' || str[i + 1] == 'i') {
        my_put_nbr(va_arg(*args, int));
    }
    if (str[i + 1] == 'c') {
        my_putchar(va_arg(*args, int));
    }
    if (str[i + 1] == 's') {
        my_putstr(va_arg(*args, char *));
    }
    if (str[i + 1] == '%') {
        my_putchar('%');
    }
    if (str[i + 1] == ' ') {
        my_putchar('%');
        my_putchar(' ');
    }
    return i + 1;
}

int mini_printf(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i = specifier(format, i, &args);
        } else {
            write(1, &(format[i]), 1);
        }
        i++;
    }
    va_end(args);
    return i;
}
