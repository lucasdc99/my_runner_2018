/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_pause
*/

#include "my.h"

void analyse_after_pause(struct sfRunner *sf)
{
    if (sf->playerCondition != PAUSE && sf->in_game == 0) {
        sfTexture_destroy(sf->texturePlayer);
        sfTexture_destroy(sf->textureEnemy);
        sfTexture_destroy(sf->textureSky);
        sfTexture_destroy(sf->textureBg);
        sfTexture_destroy(sf->textureGround);
        sfTexture_destroy(sf->texturePlatform);
        if (sf->e == 0)
            sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
        else
            sf->texturePlayer = sfTexture_createFromFile("images/75538.png", NULL);
        sf->textureEnemy = sfTexture_createFromFile("images/spikes.png", NULL);
        sf->textureSky = sfTexture_createFromFile("images/sky.png", NULL);
        sf->textureBg = sfTexture_createFromFile("images/background.png", NULL);
        sf->textureGround = sfTexture_createFromFile("images/ground.png", NULL);
        sf->texturePlatform = sfTexture_createFromFile
        ("images/platfrm.png", NULL);
        draw_sf(sf);
        sf->in_game = 1;
        sf->in_pause = 0;
    }
}

void bouton_play(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    if (position.x > sf->positionPlay.x &&
    position.x < sf->positionPlay.x + 150) {
        if (position.y > sf->positionPlay.y &&
        position.y < sf->positionPlay.y + 150) {
            sfMusic_destroy(sf->musicMenu);
            sfTexture_destroy(sf->textureBoutonPlay);
            sfTexture_destroy(sf->textureBoutonQuit);
            sfTexture_destroy(sf->textureBoutonChangeSize);
            sfSprite_destroy(sf->spriteBoutonPlay);
            sfSprite_destroy(sf->spriteBoutonQuit);
            sfSprite_destroy(sf->spriteBoutonChangeSize);
            sfMusic_play(sf->start);
            sf->playerCondition = REGULAR;
            analyse_after_pause(sf);
        }
    }
}

void bouton_quit(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    if (position.x > sf->positionQuit.x &&
    position.x < sf->positionQuit.x + 150) {
        if (position.y > sf->positionQuit.y &&
        position.y < sf->positionQuit.y + 150) {
            sfRenderWindow_destroy(sf->window);
            sfMusic_destroy(sf->musicMenu);
        }
    }
}

void modify_texture(struct sfRunner *sf)
{
    sfTexture_destroy(sf->texturePlayer);
    sfTexture_destroy(sf->textureEnemy);
    sfTexture_destroy(sf->textureSky);
    sfTexture_destroy(sf->textureBg);
    sfTexture_destroy(sf->textureGround);
    sfTexture_destroy(sf->texturePlatform);
    if (sf->e == 0) {
        sf->texturePlayer = sfTexture_createFromFile
        ("images/player_blurr.png", NULL);
    } else {
        sf->texturePlayer = sfTexture_createFromFile
        ("images/75538_blurr.png", NULL);
    }
    sf->textureEnemy = sfTexture_createFromFile
    ("images/spikes_blurr.png", NULL);
    sf->textureSky = sfTexture_createFromFile("images/sky_blurr.png", NULL);
    sf->textureBg = sfTexture_createFromFile
    ("images/background_blurr.png", NULL);
    sf->textureGround = sfTexture_createFromFile
    ("images/ground_blurr.png", NULL);
    sf->texturePlatform = sfTexture_createFromFile
    ("images/platfrm_blurr.png", NULL);
}

void analyse_pause(struct sfRunner *sf)
{
    sf->pauseTime = sf->secondSpawn;
    sfClock_restart(sf->clockSpawn);
    if (sf->playerCondition == PAUSE && sf->in_pause == 0) {
        sfMusic_pause(sf->music);
        modify_texture(sf);
        draw_sf(sf);
        sf->in_pause = 1;
        sf->in_game = 0;
    }
}