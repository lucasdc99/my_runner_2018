/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_check
*/

#include "my.h"

void manage_key_pressed(struct sfRunner *sf)
{
    static int playerConditionActual = REGULAR;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->playerCondition == REGULAR) {
            sf->playerCondition = JUMP;
        } else if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = ON_PLATFORM_JUMP;
        }
    } else if (sfKeyboard_isKeyPressed(sfKeyReturn) && sf->playerCondition != DEAD) {
        if (sf->playerCondition == PAUSE) {
            sf->playerCondition = playerConditionActual;
        } else {
            playerConditionActual = sf->playerCondition;
            sf->playerCondition = PAUSE;
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
    if (sf->event.type == sfEvtResized) {
        sf->positionScope.x = sf->event.size.width;
        sf->positionScope.y = sf->event.size.height;
        sfView_setSize(sf->view, sf->positionScope);
        sfRenderWindow_setView(sf->window, sf->view);
    }
}

void check_position_player_platform(struct sfRunner *sf)
{
    if (sf->positionPlayer.x >= sf->positionPlatform.x - 55 &&
    sf->positionPlayer.x <= sf->positionPlatform.x + 60) {
        if (sf->positionPlayer.y >= sf->positionPlatform.y - 130 &&
        sf->positionPlayer.y <= sf->positionPlatform.y - 125) {
            if (sf->playerCondition != ON_PLATFORM_JUMP) {
                sf->mvmtPlayer.y = 0;
                sf->playerCondition = ON_PLATFORM_REGULAR;
            }
        }
    } else if (sf->positionPlayer.x >= sf->positionPlatform.x + 65 &&
    sf->positionPlayer.x <= sf->positionPlatform.x + 80) {
        if (sf->playerCondition != ON_PLATFORM_JUMP) {
            sf->playerCondition = FALL;
        }
    }
}

void check_position_player(struct sfRunner *sf)
{
    move_rect(sf, 100);
    sf->positionPlayer = sfSprite_getPosition(sf->spritePlayer);
    if (sf->mvmtPlayer.y == -6.5) {
        sf->playerCondition = FALL;
    } else if (sf->positionPlayer.y > 420 && sf->playerCondition == FALL) {
        sf->positionPlayer.y = 420;
        sf->mvmtPlayer.y = 0;
        sf->playerCondition = REGULAR;
    }
    if (sf->positionPlayer.x >= sf->positionEnemy.x - 40 &&
    sf->positionPlayer.x <= sf->positionEnemy.x + 30) {
        if (sf->positionPlayer.y >= sf->positionEnemy.y - 100) {
            sf->playerCondition = DEAD;
        }
    }
    if (sf->playerCondition == ON_PLATFORM_JUMP) {
        sf->mvmtPlayer.y -= 0.5;
    }
    if (sf->playerCondition == JUMP) {
        sf->mvmtPlayer.y -= 0.5;
    } else if (sf->playerCondition == FALL) {
        sf->mvmtPlayer.y += 0.5;
    }
    sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
}

void check_position_2(struct sfRunner *sf)
{
    sf->positionEnemy = sfSprite_getPosition(sf->spriteEnemy);
    sf->positionPlatform = sfSprite_getPosition(sf->spritePlatform);
    if (sf->playerCondition == DEAD) {
        sf->speedMoveBackground = 1;
        sf->speedMoveGround = 2;
        sf->speedMoveSky = 1;
        sf->speedEnemy = 2.45;
        sf->mvmtPlayer.y += 1;
    }
    if (sf->positionEnemy.x < -100) {
        sf->existingSpike = 0;
        sf->positionEnemy.x = 1000;
        sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    }
    if (sf->positionPlatform.x < -100)
        sf->positionPlatform.x = 1400;
}