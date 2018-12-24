/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_
#define DEAD 3
#define END 6
#define JUMP 1
#define FALL -1
#define REGULAR 0
#define PAUSE 2
#define ON_PLATFORM_REGULAR 4
#define ON_PLATFORM_JUMP 5

#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
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
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>

struct sfRunner {
    sfRenderWindow* window;
    sfVideoMode mode;
    sfTexture *texturePlayer;
    sfTexture *textureEnemy;
    sfTexture *textureBg;
    sfTexture *textureSky;
    sfTexture *textureGround;
    sfTexture *texturePlatform;
    sfTexture *textureDead;
    sfTexture *textureEnd;
    sfTexture *texturePortal;
    sfSprite *spritePlayer;
    sfSprite *spriteEnemy;
    sfSprite *spriteScope;
    sfSprite *spriteBackground;
    sfSprite *spriteSky;
    sfSprite *spriteGround;
    sfSprite *spritePlatform;
    sfSprite *spriteDead;
    sfSprite *spriteEnd;
    sfSprite *spritePortal;
    sfSprite *spriteBouton;
    sfSprite *spriteBoutonRestart;
    sfText *text;
    sfText *pause;
    sfText *lives;
    sfText *score;
    sfText *over;
    sfFont *font;
    sfEvent event;
    sfFloatRect rectangleView;
    sfFloatRect viewPort;
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
    sfVector2f positionPlatform;
    sfVector2f positionRandom;
    sfVector2f positionBouton;
    sfVector2f positionText;
    sfVector2f positionPause;
    sfVector2f positionLives;
    sfVector2f positionScope;
    sfVector2f positionDead;
    sfVector2f positionPortal;
    sfVector2f scaleBackground;
    sfVector2f scaleGround;
    sfVector2f scaleSky;
    sfVector2f scalePlayer;
    sfVector2f scaleEnemy;
    sfVector2f scalePlatform;
    sfVector2f scaleDead;
    sfVector2u size;
    sfClock *clock;
    sfClock *clockSpawn;
    sfTime time;
    sfTime timeSpawn;
    sfView *view;
    sfMusic *soundShot;
    sfMusic *sound;
    float seconds;
    int seconds2;
    int secondSpawn;
    int distanceSpawn;
    int loop;
    int playerCondition;
    int angle;
    int random;
    int scoreInt;
    int livesInt;
    int speedMoveBackground;
    int speedMoveGround;
    int speedMoveSky;
    int existingSpike;
    int existingPlatform;
    int pauseTime;
    int groundy;
    int endless;
    float speedEnemy;
    char *scoreStr;
    char *livesStr;
    char *map;
    char *map2;
};

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
void init_rect(struct sfRunner *);
void init_position(struct sfRunner *);
void init_other(struct sfRunner *);
void create_sf(struct sfRunner *);
void set_sf(struct sfRunner *);
void draw_sf(struct sfRunner *);
void destroy_sf(struct sfRunner *);
void move_rect(struct sfRunner *, int);
void move_rect_ground(struct sfRunner *, int);
void move_rect_background(struct sfRunner *, int);
void move_rect_sky(struct sfRunner *, int);
void manage_key_pressed(struct sfRunner *);
void analyse_events(struct sfRunner *);
void check_position(struct sfRunner *);
void check_position_player(struct sfRunner *);
void check_position_player_platform(struct sfRunner *);
void check_position_2(struct sfRunner *);
void main_loop(struct sfRunner *);
char *get_next_line(int);

#endif //MY_H_
