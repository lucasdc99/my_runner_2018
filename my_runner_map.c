/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_map
*/

#include "my.h"

void analyse_map_2(struct sfRunner *sf, int i)
{
    if (sf->distanceSpawn > sf->mapLine && sf->endless == 1) {
        sf->distanceSpawn = 1;
        sf->shift = sf->secondSpawn;
        sfClock_restart(sf->clockSpawn);
    } else if (sf->distanceSpawn > sf->mapLine && sf->endless == 0 &&
    sf->existingPlatform <= 0 && sf->existingSpike <= 0 &&
    sf->positionEnemy.x == 1000 && sf->positionEnemy2.x == 1000 &&
    sf->positionEnemy3.x == 1000 && sf->positionPlatform.x == 1000 &&
    sf->positionPlatform2.x == 1000 && sf->positionPlatform3.x == 1000) {
        sf->playerCondition = END;
    }
    if (sf->map2d[i][sf->distanceSpawn] == sf->charPlatform)
        sf->existingPlatform++;
    if (sf->map2d[i][sf->distanceSpawn] == sf->charSpike)
        sf->existingSpike++;
}

void analyse_map(struct sfRunner *sf)
{
    if (sf->secondSpawn / 1000 == sf->distanceSpawn) {
        for (int i = 0; i < sf->mapLength - 1; i++) {
            analyse_map_2(sf, i);
        }
        sf->distanceSpawn++;
    }
}

void find_char_for_map(struct sfRunner *sf)
{
    int fd = open(".legend", O_RDONLY);
    char *buffer = get_next_line(fd);

    while (my_strcmp(buffer, "Legend:") != 0) {
        buffer = get_next_line(fd);
    }
    for (int i = 0; i < 4; i++) {
        buffer = get_next_line(fd);
        while (*buffer != 39)
            buffer++;
        if (i == 0)
            sf->charNothing = buffer[1];
        if (i == 1)
            sf->charBottom = buffer[1];
        if (i == 2)
            sf->charPlatform = buffer[1];
        if (i == 3)
            sf->charSpike = buffer[1];
    }
}

void analyse_buffer(struct sfRunner *sf, char *buffer)
{
    if (buffer == NULL) {
        sf->mapLine = -1;
        return;
    }
    sf->mapLine = my_strlen(buffer);
    sf->mapLength = 0;
}

void create_map(struct sfRunner *sf, int fd, char *av)
{
    char *buffer = get_next_line(fd);

    analyse_buffer(sf, buffer);
    if (sf->mapLine == -1)
        return;
    find_char_for_map(sf);
    while (buffer != NULL) {
        sf->mapLength++;
        buffer = get_next_line(fd);
    }
    sf->map2d = malloc(sizeof(char *) * sf->mapLength);
    for (int i = 0; i < sf->mapLength; i++)
        sf->map2d[i] = malloc(sizeof(char) * sf->mapLine);
    fd = open(av, O_RDONLY);
    for (int i = 0; i < sf->mapLength; i++) {
        buffer = get_next_line(fd);
        for (int j = 0; j < sf->mapLine; j++) {
            sf->map2d[i][j] = buffer[j];
        }
    }
}