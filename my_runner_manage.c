/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_manage
*/

#include "my.h"

void e_equal_0(struct sfRunner *sf)
{
    sf->textureEnd = sfTexture_createFromFile("images/92829.png", NULL);
    sf->textureDead = sfTexture_createFromFile("images/18922.png", NULL);
    sf->textureTitle = sfTexture_createFromFile("images/35783.png", NULL);
    sf->textureBoutonPlay = sfTexture_createFromFile("images/28272.png", NULL);
    sf->textureBoutonQuit = sfTexture_createFromFile("images/45278.png", NULL);
    if (sf->changeSize == 800) {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/51892.png", NULL);
    } else {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/67291.png", NULL);
    }
    sfText_setColor(sf->score, sfColor_fromRGB(175, 5, 32));
    sfText_setColor(sf->pause, sfColor_fromRGB(175, 5, 32));
    sf->e = 1;
}

void e_equal_1(struct sfRunner *sf)
{
    sf->textureEnd = sfTexture_createFromFile("images/end.png", NULL);
    sf->textureDead = sfTexture_createFromFile("images/dead.png", NULL);
    sf->textureTitle = sfTexture_createFromFile("images/title.png", NULL);
    sf->textureBoutonPlay = sfTexture_createFromFile("images/play.png", NULL);
    sf->textureBoutonQuit = sfTexture_createFromFile("images/quit.png", NULL);
    if (sf->changeSize == 800) {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/changeSize.png", NULL);
    } else {
        sf->textureBoutonChangeSize = sfTexture_createFromFile
        ("images/changeSize1080.png", NULL);
    }
    sfText_setColor(sf->score, sfColor_fromRGBA(76, 130, 38, 255));
    sfText_setColor(sf->pause, sfColor_fromRGBA(76, 130, 38, 255));
    sf->e = 0;
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

void manage_portal(struct sfRunner *sf)
{
    sf->positionPortal.x -= sf->speedEnemy;
    sfSprite_setPosition(sf->spritePortal, sf->positionPortal);
}