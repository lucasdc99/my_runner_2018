/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** myrunner
*/

#include "my.h"

void move_rect(struct sfRunner *sf, int offset, int max_value)
{
    sf->rect.left += offset;
    if (sf->rect.left == max_value) {
        sf->rect.left = 0;
    }
}

void move_rect_ground(struct sfRunner *sf, int offset, int max_value)
{
    sf->rectGround.left += offset;
    if (sf->rectGround.left == max_value) {
        sf->rectGround.left = 0;
    }
}

void move_rect_background(struct sfRunner *sf, int offset, int max_value)
{
    sf->rectBackground.left += offset;
    if (sf->rectBackground.left == max_value) {
        sf->rectBackground.left = 0;
    }
}

void move_rect_sky(struct sfRunner *sf, int offset, int max_value)
{
    sf->rectSky.left += offset;
    if (sf->rectSky.left == max_value) {
        sf->rectSky.left = 0;
    }
}

void manage_key_pressed(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->mvmtPlayer.y != 10) {
            //sf->mvmtPlayer.x = 10;
            sf->mvmtPlayer.y = -30.0;
        }
    }
}

void analyse_events(struct sfRunner *sf)
{
    if (sf->event.type == sfEvtClosed)
        sfRenderWindow_close(sf->window);
    if (sf->event.type == sfEvtKeyPressed)
        manage_key_pressed(sf);
}

void check_position(struct sfRunner *sf)
{
    sf->positionPlayer = sfSprite_getPosition(sf->sprite);
    if (sf->mvmtPlayer.y != 30 && sf->mvmtPlayer.y != -30) {
        move_rect(sf, 100, 400);
    }
    if (sf->positionPlayer.y < 200) {
        sf->mvmtPlayer.y = 10;
    }
    else if (sf->positionPlayer.y > 400) {
        sf->positionPlayer.y = 400;
        sf->mvmtPlayer.y = 0;
        sf->mvmtPlayer.x = -4;
    }
    if (sf->positionPlayer.x < 60)
        sf->mvmtPlayer.x = 0;
    sfSprite_setPosition(sf->sprite, sf->positionPlayer);
    sf->positionEnemy.x -= 8;
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
}

int main()
{
    sfVideoMode mode = {800, 600, 32};
    struct sfRunner *sf = malloc(sizeof(struct sfRunner));

    sf->clock = sfClock_create();
    sf->rect.top = 0;
    sf->rect.left = 0;
    sf->rect.width = 100;
    sf->rect.height = 200;
    sf->rectSky.top = 0;
    sf->rectSky.left = 0;
    sf->rectSky.width = 1920;
    sf->rectSky.height = 1080;
    sf->rectBackground.top = 0;
    sf->rectBackground.left = 0;
    sf->rectBackground.width = 800;
    sf->rectBackground.height = 240;
    sf->rectGround.top = 490;
    sf->rectGround.left = 0;
    sf->rectGround.width = 800;
    sf->rectGround.height = 960;
    sf->positionPlayer.x = 60;
    sf->positionPlayer.y = 400;
    sf->positionEnemy.x = 400;
    sf->positionEnemy.y = 400;
    sf->positionSky.x = 0;
    sf->positionSky.y = -50;
    sf->positionBackground.x = 0;
    sf->positionBackground.y = 50;
    sf->positionGround.x = 0;
    sf->positionGround.y = 130;
    sf->mvmtPlayer.x = 0.0;
    sf->mvmtPlayer.y = 0.0;
    sf->scaleSky.x = 0.6;
    sf->scaleSky.y = 0.6;
    sf->scaleBackground.x = 1.6;
    sf->scaleBackground.y = 1.6;
    sf->scaleGround.x = 1.2;
    sf->scaleGround.y = 1.2;
    sf->window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!sf->window)
        return 1;
    sf->texture = sfTexture_createFromFile("images/player.png", NULL);
    sf->enemy = sfTexture_createFromFile("images/enemy1.png", NULL);
    sf->sky = sfTexture_createFromFile("images/sky.png", NULL);
    sf->background = sfTexture_createFromFile("images/background.png", NULL);
    sf->ground = sfTexture_createFromFile("images/ground.png", NULL);
    if (!sf->texture || !sf->sky || !sf->background)
        return 1;
    sf->sprite = sfSprite_create();
    sf->spriteEnemy = sfSprite_create();
    sf->spriteSky = sfSprite_create();
    sf->spriteBackground = sfSprite_create();
    sf->spriteGround = sfSprite_create();
    sfSprite_setPosition(sf->sprite, sf->positionPlayer);
    sfSprite_setPosition(sf->spriteEnemy, sf->positionEnemy);
    sfSprite_setPosition(sf->spriteBackground, sf->positionBackground);
    sfSprite_setPosition(sf->spriteGround, sf->positionGround);
    sfSprite_setPosition(sf->spriteSky, sf->positionSky);
    sfSprite_setScale(sf->spriteSky, sf->scaleSky);
    sfSprite_setScale(sf->spriteBackground, sf->scaleBackground);
    sfSprite_setScale(sf->spriteGround, sf->scaleGround);
    while (sfRenderWindow_isOpen(sf->window))
    {
        while (sfRenderWindow_pollEvent(sf->window, &sf->event))
            analyse_events(sf);
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->seconds = sf->time.microseconds / 1000000.0;
        if (sf->seconds > 0.08) {
            sfSprite_move(sf->sprite, sf->mvmtPlayer);
            check_position(sf);
            move_rect_background(sf, 2, 645);
            move_rect_ground(sf, 8, 720);
            move_rect_sky(sf, 2, 1900);
            sfClock_restart(sf->clock);
        }
        sfRenderWindow_clear(sf->window, sfBlack);
        sfSprite_setTexture(sf->sprite, sf->texture, sfTrue);
        sfSprite_setTexture(sf->spriteEnemy, sf->enemy, sfTrue);
        sfSprite_setTexture(sf->spriteSky, sf->sky, sfTrue);
        sfSprite_setTexture(sf->spriteBackground, sf->background, sfTrue);
        sfSprite_setTexture(sf->spriteGround, sf->ground, sfTrue);
        sfSprite_setTextureRect(sf->spriteSky, sf->rectSky);
        sfSprite_setTextureRect(sf->sprite, sf->rect);
        sfSprite_setTextureRect(sf->spriteBackground, sf->rectBackground);
        sfSprite_setTextureRect(sf->spriteGround, sf->rectGround);
        sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteEnemy, NULL);
        sfRenderWindow_display(sf->window);
    }
    sfSprite_destroy(sf->sprite);
    sfTexture_destroy(sf->texture);
    sfRenderWindow_destroy(sf->window);
    return 0;
}