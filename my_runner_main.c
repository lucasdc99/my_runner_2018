/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_main
*/

#include "my.h"

void main_loop(struct sfRunner *sf)
{
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        analyse_events(sf);
    if (sf->jumpSide != 2) {
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->seconds = sf->time.microseconds / 1000000.0;
        sf->seconds2 = sf->time.microseconds / 1000.0;
        sf->loop++;
        check_position(sf);
        // if (sf->jumpSide != 2)
        //     check_position_2(sf);
        sfSprite_move(sf->spritePlayer, sf->mvmtPlayer);
        sf->positionEnemy.x -= 2.4;
        sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
        move_rect_background(sf, 645);
        move_rect_ground(sf, 720);
        move_rect_sky(sf, 1900);
        draw_sf(sf);
    }
}

int main(void)
{
    struct sfRunner *sf = malloc(sizeof(struct sfRunner));

    init_sfRect(sf);
    init_sfOther(sf);
    create_sf(sf);
    init_sfPosition(sf);
    set_sf(sf);
    while (sfRenderWindow_isOpen(sf->window))
        main_loop(sf);
    destroy_sf(sf);
    return (0);
}