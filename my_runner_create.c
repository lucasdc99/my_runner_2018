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
    sf->positionPlatform.x = 1400;
    sf->positionPlatform.y = 485;
    sf->viewPort.left = 0;
    sf->viewPort.top = 0;
    sf->viewPort.width = 1;
    sf->viewPort.height = 1;
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
    sf->scalePlatform.x = 0.6;
    sf->scalePlatform.y = 0.6;
    sf->scaleBackground.x = 1.6;
    sf->scaleBackground.y = 1.6;
    sf->scaleGround.x = 1.2;
    sf->scaleGround.y = 1.2;
    sf->speedMoveBackground = 2;
    sf->speedMoveGround = 4;
    sf->speedMoveSky = 2;
    sf->speedEnemy = 4.9;
    sf->playerCondition = REGULAR;
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
    sf->texturePlatform = sfTexture_createFromFile("images/platform.png", NULL);
    sf->spritePlayer = sfSprite_create();
    sf->spriteEnemy = sfSprite_create();
    sf->spriteSky = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->spritePlatform = sfSprite_create();
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
    sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
    sfText_setPosition(sf->pause, sf->positionPause);
    sfSprite_setPosition(sf->spriteSky, sf->positionSky);
    sfSprite_setScale(sf->spriteSky, sf->scaleSky);
    sfSprite_setScale(sf->spriteBackground, sf->scaleBackground);
    sfSprite_setScale(sf->spriteGround, sf->scaleGround);
    sfSprite_setScale(sf->spriteEnemy, sf->scaleEnemy);
    sfSprite_setScale(sf->spritePlatform, sf->scalePlatform);
    sfRenderWindow_setFramerateLimit(sf->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
}