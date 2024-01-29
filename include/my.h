/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <time.h>
#include <ncurses.h>
#include <getopt.h>
 
#define TETRIMINOS "./tetriminos"

#define RED_COLOR 0
#define GREEN_COLOR 1
#define YELLOW_COLOR 2
#define BLUE_COLOR 3
#define MAGENTA_COLOR 4
#define CYAN_COLOR 5

typedef struct vec2d {
    int x;
    int y;
} vec2d_t;

typedef struct tetris {
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    bool should_debug;
    bool should_help;
    vec2d_t *map_format;
    bool without_next;
    bool one_tetrimino_valid;
} tetris_t;

typedef struct file_reader {
    char *content;
    int size;
    int columns;
    int hor_size;
} file_t;

typedef struct tetrimino {
    char *name;
    char **map;
    char **clean_map;
    file_t *file;
    int x;
    int y;
    int color;
    bool valid;
} tetrimino_t;

typedef struct moving_tetrimino {
    tetrimino_t *tetrimino;
    int x_position;
    int y_position;
    int id;
} moving_tetrimino_t;

typedef struct tetriminos_manager {
    int size;
    tetrimino_t **tetriminos;
} tetriminos_manager_t;

typedef struct tetris_game {
    bool paused;
    int last_clock;
    int last_second;
    moving_tetrimino_t *current_moving_tetrimino;
    moving_tetrimino_t *next_moving_tetrimino;
    int high_score;
    int score;
    int lines;
    int level;
    int elapsed_second;
    WINDOW *menu_window;
    WINDOW *play_window;
    WINDOW *next_window;
    WINDOW *tetris_text_window;
} tetris_game_t;

void handle_key_press();
void check_window_size(WINDOW *window);
void check_lines();
double get_elapsed_time();
void switch_to_next();
bool can_move(moving_tetrimino_t *moving_tetrimino, int new_y, int new_x);
bool move_tetrimino(moving_tetrimino_t *moving_tetrimino, int y, int x);
int random_in_range(int min, int max);
char *remove_new_line(char *str);
void print_tetrimino(WINDOW *window, int y, int x, moving_tetrimino_t *moving_tetrimino);
moving_tetrimino_t *create_moving_tetrimino();
char *create_string(char *str, int size);
char *itoa(int number);
char *my_revstr(char *str);
void write_only(WINDOW *window, int y, int x, char *text);
void update_tetris_text();
WINDOW *create_tetrix_text_window(void);
void update_next();
void update_play();
void update_menu();
void write_and_refresh(WINDOW *window, int y, int x, char *text);
tetris_game_t *get_tetris_game();
void new_tetris_game();
void print_without_size(tetrimino_t *tetrimino);
char *remove_extension(char *str);
char *my_strcat(char *dest, char *src);
char *get_path_name(struct dirent *entity);
tetrimino_t *create_tetrimino(char *filepath);
bool end_with(char *content, char *search);
void setup_file_list(void);
int my_put_nbr(int nb);
void set_map_format(char *args);
void print_debug(void);
tetris_t *get_tetris();
void print_help();
void handle_command(int ac, char **av);
int my_strlen(char const *str);
bool check_tetrimino_integrity(tetrimino_t *tetrimino);
char **map_file_content(file_t *file);
int get_next_end_number(char *str, int start);
bool is_number(char value);
char *extract_str(char *str, int start, int end);
void set_tetrimino_content(tetrimino_t *tetrimino);
tetriminos_manager_t *get_tetrimino_manager();
void new_tetriminos_manager();
file_t *create_file_reader(char *filepath);
int my_get_nbr(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
WINDOW *create_play_window(void);
WINDOW *create_menu_window(void);
WINDOW *create_next_window(void);
void init_colors(void);
int start_game(int ac, char **av);
