/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_manage
*/

#include "my.h"

void manage_key_pressed_3(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
    (sf->playerCondition == DEAD || sf->playerCondition == END)) {
        sfRenderWindow_close(sf->window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
    sf->playerCondition == MENU) {
        if (sf->e == 0) {
            sfTexture_destroy(sf->textureEnd);
            sfTexture_destroy(sf->textureDead);
            sfTexture_destroy(sf->textureTitle);
            sfTexture_destroy(sf->textureBoutonPlay);
            sfTexture_destroy(sf->textureBoutonQuit);
            sf->textureEnd = sfTexture_createFromFile("images/92829.png", NULL);
            sf->textureDead = sfTexture_createFromFile("images/18922.png", NULL);
            sf->textureTitle = sfTexture_createFromFile("images/35783.png", NULL);
            sf->textureBoutonPlay = sfTexture_createFromFile("images/28272.png", NULL);
            sf->textureBoutonQuit = sfTexture_createFromFile("images/45278.png", NULL);
            if (sf->changeSize == 800)
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/51892.png", NULL);
            else
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/67291.png", NULL);
            sfSprite_setTexture(sf->spriteTitle, sf->textureTitle, sfTrue);
            sfSprite_setTexture(sf->spriteBoutonPlay, sf->textureBoutonPlay, sfTrue);
            sfSprite_setTexture(sf->spriteBoutonQuit, sf->textureBoutonQuit, sfTrue);
            sfText_setColor(sf->score, sfColor_fromRGB(175, 5, 32));
            sfText_setColor(sf->pause, sfColor_fromRGB(175, 5, 32));
            if (sf->changeSize == 800)
                change_size_800(sf);
            else
                change_size_fullscreen(sf);
            sf->e = 1;
        } else if (sf->e == 1) {
            sfTexture_destroy(sf->textureEnd);
            sfTexture_destroy(sf->textureDead);
            sfTexture_destroy(sf->textureTitle);
            sfTexture_destroy(sf->textureBoutonPlay);
            sfTexture_destroy(sf->textureBoutonQuit);
            sf->textureEnd = sfTexture_createFromFile("images/end.png", NULL);
            sf->textureDead = sfTexture_createFromFile("images/dead.png", NULL);
            sf->textureTitle = sfTexture_createFromFile("images/title.png", NULL);
            sf->textureBoutonPlay = sfTexture_createFromFile("images/play.png", NULL);
            sf->textureBoutonQuit = sfTexture_createFromFile("images/quit.png", NULL);
            if (sf->changeSize == 800)
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/changeSize.png", NULL);
            else
                sf->textureBoutonChangeSize = sfTexture_createFromFile("images/changeSize1080.png", NULL);
            sfSprite_setTexture(sf->spriteTitle, sf->textureTitle, sfTrue);
            sfSprite_setTexture(sf->spriteBoutonPlay, sf->textureBoutonPlay, sfTrue);
            sfSprite_setTexture(sf->spriteBoutonQuit, sf->textureBoutonQuit, sfTrue);
            sfText_setColor(sf->score, sfColor_fromRGBA(76, 130, 38, 255));
            sfText_setColor(sf->pause, sfColor_fromRGBA(76, 130, 38, 255));
            if (sf->changeSize == 800)
                change_size_800(sf);
            else
                change_size_fullscreen(sf);
            sf->e = 0;
        }
    }
}

void manage_key_pressed_2(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeyR) && ((sf->playerCondition == DEAD &&
    sf->positionPlayer.y > 800) || (sf->playerCondition == END &&
    sf->positionPortal.x < 0))) {
        init_rect(sf);
        init_other(sf);
        init_position(sf);
        sf->speedMoveBackground = 1;
        sf->speedMoveGround = 3;
        sf->speedMoveSky = 2;
        sf->existingPlatform = 0;
        sf->existingSpike = 0;
        sf->secondSpawn = 0;
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
    manage_key_pressed_3(sf);
}

void manage_key_pressed(struct sfRunner *sf)
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
    } else if (sfKeyboard_isKeyPressed(sfKeyReturn) &&
    sf->playerCondition != DEAD && sf->playerCondition != END) {
        if (sf->playerCondition == PAUSE) {
            sf->playerCondition = playerConditionActual;
        } else {
            playerConditionActual = sf->playerCondition;
            sf->playerCondition = PAUSE;
        }
    }
    manage_key_pressed_2(sf);
}

void manage_spike(struct sfRunner *sf)
{
    if (sf->existingSpike > 0 || sf->positionEnemy.x < 1000) {
        sf->positionEnemy.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    }
    if (sf->existingSpike > 1 || sf->positionEnemy2.x < 1000) {
        sf->positionEnemy2.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spriteEnemy2, sf->positionEnemy2);
    }
    if (sf->existingSpike > 2 || sf->positionEnemy3.x < 1000) {
        sf->positionEnemy3.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spriteEnemy3, sf->positionEnemy3);
    }
}

void manage_platform(struct sfRunner *sf)
{
    if (sf->existingPlatform > 0 || sf->positionPlatform.x < 1000) {
        sf->positionPlatform.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spritePlatform, sf->positionPlatform);
    }
    if (sf->existingPlatform > 1 || sf->positionPlatform2.x < 1000) {
        sf->positionPlatform2.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spritePlatform2, sf->positionPlatform2);
    }
    if (sf->existingPlatform > 2 || sf->positionPlatform3.x < 1000) {
        sf->positionPlatform3.x -= sf->speedEnemy;
        sfSprite_setPosition(sf->spritePlatform3, sf->positionPlatform3);
    }
}