/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_draw
*/

#include "my.h"

void draw_end(struct sfRunner *sf)
{
    if (sf->playerCondition == END && sf->positionPortal.x < 0) {
        sf->positionScore.x = 530;
        if (sf->e == 0)
            sf->positionScore.y = 130;
        else
            sf->positionScore.y = 230;
        sfText_setOutlineColor(sf->score, sfColor_fromRGB(209, 209, 208));
        sfText_setPosition(sf->score, sf->positionScore);
        sfRenderWindow_drawSprite(sf->window, sf->spriteEnd, NULL);
        sfRenderWindow_drawText(sf->window, sf->score, NULL);
        if (sfMusic_getStatus(sf->music) == sfPlaying) {
            sfMusic_stop(sf->music);
            if (sf->e == 0)
                sfMusic_play(sf->pickleRick);
            else {
                sfMusic_destroy(sf->pickleRick);
                sf->pickleRick = sfMusic_createFromFile("music/46753.ogg");
                sfMusic_play(sf->pickleRick);
            }
        }
    }
}

void draw_dead(struct sfRunner *sf)
{
    if (sf->playerCondition == DEAD && sf->positionPlayer.y > 800) {
        sf->positionScore.x = 500;
        if (sf->e == 0)
            sf->positionScore.y = 110;
        else
            sf->positionScore.y = 140;
        sfText_setPosition(sf->score, sf->positionScore);
        sfRenderWindow_drawSprite(sf->window, sf->spriteDead, NULL);
        sfRenderWindow_drawText(sf->window, sf->score, NULL);
        if (sfMusic_getStatus(sf->music) == sfPlaying) {
            sfMusic_stop(sf->music);
            sfMusic_play(sf->help);
            sfMusic_play(sf->musicDead);
        }
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
    sfRenderWindow_drawSprite(sf->window, sf->spriteEnemy2, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteEnemy3, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlatform, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlatform2, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlatform3, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePlayer, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spritePortal, NULL);
    sfRenderWindow_drawText(sf->window, sf->score, NULL);
    if (sf->playerCondition == PAUSE)
        sfRenderWindow_drawText(sf->window, sf->pause, NULL);
    draw_dead(sf);
    draw_end(sf);
    sfRenderWindow_display(sf->window);
}