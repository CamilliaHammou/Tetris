/*
** EPITECH PROJECT, 2022
** B-PSU-200-MAR-2-1-tetris-camillia.hammou
** File description:
** my_get_nbr
*/

int my_get_nbr(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
        }
        i++;
    }
    return nb;
}
