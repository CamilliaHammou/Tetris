/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-tetris-camillia.hammou
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar (str[i]);
        i = i + 1;
    }
    return (0);
}
