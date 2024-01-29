/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** putnbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int z = 0, y = 0, run = 0, i = 0;
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb <= 9)
        my_putchar(nb + 48);
    else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (nb);
}
