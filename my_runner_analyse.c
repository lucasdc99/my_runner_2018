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

void map_2(struct sfRunner *sf, int fd)
{
    int ok = 0;

    sf->map2 = get_next_line(fd);
    while (ok == 0) {
        for (int i = 0; sf->map2[i] != 0; i++) {
            if (sf->map2[i] != 32) {
                sf->distanceSpawn = i;
                ok = 1;
            }
        }
        if (ok == 0) {
            free(sf->map2);
            sf->map2 = get_next_line(fd);
        }
    }
}

void map(struct sfRunner *sf, int fd)
{
    int ok = 0;

    sf->map = get_next_line(fd);
    while (ok == 0) {
        for (int i = 0; sf->map[i] != 0; i++) {
            if (sf->map[i] != 32) {
                sf->distanceSpawn = i;
                ok = 1;
            }
        }
        if (ok == 0) {
            free(sf->map);
            sf->map = get_next_line(fd);
        }
    }
}