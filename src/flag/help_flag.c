/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** help_flag
*/

#include "my.h"

void print_help(void)
{
    file_t *help_file = create_file_reader("resources/help.txt");
    my_putstr(help_file->content);
    get_tetris()->should_help = true;
    exit(0);
}
