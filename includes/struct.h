/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-matthieu.roques
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdbool.h>

typedef enum type_t {PLAYER, STATIC_SPRITE, MOVING_SPRITE, GAME_BUTTONS,
    ENEMIES, MINIMAP, TEXT, PARTICLE, ITEM} type_t;

typedef enum door_t {RIGH, LEFT, DOW, UP, STAT} door_t;

typedef enum stats_t {ATTACK, SPEED, LIFE, LEVEL, POINT, XP} stats_t;

typedef struct lears_s
{
    sfVector2f pos;
    sfVector2f vec;
    sfTime an;
    sfTime mov;
    sfCircleShape *circle;
    struct lears_s *next;
}lears_t;

typedef struct minimap_s {
    sfRectangleShape **shapes;
} minimap_t;

typedef struct player_s {
    char *name;
    lears_t *larmes;
    door_t door;
    int life;
    float damage_multiplicator;
    float attack;
    float speed;
    int level;
    int xp;
    sfTime an_speed;
    sfTime mov_speed;
    sfTime an_fire;
    sfTime mov_fire;
} player_t;

struct core_s;

typedef struct game_button_s {
    bool can_click;
    bool clicked;
    void (*callback) (struct core_s *);
} game_button_t;

typedef struct text_s {
    sfText *text;
    char *str;
    int nb;
} text_t;

typedef struct init_enemy_s {
    char *filepath;
    sfIntRect rect;
    sfInt32 an_delay;
    sfInt32 mov_delay;
    int repetition;
    sfVector2f scale;
    int life;
    int damage;
    float speed;
} init_enemy_t;

typedef struct enemie_s {
    int life;
    int damage;
    float speed;
} enemie_t;

typedef struct particle_s {
    sfCircleShape *circle;
    sfColor color;
    float speed;
    sfInt32 time;
    float radius;
    int size;
} particle_t;

typedef struct item_s {
    int potion;
    int quantity;
} item_t;

typedef struct game_object_s {
    particle_t particle;
    enemie_t enemy;
    type_t type;
    item_t item;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    int repitions;
    sfVector2f pos;
    sfVector2f mov;
    sfVector2f anim;
    sfInt32 an_delay;
    sfInt32 mov_delay;
    sfTime an_time;
    sfTime mov_time;
    game_button_t game_buttons;
    text_t *text;
    minimap_t minimap;
    void (*update) (struct core_s *, struct game_object_s *);
    struct game_object_s *next;
} game_object_t;

typedef struct scene_s {
    char *name;
    char *child;
    sfMusic *music;
    player_t player;
    game_object_t *objs;
} scene_t;

typedef struct status_s {
    bool click;
    bool music;
    bool sfx;
    float volume;
    bool inviciblity;
} status_t;

typedef struct sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct map_s {
    char **room;
    game_object_t *obj;
    bool current;
    bool last;
    int type;
    bool east;
    bool west;
    bool north;
    bool south;
}map_t;

typedef struct hitbox_s
{
    sfRectangleShape *mapl;
    sfRectangleShape ***mapr;
    bool **mapb;
    sfRectangleShape *hitbox;
}hitbox_t;

typedef struct translation_s {
    bool stop;
    sfInt64 last_time;
    int repitions;
    sfInt64 delay;
    sfVector2f movement;
} translation_t;

typedef struct core_s {
    int number_enemys;
    init_enemy_t *enemys;
    sfClock *clock;
    sfFont *font;
    hitbox_t hitbox;
    sfRenderWindow *window;
    char *id_scene;
    scene_t *scene;
    struct map_s **map;
    bool clic_stat;
    status_t status;
    int stats[6];
    int items[3];
    sound_t *buttonsfx;
    sound_t *deathsfx;
    translation_t translation;
    sfTime last_time;
} core_t;

#endif /* !STRUCT_H_ */
