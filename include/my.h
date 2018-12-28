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

enum State {
    DEAD = 3,
    END = 6,
    JUMP = 1,
    FALL = -1,
    REGULAR = 0,
    PAUSE = 2,
    ON_PLATFORM_REGULAR = 4,
    ON_PLATFORM_JUMP = 5,
    MENU = -2
};

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
    sfTexture *textureBoutonPlay;
    sfTexture *textureBoutonQuit;
    sfTexture *textureBoutonChangeSize;
    sfTexture *textureTitle;
    sfSprite *spritePlayer;
    sfSprite *spriteEnemy;
    sfSprite *spriteBackground;
    sfSprite *spriteSky;
    sfSprite *spriteGround;
    sfSprite *spritePlatform;
    sfSprite *spriteDead;
    sfSprite *spriteEnd;
    sfSprite *spritePortal;
    sfSprite *spriteBoutonPlay;
    sfSprite *spriteBoutonQuit;
    sfSprite *spriteBoutonChangeSize;
    sfSprite *spriteTitle;
    sfText *pause;
    sfText *score;
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
    sfVector2f positionGround;
    sfVector2f positionPlatform;
    sfVector2f positionPause;
    sfVector2f positionScope;
    sfVector2f positionDead;
    sfVector2f positionScore;
    sfVector2f positionPortal;
    sfVector2f positionPlay;
    sfVector2f positionQuit;
    sfVector2f positionChangeSize;
    sfVector2f positionTitle;
    sfVector2f scaleBackground;
    sfVector2f scaleGround;
    sfVector2f scaleSky;
    sfVector2f scalePlayer;
    sfVector2f scaleEnemy;
    sfVector2f scalePlatform;
    sfVector2f scaleDead;
    sfClock *clock;
    sfClock *clockSpawn;
    sfTime time;
    sfTime timeSpawn;
    sfView *view;
    float seconds;
    int secondSpawn;
    int distanceSpawn;
    int playerCondition;
    int angle;
    int scoreInt;
    int speedMoveBackground;
    int speedMoveGround;
    int speedMoveSky;
    int speedPlayer;
    int shift;
    int maxValueBackground;
    int maxValueGround;
    int maxValueSky;
    int existingSpike;
    int existingPlatform;
    int pauseTime;
    int endless;
    int nearPlatform;
    int in_pause;
    int in_game;
    int changeSize;
    float speedEnemy;
    char *scoreStr;
    char *map;
    char *map2;
};

void my_putchar(char);
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
char *get_next_line(int);
void init_rect(struct sfRunner *);
void init_position(struct sfRunner *);
void init_other(struct sfRunner *);
void create_sf(struct sfRunner *);
void create_texture_sprite(struct sfRunner *);
void create_other(struct sfRunner *);
void set_texture(struct sfRunner *);
void set_other(struct sfRunner *);
void draw_sf(struct sfRunner *);
void destroy_texture_sprite(struct sfRunner *);
void destroy_other(struct sfRunner *);
void move_rect(struct sfRunner *, int);
void move_rect_ground(struct sfRunner *);
void move_rect_background(struct sfRunner *);
void move_rect_sky(struct sfRunner *);
void manage_key_pressed(struct sfRunner *);
void analyse_events(struct sfRunner *);
void map(struct sfRunner *, int);
void map_2(struct sfRunner *, int);
void analyse_map(struct sfRunner *);
void check_player_condition(struct sfRunner *);
void check_position_player(struct sfRunner *);
void check_position_player_platform(struct sfRunner *);
void check_position_2(struct sfRunner *);
void main_loop(struct sfRunner *);
void manage_spike(struct sfRunner *);
void manage_platform(struct sfRunner *);
void manage_portal(struct sfRunner *);
int check_errors(struct sfRunner *);
int check_args(int, char **, struct sfRunner *);
void help(void);
void analyse_score(struct sfRunner *);
void analyse_pause(struct sfRunner *);
void analyse_after_pause(struct sfRunner *);
void modify_texture(struct sfRunner *);
void change_size_800(struct sfRunner *);
void increase_speed(struct sfRunner *);
void analyse_menu(struct sfRunner *);
void bouton_play(struct sfRunner *);
void bouton_quit(struct sfRunner *);
void bouton_change_size(struct sfRunner *);

#endif //MY_H_