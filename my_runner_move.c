/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_move
*/

#include "my.h"

void move_rect(struct sfRunner *sf, int offset)
{
    sf->rect.left = offset * ((sf->seconds2 / sf->speedPlayer) % 4);
}

void move_rect_ground(struct sfRunner *sf)
{
    sf->rectGround.left += sf->speedMoveGround;
    if (sf->rectGround.left >= sf->maxValueGround) {
        sf->rectGround.left = 0;
    }
}

void move_rect_background(struct sfRunner *sf)
{
    sf->rectBackground.left += sf->speedMoveBackground;
    if (sf->rectBackground.left >= sf->maxValueBackground) {
        sf->rectBackground.left = 0;
    }
}

void move_rect_sky(struct sfRunner *sf)
{
    sf->rectSky.left += sf->speedMoveSky;
    if (sf->rectSky.left >= sf->maxValueSky) {
        sf->rectSky.left = 0;
    }
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
        sf->existingSpike--;
        sf->positionEnemy.x = 1000;
        sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    }
    if (sf->positionPlatform.x < -100) {
        sf->existingPlatform--;
        sf->positionPlatform.x = 1000;
        sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
    }
}