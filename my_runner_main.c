/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_main
*/

#include "get_next_line.h"
#include "my.h"

void manage_spike(struct sfRunner *sf)
{
    sf->positionEnemy.x -= sf->speedEnemy;
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    sf->map[sf->distanceSpawn] = 32;
}

void analyse_map(struct sfRunner *sf)
{
    if (sf->secondSpawn / 1000 == sf->distanceSpawn) {
        if ((sf->map[sf->distanceSpawn] == 0 || sf->map2[sf->distanceSpawn] == 0) && sf->endless == 1) {
            sf->distanceSpawn = 1;
            sfClock_restart(sf->clockSpawn);
        } else if ((sf->map[sf->distanceSpawn] == 0 || sf->map2[sf->distanceSpawn] == 0) && sf->endless == 0) {
            sf->playerCondition = END;
        }
        printf("%d %d %d %d\n", sf->map[sf->distanceSpawn], sf->map2[sf->distanceSpawn], sf->existingSpike, sf->distanceSpawn);
        if (sf->map[sf->distanceSpawn] == '2' || sf->map2[sf->distanceSpawn] == '2') {
            sf->existingSpike = 1;
        }
        sf->distanceSpawn++;
    }
}

void main_loop(struct sfRunner *sf)
{
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        analyse_events(sf);
    if (sf->playerCondition != PAUSE && sf->playerCondition != END
    && sf->positionPlayer.y < 800) {
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->timeSpawn = sfClock_getElapsedTime(sf->clockSpawn);
        sf->seconds = sf->time.microseconds / 1000000.0;
        sf->seconds2 = sf->time.microseconds / 1000.0;
        sf->secondSpawn = sf->timeSpawn.microseconds / 1000.0;
        check_position_player(sf);
        check_position_player_platform(sf);
        check_position_2(sf);
        analyse_map(sf);
        sfSprite_move(sf->spritePlayer, sf->mvmtPlayer);
        if (sf->existingSpike == 1)
            manage_spike(sf);
        sf->positionPlatform.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
        move_rect_background(sf, 320);
        move_rect_ground(sf, 720);
        move_rect_sky(sf, 1900);
        draw_sf(sf);
    }
}

void help(void)
{
    my_putstr("\nUSAGE\n");
    my_putstr("\t./my_runner map.txt\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("\tUse SPACE to jump over spikes and beat the high score !\n");
    my_putstr("\nOPTIONS\n");
    my_putstr("\t-i\tlaunch the game in infinity mode.\n");
    my_putstr("\t-h\tprint the usage and quit.\n");
    my_putstr("\nUSER INTERACTIONS\n");
    my_putstr(" During the game:\n");
    my_putstr("\tSPACE_KEY\tjump.\n");
    my_putstr("\tRETURN_KEY\tpause menu.\n");
    my_putstr(" In the menu:\n");
    my_putstr("\tQ_KEY\t\tquit the game.\n");
    my_putstr("\tRETURN_KEY\tresume game.\n");
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

int main(int ac, char **av)
{
    struct sfRunner *sf = malloc(sizeof(struct sfRunner));
    int fd;

    if (ac < 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 is required\nretry with -h\n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (1);
    }
    if (ac == 3 && my_strcmp(av[2], "-i") == 0) {
        sf->endless = 1;
    }
    fd = open(av[1], O_RDONLY);
    if (fd <= 0) 
        return (84);
    map(sf, fd);
    map_2(sf, fd);
    init_rect(sf);
    init_other(sf);
    create_sf(sf);
    init_position(sf);
    set_sf(sf);
    while (sfRenderWindow_isOpen(sf->window))
        main_loop(sf);
    destroy_sf(sf);
    return (0);
}