/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_create
*/

#include "my.h"

void create_sf(struct sfRunner *sf)
{
    init_rect(sf);
    init_other(sf);
    create_texture_sprite(sf);
    init_position(sf);
    set_other(sf);
}

void create_texture_sprite(struct sfRunner *sf)
{
    sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
    sf->textureEnemy = sfTexture_createFromFile("images/spikes.png", NULL);
    sf->textureSky = sfTexture_createFromFile("images/sky.png", NULL);
    sf->textureBg = sfTexture_createFromFile("images/background.png", NULL);
    sf->textureGround = sfTexture_createFromFile("images/ground.png", NULL);
    sf->texturePlatform = sfTexture_createFromFile("images/platfrm.png", NULL);
    sf->textureDead = sfTexture_createFromFile("images/dead.png", NULL);
    sf->textureEnd = sfTexture_createFromFile("images/end.png", NULL);
    sf->texturePortal = sfTexture_createFromFile("images/portal.png", NULL);
    sf->spritePlayer = sfSprite_create();
    sf->spriteEnemy = sfSprite_create();
    sf->spriteSky = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->spritePlatform = sfSprite_create();
    sf->spriteDead = sfSprite_create();
    sf->spriteEnd = sfSprite_create();
    sf->spritePortal = sfSprite_create();
    create_other(sf);
}

void create_other(struct sfRunner *sf)
{
    sf->window = sfRenderWindow_create(sf->mode, "Pickle Rick Runner",
    sfResize | sfClose, NULL);
    sf->view = sfView_createFromRect(sf->rectangleView);
    sf->font = sfFont_createFromFile("fonts/arial.ttf");
    sf->pause = sfText_create();
    sf->clock = sfClock_create();
    sf->clockSpawn = sfClock_create();
}

void set_texture(struct sfRunner *sf)
{
    sfSprite_setTexture(sf->spritePlayer, sf->texturePlayer, sfTrue);
    sfSprite_setTexture(sf->spriteEnemy, sf->textureEnemy, sfTrue);
    sfSprite_setTexture(sf->spritePlatform, sf->texturePlatform, sfTrue);
    sfSprite_setTexture(sf->spriteSky, sf->textureSky, sfTrue);
    sfSprite_setTexture(sf->spriteBackground, sf->textureBg, sfTrue);
    sfSprite_setTexture(sf->spriteGround, sf->textureGround, sfTrue);
    sfSprite_setTexture(sf->spriteDead, sf->textureDead, sfTrue);
    sfSprite_setTexture(sf->spriteEnd, sf->textureEnd, sfTrue);
    sfSprite_setTexture(sf->spritePortal, sf->texturePortal, sfTrue);
    sfSprite_setTextureRect(sf->spriteSky, sf->rectSky);
    sfSprite_setTextureRect(sf->spritePlayer, sf->rect);
    sfSprite_setTextureRect(sf->spriteBackground, sf->rectBackground);
    sfSprite_setTextureRect(sf->spriteGround, sf->rectGround);
}

void set_other(struct sfRunner *sf)
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
    sfSprite_setPosition(sf->spritePortal, sf->positionPortal);
    sfText_setPosition(sf->pause, sf->positionPause);
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