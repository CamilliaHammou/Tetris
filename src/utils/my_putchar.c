/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-tetris-camillia.hammou
** File description:
** my_putchar
*/

#include<unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
