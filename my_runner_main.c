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

void manage_key_pressed(struct sfRunner *sf)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sf->mvmtPlayer.y != 30)
            sf->mvmtPlayer.y = -30.0;
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
        printf("ok %f\n", sf->mvmtPlayer.y);
        move_rect(sf, 100, 400);
    }
    if (sf->positionPlayer.y < 200)
        sf->mvmtPlayer.y = 30;
    else if (sf->positionPlayer.y > 400) {
        sf->positionPlayer.y = 400;
        sf->mvmtPlayer.y = 0;
    }
    sfSprite_setPosition(sf->sprite, sf->positionPlayer);
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
    sf->positionPlayer.x = 0;
    sf->positionPlayer.y = 400;
    sf->mvmtPlayer.x = 0.0;
    sf->mvmtPlayer.y = 0.0;
    sf->window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    if (!sf->window)
        return 1;
    sf->texture = sfTexture_createFromFile("images/player.png", NULL);
    if (!sf->texture)
        return 1;
    sf->sprite = sfSprite_create();
    sfSprite_setPosition(sf->sprite, sf->positionPlayer);
    while (sfRenderWindow_isOpen(sf->window))
    {
        while (sfRenderWindow_pollEvent(sf->window, &sf->event))
            analyse_events(sf);
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->seconds = sf->time.microseconds / 1000000.0;
        if (sf->seconds > 0.08) {
            check_position(sf);
            sfSprite_move(sf->sprite, sf->mvmtPlayer);
            sfClock_restart(sf->clock);
        }
        sfRenderWindow_clear(sf->window, sfWhite);
        sfSprite_setTexture(sf->sprite, sf->texture, sfTrue);
        sfSprite_setTextureRect(sf->sprite, sf->rect);
        sfRenderWindow_drawSprite(sf->window, sf->sprite, NULL);
        sfRenderWindow_display(sf->window);
    }
    sfSprite_destroy(sf->sprite);
    sfTexture_destroy(sf->texture);
    sfRenderWindow_destroy(sf->window);
    return 0;
}