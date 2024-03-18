/*
** EPITECH PROJECT, 2024
** My_tools
** File description:
** Output functions
*/

#include "../../include/utility.h"

int auto_writer(int fd, char *str, int exit_status)
{
    write(fd, str, my_strlen(str));
    return exit_status;
}

void my_put_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    for (; tab[i] != NULL; i++)
        mini_printf("%s\n", tab[i]);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    } else if (nb < 10) {
        my_putchar(nb + '0');
        return 0;
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}
