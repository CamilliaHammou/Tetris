/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** tetris
*/

#include "my.h"

static tetris_t *tetris;

tetris_t *get_tetris()
{
    return tetris;
}

void new_tetris()
{
    tetris = malloc(sizeof(tetris_t));
    tetris->map_format = malloc(sizeof(vec2d_t));
    tetris->map_format->x = 20;
    tetris->map_format->y = 10;
    tetris->level = 1;
    tetris->key_left = 68;
    tetris->key_right = 67;
    tetris->key_turn = 65;
    tetris->key_drop = 66;
    tetris->key_quit = 'q';
    tetris->key_pause = ' ';
}

void start_tetris(int ac, char **av)
{
    new_tetriminos_manager();
    if (!tetris->one_tetrimino_valid) {
        exit(84);
    }
    handle_command(ac, av);
    if (tetris->should_debug && !tetris->should_help) {
        print_debug();
    }
}

int main(int ac, char **av)
{
    new_tetris();
    start_tetris(ac, av);
    if (!tetris->should_debug && !tetris->should_help) {
        start_game(ac, av);
    }
    return 0;
}
