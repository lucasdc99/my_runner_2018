/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_init
*/

#include "my.h"

void init_rect_2(struct sfRunner *sf)
{
    sf->rectGround.top = 490;
    sf->rectGround.left = 0;
    sf->rectGround.width = 800;
    sf->rectGround.height = 960;
    sf->rectangleView.left = 0;
    sf->rectangleView.top = 0;
    sf->rectangleView.width = 800;
    sf->rectangleView.height = 600;
    sf->viewPort.left = 0;
    sf->viewPort.top = 0;
    sf->viewPort.width = 1;
    sf->viewPort.height = 1;
}

void init_rect(struct sfRunner *sf)
{
    sf->rect.top = 0;
    sf->rect.left = 0;
    sf->rect.width = 100;
    sf->rect.height = 200;
    sf->rectSky.top = 0;
    sf->rectSky.left = 0;
    sf->rectSky.width = 1920;
    sf->rectSky.height = 1080;
    sf->rectBackground.top = 0;
    sf->rectBackground.left = 0;
    sf->rectBackground.width = 800;
    sf->rectBackground.height = 240;
    init_rect_2(sf);
}

void init_position(struct sfRunner *sf)
{
    sf->positionPlayer.x = 100;
    sf->positionPlayer.y = 420;
    sf->positionEnemy.x = 1000;
    sf->positionEnemy.y = 485;
    sf->positionSky.x = 0;
    sf->positionSky.y = -50;
    sf->positionPause = sfView_getSize(sf->view);
    sf->positionPause.x /= 4;
    sf->positionPause.y /= 2.5;
    sf->positionBackground.x = 0;
    sf->positionBackground.y = 50;
    sf->positionGround.x = 0;
    sf->positionGround.y = 130;
    sf->positionPlatform.x = 1000;
    sf->positionPlatform.y = 485;
    sf->positionDead.x = -90;
    sf->positionDead.y = 0;
    sf->positionPortal.x = 1000;
    sf->positionPortal.y = 300;
}

void init_other_2(struct sfRunner *sf)
{
    sf->scalePlatform.x = 0.8;
    sf->scalePlatform.y = 0.8;
    sf->scaleBackground.x = 1.6;
    sf->scaleBackground.y = 1.6;
    sf->scaleGround.x = 1.2;
    sf->scaleGround.y = 1.2;
    sf->speedMoveBackground = 2;
    sf->speedMoveGround = 4;
    sf->speedMoveSky = 2;
    sf->distanceSpawn = 1;
    sf->speedEnemy = 4.9;
    sf->groundy = 420;
    sf->playerCondition = REGULAR;
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
    init_other_2(sf);
}