/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_input
*/

#include "my.h"

void manage_key_pressed_e(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && sf->playerCondition == MENU) {
        sfTexture_destroy(sf->textureEnd);
        sfTexture_destroy(sf->textureDead);
        sfTexture_destroy(sf->textureTitle);
        sfTexture_destroy(sf->textureBoutonPlay);
        sfTexture_destroy(sf->textureBoutonQuit);
        if (sf->e == 0)
            e_equal_0(sf);
        else if (sf->e == 1)
            e_equal_1(sf);
        sfSprite_setTexture(sf->spriteTitle, sf->textureTitle, sfTrue);
        sfSprite_setTexture(sf->spriteBoutonPlay,
        sf->textureBoutonPlay, sfTrue);
        sfSprite_setTexture(sf->spriteBoutonQuit,
        sf->textureBoutonQuit, sfTrue);
        if (sf->changeSize == 800)
            change_size_800(sf);
        else
            change_size_fullscreen(sf);
    }
}

void manage_key_pressed_r(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyR) && ((sf->playerCondition == DEAD &&
    sf->positionPlayer.y > 800) || (sf->playerCondition == END &&
    sf->positionPortal.x < 0))) {
        init_rect(sf);
        init_other(sf);
        init_position(sf);
        set_other(sf);
        if (sf->e == 1) {
            sfText_setColor(sf->score, sfColor_fromRGB(175, 5, 32));
            sfText_setColor(sf->pause, sfColor_fromRGB(175, 5, 32));
        }
        if (sfMusic_getStatus(sf->musicDead) == sfPlaying)
            sfMusic_stop(sf->musicDead);
        for (int i = 0; i < 10; i++)
            sf->scoreStr[i] = 0;
        sf->pauseTime = 0;
        sf->playerCondition = REGULAR;
    }
}

int manage_key_pressed_retrn(struct sfRunner *sf, int playerConditionActual)
{
    if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
    sf->playerCondition != DEAD && sf->playerCondition != END) {
        if (sf->playerCondition == PAUSE) {
            sf->playerCondition = playerConditionActual;
        } else {
            playerConditionActual = sf->playerCondition;
            sf->playerCondition = PAUSE;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
    (sf->playerCondition == DEAD || sf->playerCondition == END)) {
        sfRenderWindow_close(sf->window);
    }
    manage_key_pressed_e(sf);
    manage_key_pressed_r(sf);
    return (playerConditionActual);
}

void manage_key_pressed_space(struct sfRunner *sf)
{
    static int playerConditionActual = REGULAR;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->nearPlatform == 1)
            sf->nearPlatform = 2;
        if (sf->playerCondition == REGULAR) {
            sf->nearPlatform = 1;
            sf->playerCondition = JUMP;
        } else if (sf->playerCondition == ON_PLATFORM_REGULAR) {
            sf->nearPlatform = 1;
            sf->playerCondition = ON_PLATFORM_JUMP;
        }
    }
    playerConditionActual = manage_key_pressed_retrn(sf,
    playerConditionActual);
}