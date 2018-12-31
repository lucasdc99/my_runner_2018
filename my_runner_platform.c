/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_platform
*/

#include "my.h"

void check_position_player_platform_condition(struct sfRunner *sf)
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
            check_position_player_platform_condition(sf);
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
            check_position_player_platform_condition(sf);
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
            check_position_player_platform_condition(sf);
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