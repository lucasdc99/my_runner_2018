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

void init_position_2(struct sfRunner *sf)
{
    sf->positionGround.x = 0;
    sf->positionGround.y = 130;
    sf->positionPlatform.x = 1000;
    sf->positionPlatform.y = 485;
    sf->positionDead.x = -90;
    sf->positionDead.y = 0;
    sf->positionPortal.x = 1000;
    sf->positionPortal.y = 300;
    sf->positionScore.x = 10;
    sf->positionScore.y = 0;
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
    sf->positionPause.x /= 2.8;
    sf->positionPause.y /= 3;
    sf->positionBackground.x = 0;
    sf->positionBackground.y = 50;
    init_position_2(sf);
}