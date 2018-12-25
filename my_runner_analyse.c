/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_analyse
*/

#include "my.h"

void analyse_map(struct sfRunner *sf)
{
    if (sf->secondSpawn / 1000 == sf->distanceSpawn) {
        if ((sf->map[sf->distanceSpawn] == 0 ||
        sf->map2[sf->distanceSpawn] == 0) && sf->endless == 1) {
            sf->distanceSpawn = 1;
            sfClock_restart(sf->clockSpawn);
        } else if ((sf->map[sf->distanceSpawn] == 0 ||
        sf->map2[sf->distanceSpawn] == 0) &&
        sf->endless == 0 && sf->existingPlatform == 0
        && sf->existingSpike == 0) {
            sf->playerCondition = END;
        }
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