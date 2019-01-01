/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_errors
*/

#include "my.h"

int check_map_char(struct sfRunner *sf)
{
    for (int j = 0; j < sf->mapLine; j++) {
        if ((sf->map2d[0][j] != sf->charNothing &&
        sf->map2d[0][j] != sf->charPlatform &&
        sf->map2d[0][j] != sf->charSpike) ||
        sf->map2d[1][j] != sf->charBottom) {
            my_putstr("Error: Char used must be define in .legend file\n");
            return (84);
        }
        if (sf->map2d[0][j] == sf->charPlatform)
            sf->totalPlatform++;
        else if (sf->map2d[0][j] == sf->charSpike)
            sf->totalSpikes++;
    }
    return (0);
}

int check_map(struct sfRunner *sf)
{
    if (sf->mapLength != 2) {
        my_putstr("Error: The map must contains two lines\n");
        return (84);
    }
    for (int i = 0; i < sf->mapLength; i++) {
        if (my_strlen(sf->map2d[i]) != sf->mapLine) {
            my_putstr("Error: Each lines must have same length\n");
            return (84);
        }
    }
    if (check_map_char(sf) == 84)
        return (84);
    return (0);
}

int check_errors_2(struct sfRunner *sf)
{
    if (!sf->view || !sf->pause || !sf->font || !sf->pause || !sf->clock)
        return (84);
    if (!sf->clockSpawn || !sf->window)
        return (84);
    return (check_map(sf));
}

int check_errors(struct sfRunner *sf)
{
    if (!sf->texturePlayer || !sf->textureEnemy || !sf->textureBg)
        return (84);
    if (!sf->textureSky || !sf->textureGround || !sf->texturePlatform)
        return (84);
    if (!sf->textureDead || !sf->textureEnd || !sf->texturePortal)
        return (84);
    if (!sf->spritePlayer || !sf->spriteEnemy || !sf->spriteBackground)
        return (84);
    if (!sf->spriteSky || !sf->spriteGround || !sf->spritePlatform)
        return (84);
    if (!sf->spriteDead || !sf->spriteEnd || !sf->spritePortal)
        return (84);
    return (check_errors_2(sf));
}

int check_args(int ac, char **av, struct sfRunner *sf)
{
    if (ac < 2) {
        my_putstr("./my_runner: bad arguments: 0 given but 1 required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        help();
        return (1);
    }
    if (ac == 3 && my_strcmp(av[2], "-i") == 0) {
        sf->endless = 1;
    }
    return (0);
}