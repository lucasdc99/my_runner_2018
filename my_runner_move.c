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