/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_draw
*/

#include "my.h"

void draw_end_dead(struct sfRunner *sf)
{
    if (sf->playerCondition == DEAD && sf->positionPlayer.y > 800) {
        sf->positionScore.x = 500;
        sf->positionScore.y = 110;
        sfText_setPosition(sf->score, sf->positionScore);
        sfRenderWindow_drawSprite(sf->window, sf->spriteDead, NULL);
        sfRenderWindow_drawText(sf->window, sf->score, NULL);
    }
    if (sf->playerCondition == END && sf->positionPortal.x < 0) {
        sf->positionScore.x = 530;
        sf->positionScore.y = 130;
        sfText_setOutlineColor(sf->score, sfColor_fromRGB(209, 209, 208));
        sfText_setPosition(sf->score, sf->positionScore);
        sfRenderWindow_drawSprite(sf->window, sf->spriteEnd, NULL);
        sfRenderWindow_drawText(sf->window, sf->score, NULL);
    }
}

void draw_sf(struct sfRunner *sf)
{
    sfRenderWindow_clear(sf->window, sfBlack);
    set_texture(sf);
    sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteEnemy, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlatform, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlayer, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePortal, NULL);
    sfRenderWindow_drawText(sf->window, sf->score, NULL);
    if (sf->playerCondition == PAUSE)
        sfRenderWindow_drawText(sf->window, sf->pause, NULL);
    draw_end_dead(sf);
    sfRenderWindow_display(sf->window);
}

void destroy_texture_sprite(struct sfRunner *sf)
{
    sfSprite_destroy(sf->spritePlayer);
    sfSprite_destroy(sf->spriteEnemy);
    sfSprite_destroy(sf->spriteBackground);
    sfSprite_destroy(sf->spriteSky);
    sfSprite_destroy(sf->spriteGround);
    sfSprite_destroy(sf->spritePlatform);
    sfSprite_destroy(sf->spriteDead);
    sfSprite_destroy(sf->spriteEnd);
    sfSprite_destroy(sf->spritePortal);
    sfTexture_destroy(sf->texturePlayer);
    sfTexture_destroy(sf->textureEnemy);
    sfTexture_destroy(sf->textureBg);
    sfTexture_destroy(sf->textureSky);
    sfTexture_destroy(sf->textureGround);
    sfTexture_destroy(sf->texturePlatform);
    sfTexture_destroy(sf->textureDead);
    sfTexture_destroy(sf->textureEnd);
    sfTexture_destroy(sf->texturePortal);
    destroy_other(sf);
}

void destroy_other(struct sfRunner *sf)
{
    sfView_destroy(sf->view);
    sfFont_destroy(sf->font);
    sfText_destroy(sf->pause);
    sfClock_destroy(sf->clock);
    sfClock_destroy(sf->clockSpawn);
    free(sf->map);
    free(sf->map2);
    free(sf->scoreStr);
}