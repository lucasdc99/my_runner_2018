/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_create
*/

#include "my.h"

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
    sf->rectGround.top = 490;
    sf->rectGround.left = 0;
    sf->rectGround.width = 800;
    sf->rectGround.height = 960;
    sf->rectangleView.left = 0;
    sf->rectangleView.top = 0;
    sf->rectangleView.width = 800;
    sf->rectangleView.height = 600;
}

void init_position(struct sfRunner *sf)
{
    sf->positionPlayer.x = 60;
    sf->positionPlayer.y = 420;
    sf->positionEnemy.x = 400;
    sf->positionEnemy.y = 490;
    sf->positionSky.x = 0;
    sf->positionSky.y = -50;
    sf->positionPause = sfView_getSize(sf->view);
    sf->positionPause.x /= 4;
    sf->positionPause.y /= 2.5;
    sf->positionBackground.x = 0;
    sf->positionBackground.y = 50;
    sf->positionGround.x = 0;
    sf->positionGround.y = 130;
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
    sf->scaleEnemy.x = 0.27;
    sf->scaleEnemy.y = 0.27;
    sf->scaleBackground.x = 1.6;
    sf->scaleBackground.y = 1.6;
    sf->scaleGround.x = 1.2;
    sf->scaleGround.y = 1.2;
    sf->loop = 0;
    sf->speedMoveBackground = 1;
    sf->speedMoveGround = 2;
    sf->speedMoveSky = 1;
    sf->jumpSide = 0;
}

void create_sf(struct sfRunner *sf)
{
    sf->window = sfRenderWindow_create(sf->mode, "Pickle Rick Runner",
    sfResize | sfClose, NULL);
    sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
    sf->textureEnemy = sfTexture_createFromFile("images/spikes.png", NULL);
    sf->textureSky = sfTexture_createFromFile("images/sky.png", NULL);
    sf->textureBg = sfTexture_createFromFile("images/background.png", NULL);
    sf->textureGround = sfTexture_createFromFile("images/ground.png", NULL);
    sf->spritePlayer = sfSprite_create();
    sf->spriteEnemy = sfSprite_create();
    sf->spriteSky = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->view = sfView_createFromRect(sf->rectangleView);
    sf->font = sfFont_createFromFile("arial.ttf");
    sf->pause = sfText_create();
    sf->clock = sfClock_create();
}

void set_sf(struct sfRunner *sf)
{
    sfRenderWindow_setView(sf->window, sf->view);
    sfText_setString(sf->pause, "PAUSE");
    sfText_setFont(sf->pause, sf->font);
    sfText_setCharacterSize(sf->pause, 100);
    sfSprite_setPosition(sf->spritePlayer, sf->positionPlayer);
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    sfSprite_setPosition(sf->spriteBackground, sf->positionBackground);
    sfSprite_setPosition(sf->spriteGround, sf->positionGround);
    sfText_setPosition(sf->pause, sf->positionPause);
    sfSprite_setPosition(sf->spriteSky, sf->positionSky);
    sfSprite_setScale(sf->spriteSky, sf->scaleSky);
    sfSprite_setScale(sf->spriteBackground, sf->scaleBackground);
    sfSprite_setScale(sf->spriteGround, sf->scaleGround);
    sfSprite_setScale(sf->spriteEnemy, sf->scaleEnemy);
    sfRenderWindow_setFramerateLimit(sf->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
}