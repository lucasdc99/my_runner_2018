/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

struct sfHunter {
    sfRenderWindow* window;
    sfTexture *texture;
    sfTexture *background;
    sfTexture *backgroundMenu;
    sfTexture *ground;
    sfTexture *scope;
    sfTexture *bouton;
    sfTexture *boutonRestart;
    sfTexture *boutonQuit;
    sfSprite *sprite;
    sfSprite *spriteScope;
    sfSprite *spriteBackground;
    sfSprite *spriteBackgroundMenu;
    sfSprite *spriteGround;
    sfSprite *spriteBouton;
    sfSprite *spriteBoutonRestart;
    sfText *text;
    sfText *lives;
    sfText *score;
    sfText *over;
    sfFont *font;
    sfEvent event;
    sfIntRect rect;
    sfVector2f positionSprite;
    sfVector2f offset;
    sfVector2f positionTree;
    sfVector2f positionOver;
    sfVector2f positionRestart;
    sfVector2f positionGround;
    sfVector2f positionRandom;
    sfVector2f positionBouton;
    sfVector2f positionText;
    sfVector2f positionLives;
    sfVector2f positionScope;
    sfVector2f scaleGround;
    sfVector2f scaleDuck;
    sfVector2u size;
    sfClock *clock;
    sfTime time;
    sfMusic *soundShot;
    sfMusic *sound;
    float seconds;
    int loop;
    int angle;
    int random;
    int scoreInt;
    int livesInt;
    char *scoreStr;
    char *livesStr;
};

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
void manage_mouse_click(struct sfHunter *);
void analyse_events(struct sfHunter *);
void move_rect(struct sfHunter *, int, int);
void destroy_sf(struct sfHunter *);
void check_loop(struct sfHunter *);
void create_sfvector(struct sfHunter *);
void create_sfvector_2(struct sfHunter *);
void create_sfsprite(struct sfHunter *);
int create_sftexture(struct sfHunter *);
void check_position(struct sfHunter *);
void create_sf(struct sfHunter *, sfVideoMode);
void create_sf_2(struct sfHunter *);
void opened_window(struct sfHunter *);
void turn_duck(struct sfHunter *);
int rand_a_b(int, int);
void help();
void display_over(struct sfHunter *);
void display_menu(struct sfHunter *);
void display_sf(struct sfHunter *);
int check_button_pressed(struct sfHunter *);
int menu(struct sfHunter *);
int game_over(struct sfHunter *);
int analyse_events_menu(struct sfHunter *sf);
int analyse_events_over(struct sfHunter *sf);

#endif //MY_H_
