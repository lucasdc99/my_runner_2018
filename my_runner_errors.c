/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_errors
*/

#include "my.h"

int check_errors_2(struct sfRunner *sf)
{
    if (!sf->view)
        return (84);
    if (!sf->pause)
        return (84);
    if (!sf->font)
        return (84);
    if (!sf->pause)
        return (84);
    if (!sf->clock)
        return (84);
    if (!sf->clockSpawn)
        return (84);
    if (!sf->window)
        return (84);
    return (0);
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
}