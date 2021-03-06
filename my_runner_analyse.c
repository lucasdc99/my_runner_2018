/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_analyse
*/

#include "my.h"

void analyse_score(struct sfRunner *sf)
{
    int length = 1;
    int tmp = 0;

    sf->scoreInt = (sf->secondSpawn + sf->shift) / 100;
    tmp = sf->scoreInt;
    for (int i = 0; i != 1;) {
        if (tmp / 10 == 0)
            i = 1;
        else
            length++;
        tmp /= 10;
    }
    for (int i = length - 1; i >= 0; i--) {
        sf->scoreStr[i] = sf->scoreInt % 10;
        sf->scoreStr[i] += 48;
        sf->scoreInt /= 10;
    }
    sfText_setString(sf->score, sf->scoreStr);
}

void set_menu(struct sfRunner *sf)
{
    sfSprite_setTexture(sf->spriteBoutonPlay,
    sf->textureBoutonPlay, sfTrue);
    sfSprite_setTexture(sf->spriteBoutonQuit,
    sf->textureBoutonQuit, sfTrue);
    sfSprite_setTexture(sf->spriteBoutonChangeSize,
    sf->textureBoutonChangeSize, sfTrue);
    sfSprite_setTexture(sf->spriteTitle, sf->textureTitle, sfTrue);
    sfSprite_setPosition(sf->spriteBoutonPlay, sf->positionPlay);
    sfSprite_setPosition(sf->spriteBoutonQuit, sf->positionQuit);
    sfSprite_setPosition(sf->spriteBoutonChangeSize,
    sf->positionChangeSize);
    sfSprite_setPosition(sf->spriteTitle, sf->positionTitle);
}

void analyse_menu(struct sfRunner *sf)
{
    static int ok = 0;

    sf->pauseTime = sf->secondSpawn;
    sfClock_restart(sf->clockSpawn);
    if (sf->playerCondition == MENU && sf->changeSize == 800 && ok == 0) {
        modify_texture(sf);
        set_texture(sf);
        sf->musicMenu = sfMusic_createFromFile("music/musicMenu.ogg");
        sfMusic_play(sf->musicMenu);
        ok = 1;
        set_menu(sf);
        change_size_800(sf);
    }
}

void analyse_events_2(struct sfRunner *sf)
{
    if (sf->event.type == sfEvtResized) {
        sf->positionScope.x = sf->event.size.width;
        sf->positionScope.y = sf->event.size.height;
        sfView_setSize(sf->view, sf->positionScope);
        sfRenderWindow_setView(sf->window, sf->view);
    }
    if (sf->event.type == sfEvtMouseButtonPressed &&
    sf->playerCondition == MENU) {
        bouton_play(sf);
        bouton_quit(sf);
        bouton_change_size(sf);
    }
}

void analyse_events(struct sfRunner *sf)
{
    if (sf->event.type == sfEvtClosed) {
        if (sf->playerCondition == MENU) {
            sfMusic_destroy(sf->musicMenu);
            sfTexture_destroy(sf->textureBoutonPlay);
            sfTexture_destroy(sf->textureBoutonQuit);
            sfTexture_destroy(sf->textureBoutonChangeSize);
            sfSprite_destroy(sf->spriteBoutonPlay);
            sfSprite_destroy(sf->spriteBoutonQuit);
            sfSprite_destroy(sf->spriteBoutonChangeSize);
        }
        sfRenderWindow_close(sf->window);
    }
    if (sf->event.type == sfEvtKeyPressed)
        manage_key_pressed_space(sf);
    analyse_events_2(sf);
}