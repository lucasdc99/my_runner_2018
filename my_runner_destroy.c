/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_destroy
*/

#include "my.h"

void destroy_texture_sprite(struct sfRunner *sf)
{
    sfSprite_destroy(sf->spritePlayer);
    sfSprite_destroy(sf->spriteEnemy);
    sfSprite_destroy(sf->spriteEnemy2);
    sfSprite_destroy(sf->spriteEnemy3);
    sfSprite_destroy(sf->spriteBackground);
    sfSprite_destroy(sf->spriteSky);
    sfSprite_destroy(sf->spriteGround);
    sfSprite_destroy(sf->spritePlatform);
    sfSprite_destroy(sf->spriteDead);
    sfSprite_destroy(sf->spriteEnd);
    sfSprite_destroy(sf->spritePortal);
    sfSprite_destroy(sf->spriteTitle);
    sfTexture_destroy(sf->texturePlayer);
    sfTexture_destroy(sf->textureEnemy);
    sfTexture_destroy(sf->textureBg);
    sfTexture_destroy(sf->textureSky);
    sfTexture_destroy(sf->textureGround);
    destroy_other(sf);
}

void destroy_other_2(struct sfRunner *sf)
{
    sfSprite_destroy(sf->spritePlatform2);
    sfSprite_destroy(sf->spritePlatform3);
    free(sf->scoreStr);
    free(sf->map2d);
}

void destroy_other(struct sfRunner *sf)
{
    sfTexture_destroy(sf->texturePlatform);
    sfTexture_destroy(sf->textureDead);
    sfTexture_destroy(sf->textureEnd);
    sfTexture_destroy(sf->texturePortal);
    sfTexture_destroy(sf->textureTitle);
    sfView_destroy(sf->view);
    sfFont_destroy(sf->font);
    sfText_destroy(sf->pause);
    sfText_destroy(sf->score);
    sfClock_destroy(sf->clock);
    sfClock_destroy(sf->clockSpawn);
    sfMusic_destroy(sf->pickleRick);
    sfMusic_destroy(sf->help);
    sfMusic_destroy(sf->music);
    sfMusic_destroy(sf->musicDead);
    sfMusic_destroy(sf->start);
    destroy_other_2(sf);
}