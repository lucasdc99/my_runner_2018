/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_draw
*/

#include "my.h"

void draw_sf(struct sfRunner *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    sfSprite_setTexture(sf->spritePlayer, sf->texturePlayer, sfTrue);
    sfSprite_setTexture(sf->spriteEnemy, sf->textureEnemy, sfTrue);
    sfSprite_setTexture(sf->spriteSky, sf->textureSky, sfTrue);
    sfSprite_setTexture(sf->spriteBackground, sf->textureBg, sfTrue);
    sfSprite_setTexture(sf->spriteGround, sf->textureGround, sfTrue);
    sfSprite_setTextureRect(sf->spriteSky, sf->rectSky);
    sfSprite_setTextureRect(sf->spritePlayer, sf->rect);
    sfSprite_setTextureRect(sf->spriteBackground, sf->rectBackground);
    sfSprite_setTextureRect(sf->spriteGround, sf->rectGround);
    sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlayer, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteEnemy, NULL);
    sfRenderWindow_display(sf->window);
}

void destroy_sf(struct sfRunner *sf)
{
    sfSprite_destroy(sf->spritePlayer);
    sfSprite_destroy(sf->spriteSky);
    sfSprite_destroy(sf->spriteBackground);
    sfSprite_destroy(sf->spriteGround);
    sfSprite_destroy(sf->spriteEnemy);
    sfTexture_destroy(sf->texturePlayer);
    sfTexture_destroy(sf->textureSky);
    sfTexture_destroy(sf->textureBg);
    sfTexture_destroy(sf->textureGround);
    sfTexture_destroy(sf->textureEnemy);
    sfView_destroy(sf->view);
    sfFont_destroy(sf->font);
    sfText_destroy(sf->pause);
    sfClock_destroy(sf->clock);
    sfRenderWindow_destroy(sf->window);
}

int check_errors(struct sfRunner *sf)
{
    if (!sf->texturePlayer || !sf->textureEnemy || !sf->textureSky)
        return (84);
    if (!sf->textureBg || !sf->textureGround)
        return (84);
    if (!sf->spritePlayer || !sf->spriteEnemy || !sf->spriteSky)
        return (84);
    if (!sf->spriteBackground || !sf->spriteGround)
        return (84);
    if (!sf->view)
        return (84);
    if (!sf->font)
        return (84);
    if (!sf->pause)
        return (84);
    if (!sf->clock)
        return (84);
    if (!sf->window)
        return (84);
    return (0);
}