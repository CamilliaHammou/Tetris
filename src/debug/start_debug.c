/*
** EPITECH PROJECT, 2022
** Tetris
** File description:
** start_debug
*/

#include "my.h"

static struct option long_options[] =
{
    {"level", required_argument, 0, 'L'},
    {"key-left", required_argument, 0, 'l'},
    {"key-right", required_argument, 0, 'r'},
    {"key-turn", required_argument, 0, 't'},
    {"key-drop", required_argument, 0, 'd'},
    {"key-quit", required_argument, 0, 'q'},
    {"key-pause", required_argument, 0, 'p'},
    {"map-size", required_argument, 0, 'm'},
    {"help", no_argument, 0, 'h'},
    {"debug", no_argument, 0, 'D'},
    {"without-next", no_argument, 0, 'w'},
    {0, 0, 0, 0}
};

void handle_flag_3(char flag)
{
    switch (flag) {
        case 'w':
            get_tetris()->without_next = true;
            break;
        default:
            break;
    }
}

void handle_flag_2(char flag)
{
    switch (flag) {
        case 'q':
            get_tetris()->key_quit = my_get_nbr(optarg);
            break;
        case 'p':
            get_tetris()->key_pause = my_get_nbr(optarg);
            break;
        case 'h':
            print_help();
            break;
        case 'm':
            set_map_format(optarg);
            break;
        case 'D':
            get_tetris()->should_debug = true;
            break;
        default:
            handle_flag_3(flag);
            break;
    }
}

void handle_flag(char flag)
{
    switch (flag) {
        case 'L':
            get_tetris()->level = my_get_nbr(optarg);
            break;
        case 'l':
            get_tetris()->key_left = my_get_nbr(optarg);
            break;
        case 'r':
            get_tetris()->key_right = my_get_nbr(optarg);
            break;
        case 't':
            get_tetris()->key_turn = my_get_nbr(optarg);
            break;
        case 'd':
            get_tetris()->key_drop = my_get_nbr(optarg);
            break;
        default:
            handle_flag_2(flag);
            break;
    }
}

void handle_command(int ac, char **av)
{
    while (true) {
        int option_index = 0;
        int flag = getopt_long(ac, av, "L:l:r:t:d:q:p:m:hDw",
        long_options, &option_index);
        if (flag == -1) {
            break;
        }
        handle_flag(flag);
    }
}
