/*
** EPITECH PROJECT, 2018
** MUL_my_runner_2018
** File description:
** my_runner_main
*/

#include "get_next_line.h"
#include "my.h"

void increase_speed(struct sfRunner *sf)
{
    static int already_increase = 0;

    if ((sf->secondSpawn / 1000) % 20 == 0 &&
    already_increase != sf->secondSpawn / 1000) {
        sf->speedMoveGround += 2;
        sf->speedMoveBackground++;
        sf->speedMoveSky++;
        sf->speedPlayer -= 5;
        already_increase = sf->secondSpawn / 1000;
    }
}

void main_loop_2(struct sfRunner *sf)
{
    sfSprite_move(sf->spritePlayer, sf->mvmtPlayer);
    if (sf->existingSpike >= 1)
        manage_spike(sf);
    if (sf->existingPlatform >= 1)
        manage_platform(sf);
    if (sf->playerCondition == END)
        manage_portal(sf);
    increase_speed(sf);
    move_rect_background(sf);
    move_rect_ground(sf);
    move_rect_sky(sf);
    sf->speedEnemy = 1.225 * sf->speedMoveGround;
    draw_sf(sf);
}

void analyse_menu(struct sfRunner *sf)
{
    sf->pauseTime = sf->secondSpawn;
    sfClock_restart(sf->clockSpawn);
    if (sf->playerCondition == MENU && sf->changeSize == 800) {
        modify_texture(sf);
        set_texture(sf);
        sf->textureBoutonPlay = sfTexture_createFromFile("images/play.png", NULL);
        sf->textureBoutonQuit = sfTexture_createFromFile("images/quit.png", NULL);
        sf->textureBoutonChangeSize = sfTexture_createFromFile("images/changeSize.png", NULL);
        sf->textureTitle = sfTexture_createFromFile("images/title.png", NULL);
        sf->spriteBoutonPlay = sfSprite_create();
        sf->spriteBoutonQuit = sfSprite_create();
        sf->spriteBoutonChangeSize = sfSprite_create();
        sf->spriteTitle = sfSprite_create();
        sfSprite_setTexture(sf->spriteBoutonPlay, sf->textureBoutonPlay, sfTrue);
        sfSprite_setTexture(sf->spriteBoutonQuit, sf->textureBoutonQuit, sfTrue);
        sfSprite_setTexture(sf->spriteBoutonChangeSize, sf->textureBoutonChangeSize, sfTrue);
        sfSprite_setTexture(sf->spriteTitle, sf->textureTitle, sfTrue);
        sfSprite_setPosition(sf->spriteBoutonPlay, sf->positionPlay);
        sfSprite_setPosition(sf->spriteBoutonQuit, sf->positionQuit);
        sfSprite_setPosition(sf->spriteBoutonChangeSize, sf->positionChangeSize);
        sfSprite_setPosition(sf->spriteTitle, sf->positionTitle);
        sfRenderWindow_clear(sf->window, sfBlack);
        sfRenderWindow_drawSprite(sf->window, sf->spriteSky, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteBackground, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteGround, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonPlay, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonQuit, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteBoutonChangeSize, NULL);
        sfRenderWindow_drawSprite(sf->window, sf->spriteTitle, NULL);
        sfRenderWindow_display(sf->window);
    }
}

void main_loop(struct sfRunner *sf)
{
    while (sfRenderWindow_pollEvent(sf->window, &sf->event))
        analyse_events(sf);
    if (sf->playerCondition != PAUSE && sf->playerCondition != MENU &&
    sf->positionPortal.x > -100 && sf->positionPlayer.y < 800) {
        analyse_after_pause(sf);
        sf->time = sfClock_getElapsedTime(sf->clock);
        sf->timeSpawn = sfClock_getElapsedTime(sf->clockSpawn);
        sf->seconds = sf->time.microseconds / 1000000.0;
        sf->seconds2 = sf->time.microseconds / 1000.0;
        sf->secondSpawn = sf->timeSpawn.microseconds / 1000.0 + sf->pauseTime;
        check_player_condition(sf);
        check_position_player(sf);
        check_position_player_platform(sf);
        check_position_2(sf);
        analyse_score(sf);
        analyse_map(sf);
        main_loop_2(sf);
    } else {
        analyse_menu(sf);
        analyse_pause(sf);
    }
}

void help(void)
{
    my_putstr("\nUSAGE\n");
    my_putstr("\t./my_runner map.txt\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("\tUse SPACE to jump over spikes and beat the high score !\n");
    my_putstr("\nOPTIONS\n");
    my_putstr("\t-i\tlaunch the game in infinity mode.\n");
    my_putstr("\t-h\tprint the usage and quit.\n");
    my_putstr("\nUSER INTERACTIONS\n");
    my_putstr(" During the game:\n");
    my_putstr("\tSPACE_KEY\tjump.\n");
    my_putstr("\tRETURN_KEY\tpause menu.\n");
    my_putstr(" In the menu:\n");
    my_putstr("\tQ_KEY\t\tquit the game.\n");
    my_putstr("\tRETURN_KEY\tresume game.\n");
}

int main(int ac, char **av)
{
    struct sfRunner *sf = malloc(sizeof(struct sfRunner));
    int fd;

    if (check_args(ac, av, sf) != 84)
        fd = open(av[1], O_RDONLY);
    else
        return (84);
    if (fd <= 0)
        return (84);
    map(sf, fd);
    map_2(sf, fd);
    create_sf(sf);
    if (check_errors(sf) == 84)
        return (84);
    while (sfRenderWindow_isOpen(sf->window))
        main_loop(sf);
    destroy_texture_sprite(sf);
    sfRenderWindow_destroy(sf->window);
    return (0);
}