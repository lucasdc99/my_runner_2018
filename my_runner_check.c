/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_check
*/

#include "my.h"

void manage_key_pressed(struct sfRunner *sf)
{
    static int jumpSideActual = 0;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->jumpSide == 0) {
            sf->jumpSide = 1;
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        if (sf->jumpSide == 2) {
            sf->jumpSide = jumpSideActual;
        } else {
            jumpSideActual = sf->jumpSide;
            sf->jumpSide = 2;
            sfRenderWindow_drawText(sf->window, sf->pause, NULL);
            sfRenderWindow_display(sf->window);
        }
    }
}

void analyse_events(struct sfRunner *sf)
{
    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtKeyPressed)
        manage_key_pressed(sf);
}

void check_position(struct sfRunner *sf)
{
    sf->positionPlayer = sfSprite_getPosition(sf->spritePlayer);
    move_rect(sf, 100);
    if (sf->positionPlayer.y < 350 && sf->jumpSide == 1) {
        sf->jumpSide = -1;
    } else if (sf->positionPlayer.y > 420 && sf->jumpSide == -1) {
        sf->positionPlayer.y = 420;
        sf->mvmtPlayer.y = 0;
        sf->jumpSide = 0;
    }
    if (sf->jumpSide == 1) {
        sf->mvmtPlayer.y -= 0.5;
    } else if (sf->jumpSide == -1) {
        sf->mvmtPlayer.y += 0.5;
    }
    sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
}

void check_position_2(struct sfRunner *sf)
{
    sf->positionPlayer = sfSprite_getPosition(sf->spritePlayer);
    sf->positionEnemy = sfSprite_getPosition(sf->spriteEnemy);
    if (sf->positionPlayer.x + 60 > sf->positionEnemy.x &&
        sf->positionPlayer.y + 120 >= sf->positionEnemy.y) {
            sf->jumpSide = 2;
    }
    if (sf->jumpSide == 2)
        sf->mvmtPlayer.y += 1;
}