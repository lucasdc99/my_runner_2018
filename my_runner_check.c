/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_check
*/

#include "my.h"

void check_position_player_platform_if(struct sfRunner *sf)
{
    if (sf->playerCondition == FALL && sf->mvmtPlayer.y > 4) {
        sf->mvmtPlayer.y = 0;
        sf->playerCondition = ON_PLATFORM_REGULAR;
    }
}

void check_position_player_platform_3(struct sfRunner *sf)
{
    if (sf->positionPlayer.x >= sf->positionPlatform3.x - 75 &&
    sf->positionPlayer.x <= sf->positionPlatform3.x + 60) {
        if (sf->nearPlatform == 0)
            sf->nearPlatform = 1;
    }
    if (sf->positionPlayer.x >= sf->positionPlatform3.x - 55 &&
    sf->positionPlayer.x <= sf->positionPlatform3.x + 60) {
        if (sf->positionPlayer.y >= sf->positionPlatform3.y - 130 &&
        sf->positionPlayer.y <= sf->positionPlatform3.y - 125) {
            check_position_player_platform_if(sf);
        }
    } else if (sf->positionPlayer.x >= sf->positionPlatform3.x + 65 &&
    sf->positionPlayer.x <= sf->positionPlatform3.x + 80) {
        if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = FALL;
            sf->nearPlatform = 0;
        }
    }
}

void check_position_player_platform_2(struct sfRunner *sf)
{
    if (sf->positionPlayer.x >= sf->positionPlatform2.x - 75 &&
    sf->positionPlayer.x <= sf->positionPlatform2.x + 60) {
        if (sf->nearPlatform == 0)
            sf->nearPlatform = 1;
    }
    if (sf->positionPlayer.x >= sf->positionPlatform2.x - 55 &&
    sf->positionPlayer.x <= sf->positionPlatform2.x + 60) {
        if (sf->positionPlayer.y >= sf->positionPlatform2.y - 130 &&
        sf->positionPlayer.y <= sf->positionPlatform2.y - 125) {
            check_position_player_platform_if(sf);
        }
    } else if (sf->positionPlayer.x >= sf->positionPlatform2.x + 65 &&
    sf->positionPlayer.x <= sf->positionPlatform2.x + 80) {
        if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = FALL;
            sf->nearPlatform = 0;
        }
    }
    check_position_player_platform_3(sf);
}

void check_position_player_platform(struct sfRunner *sf)
{
    if (sf->positionPlayer.x >= sf->positionPlatform.x - 75 &&
    sf->positionPlayer.x <= sf->positionPlatform.x + 60) {
        if (sf->nearPlatform == 0)
            sf->nearPlatform = 1;
    }
    if (sf->positionPlayer.x >= sf->positionPlatform.x - 55 &&
    sf->positionPlayer.x <= sf->positionPlatform.x + 60) {
        if (sf->positionPlayer.y >= sf->positionPlatform.y - 130 &&
        sf->positionPlayer.y <= sf->positionPlatform.y - 125) {
            check_position_player_platform_if(sf);
        }
    } else if (sf->positionPlayer.x >= sf->positionPlatform.x + 65 &&
    sf->positionPlayer.x <= sf->positionPlatform.x + 80) {
        if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->playerCondition = FALL;
            sf->nearPlatform = 0;
        }
    }
    check_position_player_platform_2(sf);
}

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