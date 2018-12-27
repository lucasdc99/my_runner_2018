/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_analyse
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
        sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
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

void analyse_score(struct sfRunner *sf)
{
    int length = 1;
    int tmp = 0;

    sf->scoreInt = (sf->secondSpawn + sf->shift) / 100;
    tmp = sf->scoreInt;
    for (int i = 0; i != 1;) {
        if (tmp / 10 == 0) {
            i = 1;
            tmp /= 10;
        } else {
            tmp /= 10;
            length++;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        sf->scoreStr[i] = sf->scoreInt % 10;
        sf->scoreStr[i] += 48;
        sf->scoreInt /= 10;
    }
    sfText_setString(sf->score, sf->scoreStr);
}

void analyse_map(struct sfRunner *sf)
{
    if (sf->secondSpawn / 1000 == sf->distanceSpawn) {
        if ((sf->map[sf->distanceSpawn] == 0 ||
        sf->map2[sf->distanceSpawn] == 0) && sf->endless == 1) {
            sf->distanceSpawn = 1;
            sf->shift = sf->secondSpawn;
            sfClock_restart(sf->clockSpawn);
        } else if ((sf->map[sf->distanceSpawn] == 0 ||
            sf->map2[sf->distanceSpawn] == 0) &&
            sf->endless == 0 && sf->existingPlatform == 0
            && sf->existingSpike == 0)
            sf->playerCondition = END;
        if (sf->map[sf->distanceSpawn] == '2' ||
        sf->map2[sf->distanceSpawn] == '2') {
            sf->existingSpike++;
        } else if (sf->map[sf->distanceSpawn] == '3' ||
        sf->map2[sf->distanceSpawn] == '3') {
            sf->existingPlatform++;
        }
        sf->distanceSpawn++;
    }
}

void analyse_events(struct sfRunner *sf)
{
    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtKeyPressed)
        manage_key_pressed(sf);
    if (sf->event.type == sfEvtResized) {
        sf->positionScope.x = sf->event.size.width;
        sf->positionScope.y = sf->event.size.height;
        sfView_setSize(sf->view, sf->positionScope);
        sfRenderWindow_setView(sf->window, sf->view);
    }
}