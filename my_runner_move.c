/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_move
*/

#include "my.h"

void move_rect(struct sfRunner *sf, int offset)
{
    sf->rect.left = offset * ((sf->seconds2 / 150) % 4);
}

void move_rect_ground(struct sfRunner *sf, int max_value)
{
    sf->rectGround.left += sf->speedMoveGround;
    if (sf->rectGround.left == max_value) {
        sf->rectGround.left = 0;
    }
}

void move_rect_background(struct sfRunner *sf, int max_value)
{
    sf->rectBackground.left += sf->speedMoveBackground;
    if (sf->rectBackground.left == max_value) {
        sf->rectBackground.left = 0;
    }
}

void move_rect_sky(struct sfRunner *sf, int max_value)
{
    sf->rectSky.left += sf->speedMoveSky;
    if (sf->rectSky.left == max_value) {
        sf->rectSky.left = 0;
    }
}

int check_args(int ac, char **av, struct sfRunner *sf)
{
    if (ac < 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (1);
    }
    if (ac == 3 && my_strcmp(av[2], "-i") == 0) {
        sf->endless = 1;
    }
}