/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** window_size
*/

#include "my.h"

void check_window_size(WINDOW *window)
{
    int x = 0, y = 0;
	getmaxyx(window, y, x);
    if (x <= 85 || y <= 25) {
        endwin();
        my_putstr("Your terminal window is too small, please enlarge it to atleast 125x125\n");
        exit(84);
    }
}