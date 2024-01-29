/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** tetris_game
*/

#include "my.h"

static tetris_game_t *tetris_game;

tetris_game_t *get_tetris_game()
{
    return tetris_game;
}

void new_tetris_game()
{
    tetris_game = malloc(sizeof(tetris_game_t));
    tetris_game->menu_window = create_menu_window();
    tetris_game->play_window = create_play_window();
    tetris_game->next_window = create_next_window();
    tetris_game->tetris_text_window = create_tetrix_text_window();
    tetris_game->current_moving_tetrimino = create_moving_tetrimino();
    tetris_game->next_moving_tetrimino = create_moving_tetrimino();
    tetris_game->level = get_tetris()->level;
}