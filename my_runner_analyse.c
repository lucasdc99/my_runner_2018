/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_analyse
*/

#include "my.h"

void analyse_after_pause(struct sfRunner *sf)
{
    if (sf->playerCondition != PAUSE && sf->in_game == 0) {
        sfTexture_destroy(sf->texturePlayer);
        sfTexture_destroy(sf->textureEnemy);
        sfTexture_destroy(sf->textureSky);
        sfTexture_destroy(sf->textureBg);
        sfTexture_destroy(sf->textureGround);
        sfTexture_destroy(sf->texturePlatform);
        sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
        sf->textureEnemy = sfTexture_createFromFile("images/spikes.png", NULL);
        sf->textureSky = sfTexture_createFromFile("images/sky.png", NULL);
        sf->textureBg = sfTexture_createFromFile("images/background.png", NULL);
        sf->textureGround = sfTexture_createFromFile("images/ground.png", NULL);
        sf->texturePlatform = sfTexture_createFromFile
        ("images/platfrm.png", NULL);
        draw_sf(sf);
        sf->in_game = 1;
        sf->in_pause = 0;
    }
}

void analyse_score(struct sfRunner *sf)
{
    int length = 1;
    int tmp = 0;

    sf->scoreInt = (sf->secondSpawn + sf->shift) / 100;
    tmp = sf->scoreInt;
    for (int i = 0; i != 1;) {
        if (tmp / 10 == 0) {
            i = 1;
            tmp /= 10;
        } else {
            tmp /= 10;
            length++;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        sf->scoreStr[i] = sf->scoreInt % 10;
        sf->scoreStr[i] += 48;
        sf->scoreInt /= 10;
    }
    sfText_setString(sf->score, sf->scoreStr);
}

void analyse_map(struct sfRunner *sf)
{
    if (sf->secondSpawn / 1000 == sf->distanceSpawn) {
        if ((sf->map[sf->distanceSpawn] == 0 ||
        sf->map2[sf->distanceSpawn] == 0) && sf->endless == 1) {
            sf->distanceSpawn = 1;
            sf->shift = sf->secondSpawn;
            sfClock_restart(sf->clockSpawn);
        } else if ((sf->map[sf->distanceSpawn] == 0 ||
            sf->map2[sf->distanceSpawn] == 0) &&
            sf->endless == 0 && sf->existingPlatform == 0
            && sf->existingSpike == 0)
            sf->playerCondition = END;
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

void bouton_play(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);

    if (position.x > sf->positionPlay.x &&
    position.x < sf->positionPlay.x + 150) {
        if (position.y > sf->positionPlay.y &&
        position.y < sf->positionPlay.y + 150) {
            sf->playerCondition = REGULAR;
            analyse_after_pause(sf);
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
        }
    }
}

void bouton_change_size(struct sfRunner *sf)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(sf->window);
    sfVector2u size = {1920, 1080};

    if (position.x > sf->positionChangeSize.x &&
    position.x < sf->positionChangeSize.x + 350) {
        if (position.y > sf->positionChangeSize.y &&
        position.y < sf->positionChangeSize.y + 150) {
            if (sf->changeSize == 800) {
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/changeSize1080.png", NULL);
                sfRenderWindow_destroy(sf->window);
                sf->window = sfRenderWindow_create
                (sf->mode, "Pickle Rick Runner", sfFullscreen | sfClose, NULL);
                sfRenderWindow_setFramerateLimit(sf->window, 60);
                sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
                sf->scalePlatform.x = 0.8;
                sf->scalePlatform.y = 0.8;
                sf->scaleBackground.x = 1.6;
                sf->scaleBackground.y = 1.6;
                sf->scaleGround.x = 1.2;
                sf->scaleGround.y = 1.2;
                sfSprite_setTexture(sf->spriteBoutonChangeSize, sf->textureBoutonChangeSize, sfTrue);
                sfRenderWindow_clear(sf->window, sfBlack);
                sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonPlay, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonQuit, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonChangeSize, NULL);
                sfRenderWindow_drawSprite(sf->window, sf->spriteTitle, NULL);
                sfRenderWindow_display(sf->window);
                sf->changeSize = 1080;
            } else {
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/changeSize.png", NULL);
                sfRenderWindow_destroy(sf->window);
                sf->window = sfRenderWindow_create
                (sf->mode, "Pickle Rick Runner", sfClose, NULL);
                sfRenderWindow_setFramerateLimit(sf->window, 60);
                sfRenderWindow_setVerticalSyncEnabled(sf->window, sfTrue);
                sf->changeSize = 800;
            }
        }
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
    if (sf->event.type == sfEvtMouseButtonPressed && sf->playerCondition == MENU) {
        bouton_play(sf);
        bouton_quit(sf);
        bouton_change_size(sf);
    }
}