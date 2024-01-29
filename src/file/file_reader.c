/*
** EPITECH PROJECT, 2022
** solver
** File description:
** file_reader
*/

#include "my.h"

static file_t *file_reader;

void scan_content(void)
{
    char *content = file_reader->content;
    file_reader->columns = 1;
    int max_hor = 0;
    for (int i = 0; content[i] != '\0'; i++) {
        char value = content[i];
        max_hor++;
        if (value == '\n') {
            file_reader->columns++;
            max_hor = 0;
        }
        if (max_hor > file_reader->hor_size) {
            file_reader->hor_size = max_hor;
        }
    }
}

int file_size(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        exit(84);
    }
    char buffer;
    int counter = 0;
    while (read(fd, &buffer, 1)) {
        counter++;
    }
    close(fd);
    return counter;
}

void set_content(char *filepath)
{
    file_reader->size = file_size(filepath);
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * file_reader->size);
    while (read(fd, buffer, file_reader->size));
    file_reader->content = buffer;
    scan_content();
    close(fd);
}

file_t *create_file_reader(char *filepath)
{
    file_reader = malloc(sizeof(file_t));
    set_content(filepath);
    return file_reader;
}
