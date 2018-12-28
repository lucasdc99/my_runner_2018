/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_set
*/

#include "my.h"

void init_other_2(struct sfRunner *sf)
{
    sf->scalePlatform.x = 0.8;
    sf->scalePlatform.y = 0.8;
    sf->scaleBackground.x = 1.6;
    sf->scaleBackground.y = 1.6;
    sf->scaleGround.x = 1.2;
    sf->scaleGround.y = 1.2;
    sf->speedMoveBackground = 1;
    sf->speedMoveGround = 3;
    sf->speedMoveSky = 2;
    sf->speedPlayer = 120;
    sf->maxValueBackground = 645;
    sf->maxValueGround = 720;
    sf->maxValueSky = 1920;
    sf->distanceSpawn = 1;
    sf->speedEnemy = 4.9;
    sf->shift = 0;
    sf->nearPlatform = 0;
    sf->scoreInt = 0;
    sf->playerCondition = MENU;
}

void init_other(struct sfRunner *sf)
{
    sf->mode.width = 800;
    sf->mode.height = 600;
    sf->mode.bitsPerPixel = 32;
    sf->mvmtPlayer.x = 0.0;
    sf->mvmtPlayer.y = 0.0;
    sf->scaleSky.x = 0.6;
    sf->scaleSky.y = 0.6;
    sf->scaleDead.x = 0.7;
    sf->scaleDead.y = 0.83;
    sf->scaleEnemy.x = 0.27;
    sf->scaleEnemy.y = 0.27;
    if (sf->playerCondition != DEAD)
        sf->scoreStr = malloc(sizeof(char) * 10);
    init_other_2(sf);
}

void set_other_2(struct sfRunner *sf)
{
    sfSprite_setPosition(sf->spriteBackground, sf->positionBackground);
    sfSprite_setPosition(sf->spriteGround, sf->positionGround);
    sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
    sfSprite_setPosition(sf->spritePortal, sf->positionPortal);
    sfText_setPosition(sf->pause, sf->positionPause);
    sfText_setPosition(sf->score, sf->positionScore);
    sfSprite_setPosition(sf->spriteSky, sf->positionSky);
    sfSprite_setScale(sf->spriteSky, sf->scaleSky);
    sfSprite_setScale(sf->spriteBackground, sf->scaleBackground);
    sfSprite_setScale(sf->spriteGround, sf->scaleGround);
    sfSprite_setScale(sf->spriteEnemy, sf->scaleEnemy);
    sfSprite_setScale(sf->spritePlatform, sf->scalePlatform);
    sfSprite_setScale(sf->spritePortal, sf->scalePlatform);
    sfRenderWindow_setFramerateLimit(sf->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
}

void set_other(struct sfRunner *sf)
{
    sfRenderWindow_setView(sf->window, sf->view);
    sfText_setString(sf->score, "0");
    sfText_setString(sf->pause, "PAUSE");
    sfText_setFont(sf->pause, sf->font);
    sfText_setFont(sf->score, sf->font);
    sfText_setCharacterSize(sf->pause, 100);
    sfText_setCharacterSize(sf->score, 50);
    sfText_setColor(sf->score, sfColor_fromRGBA(76, 130, 38, 255));
    sfText_setColor(sf->pause, sfColor_fromRGBA(76, 130, 38, 255));
    sfText_setOutlineThickness(sf->score, 2);
    sfText_setOutlineColor(sf->score, sfWhite);
    sfText_setOutlineThickness(sf->pause, 2);
    sfText_setOutlineColor(sf->pause, sfWhite);
    sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    set_other_2(sf);
}