/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** create_minimap
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"
#include "linked_list.h"
#include "update.h"

static void add_current_square(core_t *core, game_object_t *obj, size_t count)
{
    obj->minimap.shapes[count] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(obj->minimap.shapes[count], sfWhite);
    sfRectangleShape_setSize(obj->minimap.shapes[count],
    (sfVector2f){20, 20});
    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x)
            if (core->map[y][x].current)
                sfRectangleShape_setPosition(obj->minimap.shapes[count],
                (sfVector2f){5 + 10 + 30 * x + x * 10, 5 + 30 * y + y * 10});
}

static void create_shape(game_object_t *obj, size_t *count, sfVector2f size,
sfVector2f pos)
{
    obj->minimap.shapes[*count] = sfRectangleShape_create();
    sfRectangleShape_setOrigin(obj->minimap.shapes[*count],
    (sfVector2f){5, 15});
    sfRectangleShape_setFillColor(obj->minimap.shapes[*count],
    sfColor_fromRGB(112, 112, 112));
    sfRectangleShape_setSize(obj->minimap.shapes[*count], size);
    sfRectangleShape_setPosition(obj->minimap.shapes[*count], pos);
    count[0]++;
}

static void create_shape_2(game_object_t *obj, size_t *count, sfVector2f size,
sfVector2f pos)
{
    obj->minimap.shapes[*count] = sfRectangleShape_create();
    sfRectangleShape_setOrigin(obj->minimap.shapes[*count],
    (sfVector2f){5, 15});
    sfRectangleShape_setFillColor(obj->minimap.shapes[*count],
    sfColor_fromRGB(112, 112, 112));
    sfRectangleShape_setSize(obj->minimap.shapes[*count], size);
    sfRectangleShape_setPosition(obj->minimap.shapes[*count], pos);
    sfRectangleShape_setRotation(obj->minimap.shapes[*count], 90);
    count[0]++;
}

static void init_struct_minimap(game_object_t *obj, size_t count)
{
    obj->minimap.shapes[count + 1] = NULL;
    obj->type = MINIMAP;
    obj->next = NULL;
    obj->update = update_minimap;
}

void create_minimap(core_t *core, char *s)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    size_t count = 0;
    int i = 0;
    obj->minimap.shapes = malloc(sizeof(sfRectangleShape *) * (100));

    for (int y = 0; core->map[y]; ++y)
        for (int x = 0; core->map[y][x].type != -210; ++x) {
            if (core->map[y][x].type != -1)
                create_shape(obj, &count, (sfVector2f){30, 30},
                (sfVector2f){10 + 5 + 30 * x + x * 10, 25 + 30 * y + y * 10});
            if (core->map[y][x].type != -1 && core->map[y][x].south)
                create_shape(obj, &count, (sfVector2f){10, 30},
                (sfVector2f){25 + 30 * x + x * 10, 40 + 30 * y + y * 10});
            if (core->map[y][x].type != -1 && core->map[y][x].east)
                create_shape_2(obj, &count, (sfVector2f){10, 30},
                (sfVector2f){40 + 30 * x + x * 10, 25 + 30 * y + y * 10});
        }
    add_current_square(core, obj, count);
    init_struct_minimap(obj, count);
    for (; core->scene[i].name && my_strcmp(core->scene[i].name, s) != 0; ++i);
    put_at_end_list(&core->scene[i].objs, obj);
}