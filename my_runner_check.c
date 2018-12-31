/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_check
*/

#include "my.h"

void check_player_condition_2(struct sfRunner *sf)
{
    if (sf->playerCondition == JUMP) {
        sf->mvmtPlayer.y -= 0.5;
    } else if (sf->playerCondition == FALL) {
        sf->mvmtPlayer.y += 0.5;
    }
    if (sf->playerCondition == END) {
        if (sf->positionPlayer.y > 420) {
            sf->mvmtPlayer.y = 0;
            sf->positionPlayer.y = 420;
            sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
        } else if (sf->positionPlayer.y < 420)
            sf->mvmtPlayer.y += 0.5;
    }
}

void check_player_condition(struct sfRunner *sf)
{
    if (sf->nearPlatform == 2) {
        if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = ON_PLATFORM_JUMP;
            sf->nearPlatform = 0;
        }
        if (sf->playerCondition == REGULAR) {
            sf->playerCondition = JUMP;
            sf->nearPlatform = 0;
        }
    }
    if (sf->playerCondition == ON_PLATFORM_JUMP)
        sf->mvmtPlayer.y -= 0.5;
    check_player_condition_2(sf);
}

void check_position_player_2(struct sfRunner *sf)
{
    if (sf->positionPlayer.x >= sf->positionEnemy2.x - 40 &&
    sf->positionPlayer.x <= sf->positionEnemy2.x + 30) {
        if (sf->positionPlayer.y >= sf->positionEnemy2.y - 100)
            sf->playerCondition = DEAD;
    }
    if (sf->positionPlayer.x >= sf->positionEnemy3.x - 40 &&
    sf->positionPlayer.x <= sf->positionEnemy3.x + 30) {
        if (sf->positionPlayer.y >= sf->positionEnemy3.y - 100)
            sf->playerCondition = DEAD;
    }
    sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
}

void check_position_player(struct sfRunner *sf)
{
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
    check_position_player_2(sf);
}

void bouton_play(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    if (position.x > sf->positionPlay.x &&
    position.x < sf->positionPlay.x + 150) {
        if (position.y > sf->positionPlay.y &&
        position.y < sf->positionPlay.y + 150) {
            sfMusic_destroy(sf->musicMenu);
            sfTexture_destroy(sf->textureBoutonPlay);
            sfTexture_destroy(sf->textureBoutonQuit);
            sfTexture_destroy(sf->textureBoutonChangeSize);
            sfSprite_destroy(sf->spriteBoutonPlay);
            sfSprite_destroy(sf->spriteBoutonQuit);
            sfSprite_destroy(sf->spriteBoutonChangeSize);
            sfMusic_play(sf->start);
            sf->playerCondition = REGULAR;
            analyse_after_pause(sf);
        }
    }
}