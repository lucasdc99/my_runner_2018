/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_map
*/

#include "my.h"

int map_2_find_distance(struct sfRunner *sf, int ok)
{
    for (int i = 0; sf->map2[i] != 0; i++) {
        if (sf->map2[i] != 32) {
            sf->distanceSpawn = i;
            ok = 1;
        }
    }
    return (ok);
}

int map_find_distance(struct sfRunner *sf, int ok)
{
    for (int i = 0; sf->map[i] != 0; i++) {
        if (sf->map[i] != 32) {
            sf->distanceSpawn = i;
            ok = 1;
        }
    }
    return (ok);
}

void map_2(struct sfRunner *sf, int fd)
{
    int ok = 0;

    sf->map2 = get_next_line(fd);
    while (ok == 0) {
        ok = map_2_find_distance(sf, ok);
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
        ok = map_find_distance(sf, ok);
        if (ok == 0) {
            free(sf->map);
            sf->map = get_next_line(fd);
        }
    }
}