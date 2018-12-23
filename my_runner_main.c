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
    if (sf->playerCondition != PAUSE) {
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->seconds = sf->time.microseconds / 1000000.0;
        sf->seconds2 = sf->time.microseconds / 1000.0;
        check_position_player(sf);
        check_position_2(sf);
        sfSprite_move(sf->spritePlayer, sf->mvmtPlayer);
        sf->positionEnemy.x -= sf->speedEnemy;
        sf->positionPlatform.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
        sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
        move_rect_background(sf, 320);
        move_rect_ground(sf, 720);
        move_rect_sky(sf, 1900);
        draw_sf(sf);
    }
}

int main(void)
{
    struct sfRunner *sf = malloc(sizeof(struct sfRunner));

    init_rect(sf);
    init_other(sf);
    create_sf(sf);
    init_position(sf);
    set_sf(sf);
    while (sfRenderWindow_isOpen(sf->window))
        main_loop(sf);
    destroy_sf(sf);
    return (0);
}