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
    if (sfKeyboard_isKeyPressed(sfKeyR) && (sf->playerCondition == DEAD &&
    sf->positionPlayer.y > 800 || sf->playerCondition == END &&
    sf->positionPortal.x < 0)) {
        init_rect(sf);
        init_other(sf);
        init_position(sf);
        sf->speedMoveBackground = 1;
        sf->speedMoveGround = 3;
        sf->speedMoveSky = 2;
        set_other(sf);
        for (int i = 0; i < 10; i++)
            sf->scoreStr[i] = 0;
        sf->pauseTime = 0;
        sf->playerCondition = REGULAR;
    }
}

void manage_key_pressed(struct sfRunner *sf)
{
    static int playerConditionActual = REGULAR;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->nearPlatform == 1)
            sf->nearPlatform = 2;
        if (sf->playerCondition == REGULAR) {
            sf->nearPlatform = 1;
            sf->playerCondition = JUMP;
        } else if (sf->playerCondition == ON_PLATFORM_REGULAR)
            sf->playerCondition = ON_PLATFORM_JUMP;
    } else if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
    sf->playerCondition != DEAD && sf->playerCondition != END) {
        if (sf->playerCondition == PAUSE) {
            sf->playerCondition = playerConditionActual;
        } else {
            playerConditionActual = sf->playerCondition;
            sf->playerCondition = PAUSE;
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