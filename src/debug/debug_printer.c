/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** debug_printer
*/

#include "my.h"

void print_number_values_two(void)
{
    my_putstr("Key drop: ");
    const char *drop = keyname(get_tetris()->key_drop);
    my_putstr(drop);
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_drop);
    my_putstr(")");
    my_putstr("\nKey quit: ");
    const char *quit = keyname(get_tetris()->key_quit);
    my_putstr(quit);
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_quit);
    my_putstr(")");
    my_putstr("\nKey pause: ");
    const char *pause = keyname(get_tetris()->key_pause);
    my_putstr(pause);
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_pause);
    my_putstr(")");
    my_putstr("\n");
}

void print_set_values(void)
{
    my_putstr("Next: ");
    my_putstr(get_tetris()->without_next ? "No" : "Yes");
    my_putstr("\nLevel: ");
    int level =  get_tetris()->level;
    my_put_nbr(level);
    my_putstr("\nSize: ");
    int size = get_tetris()->map_format->x;
    int size_two = get_tetris()->map_format->y;
    my_put_nbr(size);
    my_putstr ("*");
    my_put_nbr(size_two);
    my_putstr("\n");
}

void print_single_tetri(tetrimino_t *tetrimino)
{
    my_putstr("Tetriminos '");
    my_putstr(tetrimino->name);
    my_putstr("': ");
    if (tetrimino->valid) {
        my_putstr("size ");
        my_put_nbr(tetrimino->x);
        my_putstr("*");
        my_put_nbr(tetrimino->y);
        my_putstr(", color ");
        my_put_nbr(tetrimino->color);
        my_putstr("\n");
        print_without_size(tetrimino);
    } else {
        my_putstr("error\n");
    }
}

void print_tetri_values(void)
{
    my_putstr("\n");
    my_putstr("Number of tetriminos: ");
    my_put_nbr(get_tetrimino_manager()->size);
    my_putstr("\n");
    tetrimino_t **tetriminos = get_tetrimino_manager()->tetriminos;
    for (int i = 0; tetriminos[i] != NULL; i++) {
        print_single_tetri(tetriminos[i]);
    }
}

void print_number_values(void)
{
    my_putstr("Key left: ");
    my_putstr(keyname(get_tetris()->key_left));
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_left);
    my_putstr(")");
    my_putstr("\nKey right: ");
    my_putstr(keyname(get_tetris()->key_right));
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_right);
    my_putstr(")");
    my_putstr("\nKey turn: ");
    my_putstr(keyname(get_tetris()->key_turn));
    my_putstr(" (");
    my_put_nbr(get_tetris()->key_turn);
    my_putstr(")");
    my_putstr("\n");
    print_number_values_two();
    print_set_values();
    print_tetri_values();
}

void print_debug(void)
{
    print_number_values();
}
