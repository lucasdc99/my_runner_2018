/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_manage
*/

#include "my.h"

void manage_key_pressed_2(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
    (sf->playerCondition == DEAD || sf->playerCondition == END)) {
        sfRenderWindow_close(sf->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) &&
    (sf->playerCondition == DEAD || sf->playerCondition == END)) {
        init_rect(sf);
        init_other(sf);
        init_position(sf);
        set_other(sf);
        sf->pauseTime = 0;
        sf->playerCondition = REGULAR;
    }
}

void manage_key_pressed(struct sfRunner *sf)
{
    static int playerConditionActual = REGULAR;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->playerCondition == REGULAR) {
            sf->playerCondition = JUMP;
        } else if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = ON_PLATFORM_JUMP;
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
    sf->playerCondition != DEAD && sf->playerCondition != END) {
        if (sf->playerCondition == PAUSE) {
            sf->playerCondition = playerConditionActual;
        } else {
            playerConditionActual = sf->playerCondition;
            sf->playerCondition = PAUSE;
            sfRenderWindow_drawText(sf->window, sf->pause, NULL);
            sfRenderWindow_display(sf->window);
        }
    }
    manage_key_pressed_2(sf);
}

void manage_spike(struct sfRunner *sf)
{
    sf->positionEnemy.x -= sf->speedEnemy;
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
}

void manage_platform(struct sfRunner *sf)
{
    sf->positionPlatform.x -= sf->speedEnemy;
    sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
}

void manage_portal(struct sfRunner *sf)
{
    sf->positionPortal.x -= sf->speedEnemy;
    sfSprite_setPosition(sf->spritePortal, sf->positionPortal);
}