/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_menu
*/

#include "my.h"

void change_size_800(struct sfRunner *sf)
{
    sfRenderWindow_setFramerateLimit(sf->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
    sfSprite_setTexture(sf->spriteBoutonChangeSize,
    sf->textureBoutonChangeSize, sfTrue);
    sfRenderWindow_clear(sf->window, sfBlack);
    sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonPlay, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonQuit, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonChangeSize, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteTitle, NULL);
    sfRenderWindow_display(sf->window);
}

void change_size_fullscreen(struct sfRunner *sf)
{
    sfRenderWindow_setFramerateLimit(sf->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
    sfSprite_setTexture(sf->spriteBoutonChangeSize,
    sf->textureBoutonChangeSize, sfTrue);
    sfRenderWindow_clear(sf->window, sfBlack);
    sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBackground, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonPlay, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonQuit, NULL);
    sfRenderWindow_drawSprite(sf->window,
    sf->spriteBoutonChangeSize, NULL);
    sfRenderWindow_drawSprite(sf->window, sf->spriteTitle, NULL);
    sfRenderWindow_display(sf->window);
}

void bouton_change_size_2(struct sfRunner *sf)
{
    if (sf->changeSize == 800) {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/changeSize1080.png", NULL);
        sfRenderWindow_destroy(sf->window);
        sf->window = sfRenderWindow_create
        (sf->mode, "Pickle Rick Runner", sfFullscreen | sfClose, NULL);
        change_size_fullscreen(sf);
        sf->changeSize = 1920;
    } else {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/changeSize.png", NULL);
        sfRenderWindow_destroy(sf->window);
        sf->window = sfRenderWindow_create
        (sf->mode, "Pickle Rick Runner", sfClose, NULL);
        change_size_800(sf);
        sf->changeSize = 800;
    }
}

void bouton_change_size(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    if (position.x > sf->positionChangeSize.x &&
    position.x < sf->positionChangeSize.x + 350) {
        if (position.y > sf->positionChangeSize.y &&
        position.y < sf->positionChangeSize.y + 150) {
            bouton_change_size_2(sf);
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