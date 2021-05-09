/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-malek.gatoufi
** File description:
** coliding_system
*/

#include <stdbool.h>
#include <stdarg.h>
#include <math.h>
#include "coliding_system.h"
#include "csfml.h"

static bool r_r_intersection(va_list ap)
{
    sfRectangleShape *shape1 = va_arg(ap, sfRectangleShape *);
    sfRectangleShape *shape2 = va_arg(ap, sfRectangleShape *);
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(shape1);
    sfFloatRect rect2 = sfRectangleShape_getGlobalBounds(shape2);

    return (sfFloatRect_intersects(&rect1, &rect2, NULL));
}

static bool c_r_intersection(va_list ap)
{
    sfRectangleShape *shape1 = va_arg(ap, sfRectangleShape *);
    sfCircleShape *shape2 = va_arg(ap, sfCircleShape *);
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(shape1);
    sfVector2f circle = sfCircleShape_getPosition(shape2);
    float radius = sfCircleShape_getRadius(shape2);

    circle.x += radius;
    circle.y += radius;
    rect.left += rect.width / 2;
    rect.top += rect.height / 2;
    if (fabs(circle.x - rect.left) > ((rect.width / 2 + radius)))
        return false;
    if (fabs(circle.y - rect.top) > ((rect.height / 2 + radius)))
        return false;
    if (fabs(circle.x - radius - rect.left) <= ((rect.width / 2)))
        return true;
    if (fabs(circle.y - radius - rect.top) <= ((rect.height / 2)))
        return true;
    return (pow((fabs(circle.x - rect.left) - rect.width / 2), 2)
        + pow((fabs(circle.y - rect.top) - rect.height / 2), 2)
        <= (pow(radius, 2)));
}

static bool c_c_intersection(va_list ap)
{
    sfCircleShape *shape1 = va_arg(ap, sfCircleShape *);
    sfCircleShape *shape2 = va_arg(ap, sfCircleShape *);
    sfVector2f circle1 = sfCircleShape_getPosition(shape1);
    sfVector2f circle2 = sfCircleShape_getPosition(shape2);
    float radius1 = sfCircleShape_getRadius(shape1);
    float radius2 = sfCircleShape_getRadius(shape2);
    float dx = circle1.x - circle2.x;
    float dy = circle1.y - circle2.y;
    float dist = sqrt(pow(dx, 2) + pow(dy, 2));

    if (dist < radius1 + radius2)
        return (true);
    return (false);
}

bool coliding_system(inter_t intersection, ...)
{
    va_list ap;
    bool result = true;

    va_start(ap, intersection);
    if (intersection == R_R)
        result = r_r_intersection(ap);
    if (intersection == C_R)
        result = c_r_intersection(ap);
    if (intersection == C_C)
        result = c_c_intersection(ap);
    va_end(ap);
    return (result);
}