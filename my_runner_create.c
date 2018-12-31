/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_create
*/

#include "my.h"

void create_sf(struct sfRunner *sf)
{
    init_rect(sf);
    init_other(sf);
    create_texture_sprite(sf);
    init_position(sf);
    sf->window = sfRenderWindow_create
    (sf->mode, "Pickle Rick Runner", sfClose, NULL);
    set_other(sf);
}

void create_texture_sprite(struct sfRunner *sf)
{
    sf->texturePlayer = sfTexture_createFromFile("images/player.png", NULL);
    sf->textureEnemy = sfTexture_createFromFile("images/spikes.png", NULL);
    sf->textureSky = sfTexture_createFromFile("images/sky.png", NULL);
    sf->textureBg = sfTexture_createFromFile("images/background.png", NULL);
    sf->textureGround = sfTexture_createFromFile("images/ground.png", NULL);
    sf->texturePlatform = sfTexture_createFromFile("images/platfrm.png", NULL);
    sf->textureDead = sfTexture_createFromFile("images/dead.png", NULL);
    sf->textureEnd = sfTexture_createFromFile("images/end.png", NULL);
    sf->texturePortal = sfTexture_createFromFile("images/portal.png", NULL);
    sf->textureBoutonPlay = sfTexture_createFromFile
    ("images/play.png", NULL);
    sf->textureBoutonQuit = sfTexture_createFromFile
    ("images/quit.png", NULL);
    sf->textureBoutonChangeSize = sfTexture_createFromFile
    ("images/changeSize.png", NULL);
    sf->textureTitle = sfTexture_createFromFile("images/title.png", NULL);
    sf->pickleRick = sfMusic_createFromFile("music/pickleRick.ogg");
    sf->help = sfMusic_createFromFile("music/help.ogg");
    create_other(sf);
}

void create_other_2(struct sfRunner *sf)
{
    sf->clock = sfClock_create();
    sf->clockSpawn = sfClock_create();
    sf->musicDead = sfMusic_createFromFile("music/musicDead.ogg");
    sf->start = sfMusic_createFromFile("music/start.ogg");
    sf->view = sfView_createFromRect(sf->rectangleView);
    sf->font = sfFont_createFromFile("fonts/get_schwifty.ttf");
    sf->pause = sfText_create();
    sf->score = sfText_create();
    sf->music = sfMusic_createFromFile("music/music.ogg");
}

void create_other(struct sfRunner *sf)
{
    sf->spriteBoutonPlay = sfSprite_create();
    sf->spriteBoutonQuit = sfSprite_create();
    sf->spriteBoutonChangeSize = sfSprite_create();
    sf->spriteTitle = sfSprite_create();
    sf->spritePlayer = sfSprite_create();
    sf->spriteEnemy = sfSprite_create();
    sf->spriteEnemy2 = sfSprite_create();
    sf->spriteEnemy3 = sfSprite_create();
    sf->spriteSky = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sf->spritePlatform = sfSprite_create();
    sf->spritePlatform2 = sfSprite_create();
    sf->spritePlatform3 = sfSprite_create();
    sf->spriteDead = sfSprite_create();
    sf->spriteEnd = sfSprite_create();
    sf->spritePortal = sfSprite_create();
    create_other_2(sf);
}

void set_texture(struct sfRunner *sf)
{
    sfSprite_setTexture(sf->spritePlayer, sf->texturePlayer, sfTrue);
    sfSprite_setTexture(sf->spriteEnemy, sf->textureEnemy, sfTrue);
    sfSprite_setTexture(sf->spriteEnemy2, sf->textureEnemy, sfTrue);
    sfSprite_setTexture(sf->spriteEnemy3, sf->textureEnemy, sfTrue);
    sfSprite_setTexture(sf->spritePlatform, sf->texturePlatform, sfTrue);
    sfSprite_setTexture(sf->spritePlatform2, sf->texturePlatform, sfTrue);
    sfSprite_setTexture(sf->spritePlatform3, sf->texturePlatform, sfTrue);
    sfSprite_setTexture(sf->spriteSky, sf->textureSky, sfTrue);
    sfSprite_setTexture(sf->spriteBackground, sf->textureBg, sfTrue);
    sfSprite_setTexture(sf->spriteGround, sf->textureGround, sfTrue);
    sfSprite_setTexture(sf->spriteDead, sf->textureDead, sfTrue);
    sfSprite_setTexture(sf->spriteEnd, sf->textureEnd, sfTrue);
    sfSprite_setTexture(sf->spritePortal, sf->texturePortal, sfTrue);
    sfSprite_setTextureRect(sf->spriteSky, sf->rectSky);
    sfSprite_setTextureRect(sf->spritePlayer, sf->rect);
    sfSprite_setTextureRect(sf->spriteBackground, sf->rectBackground);
    sfSprite_setTextureRect(sf->spriteGround, sf->rectGround);
    if (sf->playerCondition != DEAD && sf->playerCondition != END)
        sfText_setString(sf->score, sf->scoreStr);
}