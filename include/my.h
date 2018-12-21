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

struct sfRunner {
    sfRenderWindow* window;
    sfTexture *texture;
    sfTexture *enemy;
    sfTexture *background;
    sfTexture *sky;
    sfTexture *ground;
    sfTexture *scope;
    sfTexture *bouton;
    sfTexture *boutonRestart;
    sfTexture *boutonQuit;
    sfSprite *sprite;
    sfSprite *spriteEnemy;
    sfSprite *spriteScope;
    sfSprite *spriteBackground;
    sfSprite *spriteSky;
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
    sfIntRect rectBackground;
    sfIntRect rectGround;
    sfIntRect rectSky;
    sfVector2f positionPlayer;
    sfVector2f positionEnemy;
    sfVector2f positionBackground;
    sfVector2f positionSky;
    sfVector2f mvmtPlayer;
    sfVector2f positionTree;
    sfVector2f positionOver;
    sfVector2f positionRestart;
    sfVector2f positionGround;
    sfVector2f positionRandom;
    sfVector2f positionBouton;
    sfVector2f positionText;
    sfVector2f positionLives;
    sfVector2f positionScope;
    sfVector2f scaleBackground;
    sfVector2f scaleGround;
    sfVector2f scaleSky;
    sfVector2f scalePlayer;
    sfVector2f scaleEnemy;
    sfVector2u size;
    sfClock *clock;
    sfTime time;
    sfMusic *soundShot;
    sfMusic *sound;
    float seconds;
    int seconds2;
    int loop;
    int jumpSide;
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
void manage_mouse_click(struct sfRunner *);
void analyse_events(struct sfRunner *);
void move_rect(struct sfRunner *, int, int);
void destroy_sf(struct sfRunner *);
void check_loop(struct sfRunner *);
void create_sfvector(struct sfRunner *);
void create_sfvector_2(struct sfRunner *);
void create_sfsprite(struct sfRunner *);
int create_sftexture(struct sfRunner *);
void check_position(struct sfRunner *);
void create_sf(struct sfRunner *, sfVideoMode);
void create_sf_2(struct sfRunner *);
void opened_window(struct sfRunner *);
void turn_duck(struct sfRunner *);
int rand_a_b(int, int);
void help();
void display_over(struct sfRunner *);
void display_menu(struct sfRunner *);
void display_sf(struct sfRunner *);
int check_button_pressed(struct sfRunner *);
int menu(struct sfRunner *);
int game_over(struct sfRunner *);
int analyse_events_menu(struct sfRunner *sf);
int analyse_events_over(struct sfRunner *sf);

#endif //MY_H_
