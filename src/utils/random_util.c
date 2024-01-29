/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** random
*/

#include "my.h"

void update_seed(void)
{
    srand(time(NULL));
}

int random_int(int range)
{
    update_seed();
    return rand() % (range + 1);
}

int random_in_range(int min, int max)
{
    update_seed();
    return random_int(max - min) + min;
}